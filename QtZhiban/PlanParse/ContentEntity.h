#pragma once
#include <QObject>

struct ContentSection
{
	QString content;
	QString styleName;
	int fontSize;
	QString fontFamily;
	QString textAlignment;
	int breakLine;
	int state;
};



struct HeaderStyle {
	QString styleName;
	int fontSize;
	QString fontFamily;
	QString textAlignment;
	int state;
};

struct TemplateName {
	QString name;
	int state;
};

struct WordTemplateName {
	QString name;
	int state;
};

enum ContentType
{
	Text,
	Image,
	Table
};
Q_DECLARE_METATYPE(ContentType)

struct ContentTable
{
	QList<QList<QString>> tableData;  // 用于存储表格的内容
	int rowNum;
	int colNum;
};
Q_DECLARE_METATYPE(ContentTable)

struct HeaderContent {
	ContentType type;
	QString text;               // 用于存储文本的内容
	QString imagePath;          // 用于存储图片路径
	QString imageContent;       // 用于存储图片的内容
	ContentTable table;         // 用于存储表格的内容
};
Q_DECLARE_METATYPE(HeaderContent)

struct PlanTemplateItem {
	QString title;
	QString styleName;
	QList<HeaderContent> headerContents;
	int state;
	QList<PlanTemplateItem> subTemplateItemCollection;
};
Q_DECLARE_METATYPE(PlanTemplateItem)
