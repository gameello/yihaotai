#include "IdGenerateHelper.h"

#include <QMutexLocker>
#include <QThread>

IdGenerateHelper* IdGenerateHelper::helper = nullptr;
IdGenerateHelper::IdGenerateHelper()
{
	QDateTime datetime = QDateTime::currentDateTime();
	datetime.setTime(QTime(0, 0, 0, 0));
	baseNum = datetime.toMSecsSinceEpoch();

	m_LastDateTime = QDateTime::currentDateTime();
	m_LastDateTime2 = QDateTime::currentDateTime();
}

IdGenerateHelper::~IdGenerateHelper()
{
	
}

qint64 IdGenerateHelper::generate()
{
	QMutexLocker locker(&mutex);
	QDateTime current_date_time = QDateTime::currentDateTime();
	if (current_date_time == m_LastDateTime)
	{
		QThread::msleep(1);
		current_date_time = current_date_time.addMSecs(1);
	}
	id = current_date_time.toMSecsSinceEpoch() - baseNum;
	m_LastDateTime = current_date_time;
	return id;
}

IdGenerateHelper* IdGenerateHelper::instance()
{
	if (!helper)
	{
		helper = new IdGenerateHelper();
	}
	return helper;
}

