#pragma once

#include <QSql>
#include <QSqlDatabase>
#include <QQueue>
#include <QString>
#include <QMutex>
#include <QMutexLocker>
#include <QWaitCondition>
#include <QSettings>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDriver>
#include <QStringList>
#include <QVector>
#include <QVariant>
#include <QSqlRecord>

// #include "../global.h"

class ConnectionPool
{
public:
	~ConnectionPool();

	// 关闭所有数据库连接
	static void release();

	// 获取数据库连接
	static QSqlDatabase openConnection();

	// 释放数据库连接回连接池
	static void closeConnection(QSqlDatabase connection);

	//数据库查询函数
	bool DataQuery(QString table, QVector<QString> columns,
		QVector<QStringList>& outcome, QString &info, QString cond = "");


private:
	ConnectionPool();

	static ConnectionPool& getInstance();

	// 创建数据库连接
	QSqlDatabase createConnection(const QString &connectionName);

	QQueue<QString> usedConnectionNames;	// 已使用的数据库连接名
	QQueue<QString> unusedConnectionNames;	// 未使用的数据库连接名

	// 数据库信息
	QString hostName;
	int port;
	QString databaseName;
	QString username;
	QString password;
	QString databaseType;

	bool testOnBorrow;		// 获取连接时验证连接是否有效
	QString testOnBorrowSql;	// 获取连接时验证连接是否有效所使用的SQL语句

	int maxWaitTime;		// 最大等待时间
	int waitInterval;		// 尝试获取连接时等待间隔时间
	int maxConnectionCount;	// 最大连接数

	static QMutex mutex;
	static QWaitCondition waitCondition;
	static ConnectionPool *instance;

};

