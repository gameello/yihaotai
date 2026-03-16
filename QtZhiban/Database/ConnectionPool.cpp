#include "ConnectionPool.h"

#include <QApplication>
// #include "../global.h"

QMutex ConnectionPool::mutex;
QWaitCondition ConnectionPool::waitCondition;
ConnectionPool * ConnectionPool::instance = nullptr;

ConnectionPool::ConnectionPool()
{
	QSettings settings(QApplication::applicationDirPath() + "/config/config.ini", QSettings::IniFormat);
	// settings.setValue("Database/Key2", "valuess");

	hostName = settings.value("Database/hostname","127.0.0.1").toString();
	port = settings.value("Database/port", "5432").toInt();
	databaseName = settings.value("Database/databaseName", "huawulian").toString();
	username = settings.value("Database/username", "postgres").toString();
	password = settings.value("Database/password", "2020").toString();
	databaseType = settings.value("Database/databaseType", "QPSQL").toString();

	testOnBorrow = true;
	testOnBorrowSql = "SELECT 1";

	maxWaitTime = 1000;
	waitInterval = 200;
	maxConnectionCount = 1000;
}

QSqlDatabase ConnectionPool::createConnection(const QString &connectionName)
{
	if (QSqlDatabase::contains(connectionName))
	{
		QSqlDatabase connection = QSqlDatabase::database(connectionName);

		if (testOnBorrow)
		{
			QSqlQuery query(testOnBorrowSql);

			if (query.lastError().type() != QSqlError::NoError && !connection.open())
			{
				return QSqlDatabase();
			}
		}

		return connection;
	}

	// 创建一个新的连接
	QSqlDatabase connection = QSqlDatabase::addDatabase(databaseType, connectionName);
	connection.setHostName(hostName);
	connection.setPort(port);
	connection.setDatabaseName(databaseName);
	connection.setUserName(username);
	connection.setPassword(password);
	// connection.setPort();

	if (!connection.open())
	{
		QSqlError error = connection.lastError();
		QString d = error.databaseText();
		return QSqlDatabase();
	}

	return connection;
}

ConnectionPool::~ConnectionPool()
{
	// 删除在用连接
	for(QString connectionName : usedConnectionNames)
	{
		QSqlDatabase::removeDatabase(connectionName);
	}

	// 删除空闲连接
	for (QString connectionName : unusedConnectionNames)
	{
		QSqlDatabase::removeDatabase(connectionName);
	}
}

void ConnectionPool::release()
{
	QMutexLocker locker(&mutex);
	delete instance;
	instance = nullptr;
}

QSqlDatabase ConnectionPool::openConnection()
{
	ConnectionPool& pool = ConnectionPool::getInstance();
	QString connectionName;

	QMutexLocker locker(&mutex);

	// 已创建的连接数
	int connectionCount = pool.unusedConnectionNames.size() + pool.usedConnectionNames.size();

	// 如果连接已用完，等待 waitInterval 毫秒后重试，最长等待 maxWaitTime 毫秒
	for (int i = 0; i < pool.maxWaitTime && pool.unusedConnectionNames.size() == 0 && connectionCount == pool.maxConnectionCount; i += pool.waitInterval)
	{
		waitCondition.wait(&mutex, pool.waitInterval);
	}

	if (pool.unusedConnectionNames.size() > 0)
	{
		// 有已回收的连接则复用
		connectionName = pool.unusedConnectionNames.dequeue();
	}
	else if(connectionCount < pool.maxConnectionCount)
	{
		// 没有已回收的连接，但未达到最大连接数，则创建新的连接
		connectionName = QString("Connection-%1").arg(connectionCount + 1);
	}
	else
	{
		return QSqlDatabase();
	}

	// 创建数据库
	QSqlDatabase connection = pool.createConnection(connectionName);

	// 有效的连接才放入 usedConnectionNames 队列
	if (connection.isOpen())
	{
		pool.usedConnectionNames.enqueue(connectionName);
	}

	return connection;
}

ConnectionPool & ConnectionPool::getInstance()
{
	if (instance == nullptr)
	{
		QMutexLocker locker(&mutex);
		instance = new ConnectionPool();
	}

	return *instance;
}

void ConnectionPool::closeConnection(QSqlDatabase connection)
{
	ConnectionPool& pool = ConnectionPool::getInstance();
	QString connectionName = connection.connectionName();

	// 如果是我们创建的连接，从 used 里删除，放入 unused 里
	if (pool.usedConnectionNames.contains(connectionName))
	{
		QMutexLocker locker(&mutex);
		pool.usedConnectionNames.removeOne(connectionName);
		pool.unusedConnectionNames.enqueue(connectionName);
		waitCondition.wakeOne();
	}
}