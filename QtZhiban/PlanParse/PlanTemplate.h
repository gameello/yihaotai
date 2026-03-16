#pragma once

#include <QObject>
#include "ContentEntity.h"

struct PlanFileInfo
{
	QString name;
	QString author;
	bool allow;
	QString xml;
};
Q_DECLARE_METATYPE(PlanFileInfo)

class  PlanTemplate : public QObject
{
	Q_OBJECT

public:
	PlanTemplate(QObject *parent = Q_NULLPTR);
	~PlanTemplate();

	TemplateName templateName;
	WordTemplateName wordTemplateName;
	QList<ContentSection> titleHeaderCollection;		//空军雷达兵第XX旅作战计划
	QList<PlanTemplateItem> templateItemCollection;		//正文
	QList<ContentSection> fileEndCollection;			//结尾中国电子科技集团第十五研究所
	QList<HeaderStyle> headerStyleCollection;			//标题字号
};
