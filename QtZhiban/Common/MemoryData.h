#pragma once
#include <QMap>
#include <QList>
#include <QString>
#include <QVector>
#include <QDateTime>
#include <QObject>
#include "PlanParse/PlanTemplate.h"

struct xiweistruct
{
	int id;
	QString name = "";
	QString password = "";
	int level = 0;
};

struct renyuanstruct
{
	int id;
	QString name = "";
	QString zhiwu = "";
	int xiwei = 0;
};

struct sqlConfig
{
	int id;
	QString type = "";
	QString info = "";
	int level = 0;
};

struct todoStruct
{
	qint64 idGenerate;
	int xiwei;
	QDate date;
	QString title;
	int percent;
	QString miaoshu;
};

class MemoryData
{
public:
	MemoryData();
	~MemoryData();

	// 当前日期
	QDate currDate;

	// 当前席位id
	int curSeatName;

	// 席位名称
	QStringList SeatNamelist;
	QList<xiweistruct> XiweiList;
	QMap<int, xiweistruct> XiweiMap;

	// 数据库配置表，包含tab页名称
	QMap<int, sqlConfig> sql_configs;

	// 人员信息
	QStringList Renyuanlist;
	QStringList Zhiwulist;
	QMap<int, QList<renyuanstruct>> Renyuanstructs;
	QMap<int, QList<QString>> renyuanmap;
	QMap<int, QList<QString>> zhiwumap;
	QHash<QString, QString> Renyuanzhiwu;

	//存放模板文件的内容和标题
	QMap<QString, QString> templateFiles;
	// 计划方案文件信息
	PlanFileInfo planFileInfo;
	// 记录组内其他成员正在编辑的章节目录
	QList<QString> chapters;
	// 记录其他席位已编辑完成的章节内容,每次更新之后清空
	QMap<QString, QString> chapterContents;
};
