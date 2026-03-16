#pragma once

#include <QtGlobal>
#include <QMutex>
#include <QDateTime>

class  IdGenerateHelper
{
public:
	~IdGenerateHelper();
	
	static IdGenerateHelper * instance();

	qint64 generate();

private:
	IdGenerateHelper();

	static IdGenerateHelper *helper;

	QMutex mutex;
	qint64  baseNum=0;
	QDateTime m_LastDateTime;

	QMutex mutex2;
	qint64 baseNum2 = (QDateTime::fromString("2021-01-01 00:00:00.000", \
		"yyyy-MM-dd hh:mm:ss.zzz")).toMSecsSinceEpoch();
	QDateTime m_LastDateTime2;

	qint64 id = 0;

};

