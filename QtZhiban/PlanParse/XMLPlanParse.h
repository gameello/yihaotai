#pragma once

#include <QObject>
#include <QXmlStreamReader>
#include <QTextEdit>
#include "ContentEntity.h"

class PlanTemplate;
class  XMLPlanParse : public QObject
{
	Q_OBJECT

public:
	XMLPlanParse(QObject *parent = Q_NULLPTR);
	~XMLPlanParse();

	void parseContentSection(QXmlStreamReader& xmlReader, ContentSection& section, int state);
	void parseHeaderStyle(QXmlStreamReader& xmlReader, HeaderStyle& style);
	QList<ContentSection> parseTitleHeaderCollection(QXmlStreamReader& xmlReader, int state);
	QList<PlanTemplateItem> parseTemplateItemCollection(QXmlStreamReader& xmlReader, int state);
	void parsePlanTemplateItem(QXmlStreamReader& xmlReader, PlanTemplateItem& item, int state);

	QList<ContentSection> parseFileEndCollection(QXmlStreamReader& xmlReader, int state);
	QList<HeaderStyle> parseHeaderStyleCollection(QXmlStreamReader& xmlReader);
	PlanTemplate* parsePlanTemplate(QXmlStreamReader& xmlReader);
	QList<PlanTemplateItem> parseSectionFile(QXmlStreamReader& xmlReader);

private:
	PlanTemplate *m_PlanTemplate;


};
