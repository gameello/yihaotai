#ifndef GLOBAL_H
#define GLOBAL_H

#include <string>
#include <QString>
#include <QDateTime>
#include <QVariant>

#include "IdGenerateHelper.h"
#include "SettingService.h"
#include "tip/MessageTipService.h"
#include "Common/MemoryDataService.h"
#include "Log/QtCLog.h"

#define MAKE_CHAR(s) (s).toLocal8Bit().data()
#define MAKE_UTF8_CHAR(s) (s).toUtf8().data()

extern  SettingService *settingService;
extern	IdGenerateHelper* idHelper;
extern  MessageTipService *messageTipService;
extern  MemoryDataService *memoryDataService;

// 数据类型转换
int variant2int(QVariant v);
qint64 variant2longlong(QVariant v);
double variant2double(QVariant v);
QString variant2string(QVariant v);
QDateTime variant2datetime(QVariant v);

// 角度/弧度转换
double angle2radian(double angle);
double radian2angle(double angle);

QString convertRGBA16Hex(QColor color);

#define UINT_32 unsigned int
#define UINT_16 unsigned short

// 软件席位
#define ZCQKBH QString::fromLocal8Bit("战场情况标绘席")
#define JHFANZ QString::fromLocal8Bit("计划方案拟制席")
#define FATYPG QString::fromLocal8Bit("方案推演评估席")

#define TSRGBA(r,g,b,a) ((UINT_32)((((UINT_16)a)<<24) | (((UINT_16)b)<<16) | (((UINT_16)g)<<8) | ((UINT_16)r)))
#define TSRGBA2QCOLOR(rgba)\
	(QColor((rgba) & 0xFF, (rgba >> 8) & 0xFF, (rgba>>16) & 0xFF, (rgba>>24) & 0xFF))

#endif // GLOBAL_H
