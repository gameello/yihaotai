#include "global.h"
#include <QtMath>
#include <QColor>


SettingService *settingService = nullptr;
IdGenerateHelper *idHelper = nullptr;
MessageTipService *messageTipService = nullptr;
MemoryDataService *memoryDataService = nullptr;

int variant2int(QVariant v)
{
	return (v.isValid()) ? v.toInt() : 0;
}

qint64 variant2longlong(QVariant v)
{
	return (v.isValid()) ? v.toLongLong() : 0;
}

double variant2double(QVariant v)
{
	return (v.isValid()) ? v.toDouble() : 0;
}

QString variant2string(QVariant v)
{
	QString str;
	QVariant::Type type = v.type();
	switch (type)
	{
	case QVariant::Bool:
		str = (v.toBool()) ? "True" : "False";
		break;
	case QVariant::Int:
		str = QString::number(v.toInt());
		break;
	case QVariant::LongLong:
		str = QString::number(v.toLongLong());
		break;
	case QVariant::Double:
		str = QString::number(v.toDouble(), 'f', 4);
		break;
	case QVariant::String:
		str = v.toString();
		break;
	case QVariant::StringList:
		str = v.toStringList().join(";");
		break;
	case QVariant::UInt:
		str = QString::number(v.toUInt());
		break;
	case QVariant::DateTime:
		str = v.toDateTime().toString("yyyy-MM-dd HH:mm:ss");
	}
	return str;
}

QDateTime variant2datetime(QVariant v)
{
	return v.toDateTime();
}

double angle2radian(double angle)
{
	return angle * M_PI / 180;
}

double radian2angle(double angle)
{
	return angle * 180 / M_PI;
}

QString convertRGBA16Hex(QColor color)
{
	QString redStr = QString("%1").arg(color.red(), 2, 16, QChar('0'));
	QString greenStr = QString("%1").arg(color.green(), 2, 16, QChar('0'));
	QString blueStr = QString("%1").arg(color.blue(), 2, 16, QChar('0'));
	QString alphaStr = QString("%1").arg(color.alpha(), 2, 16, QChar('0'));

	QString colStr = "#" + redStr + greenStr + blueStr + alphaStr;
	return colStr;
}
