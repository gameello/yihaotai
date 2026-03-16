#include "PlanParse/XMLPlanParse.h"
#include "PlanParse/PlanTemplate.h"
#include <QDebug>

XMLPlanParse::XMLPlanParse(QObject *parent)
	: QObject(parent), m_PlanTemplate(nullptr)
{
}

XMLPlanParse::~XMLPlanParse()
{
}

void XMLPlanParse::parseContentSection(QXmlStreamReader & xmlReader, ContentSection & section, int state)
{
	while (!xmlReader.atEnd()) {
		xmlReader.readNext();
		if (xmlReader.isStartElement()) {
			if (xmlReader.name() == "Content") {
				xmlReader.readNext();
				section.content = xmlReader.text().toString();
				section.state = state;
			}
			else if (xmlReader.name() == "StyleName") {
				xmlReader.readNext();
				section.styleName = xmlReader.text().toString();
			}
			else if (xmlReader.name() == "FontSize") {
				xmlReader.readNext();
				section.fontSize = xmlReader.text().toInt();
			}
			else if (xmlReader.name() == "FontFamily") {
				xmlReader.readNext();
				section.fontFamily = xmlReader.text().toString();
			}
			else if (xmlReader.name() == "TextAlignment") {
				xmlReader.readNext();
				section.textAlignment = xmlReader.text().toString();
			}
			else if (xmlReader.name() == "BreakLine") {
				xmlReader.readNext();
				section.breakLine = xmlReader.text().toInt();
			}
		}
		else if (xmlReader.isEndElement() && xmlReader.name() == "ContentSection") {
			qDebug() << "Reached end of ContentSection";
			break;
		}
	}
}

void XMLPlanParse::parseHeaderStyle(QXmlStreamReader& xmlReader, HeaderStyle& style)
{
	while (!xmlReader.atEnd()) {
		xmlReader.readNext();
		if (xmlReader.isStartElement()) {
			if (xmlReader.name() == "StyleName") {
				xmlReader.readNext();
				style.styleName = xmlReader.text().toString();
			}
			else if (xmlReader.name() == "FontSize") {
				xmlReader.readNext();
				style.fontSize = xmlReader.text().toInt();
			}
			else if (xmlReader.name() == "FontFamily") {
				xmlReader.readNext();
				style.fontFamily = xmlReader.text().toString();
			}
		}
		else if (xmlReader.isEndElement() && xmlReader.name() == "HeaderStyle") {
			qDebug() << "Reached end of HeaderStyle";
			break;
		}
	}
}

QList<ContentSection> XMLPlanParse::parseTitleHeaderCollection(QXmlStreamReader& xmlReader, int state)
{
	QList<ContentSection> sections;
	// 在这里解析 <TitleHeaderCollection> 的内容，类似之前的示例代码
	// 将解析结果保存到 sections 中
	while (!xmlReader.atEnd()) {
		xmlReader.readNext();
		if (xmlReader.isStartElement()) {
			if (xmlReader.name() == "ContentSection") {
				ContentSection section;
				parseContentSection(xmlReader, section, state);
				sections.append(section);
			}
		}
		else if (xmlReader.isEndElement() && xmlReader.name() == "TitleHeaderCollection") {
			qDebug() << "Reached end of TitleHeaderCollection";
			break;
		}
	}
	return sections;
}

QList<PlanTemplateItem> XMLPlanParse::parseTemplateItemCollection(QXmlStreamReader& xmlReader, int state) 
{
	QList<PlanTemplateItem> templateItems;
	while (!xmlReader.atEnd()) {
		xmlReader.readNext();
		if (xmlReader.isStartElement()) {
			if (xmlReader.name() == "PlanTemplateItem") {
				PlanTemplateItem item;
				parsePlanTemplateItem(xmlReader, item, state);
				templateItems.append(item);
			}
		}
		else if (xmlReader.isEndElement() && xmlReader.name() == "TemplateItemCollection") {
			qDebug() << "Reached end of TemplateItemCollection";
			break;
		}
		else if (xmlReader.isEndElement() && xmlReader.name() == "SubTemplateItemCollection") {
			qDebug() << "Reached end of SubTemplateItemCollection";
			break;
		}
	}
	return templateItems;
}

void XMLPlanParse::parsePlanTemplateItem(QXmlStreamReader& xmlReader, PlanTemplateItem& item, int state)
{
	while (!xmlReader.atEnd()) {
		xmlReader.readNext();
		if (xmlReader.isStartElement()) {
			if (xmlReader.name() == "Title") {
				item.title = xmlReader.readElementText();
				item.state = state;
			}
			else if (xmlReader.name() == "StyleName") {
				item.styleName = xmlReader.readElementText();
			}
			else if (xmlReader.name() == "HeaderContent") {
				
				while (!(xmlReader.isEndElement() && xmlReader.name() == "HeaderContent"))
				{
					xmlReader.readNext();
					HeaderContent content;
					if (xmlReader.isStartElement() && xmlReader.name() == "Text")
					{
						QString _text = xmlReader.readElementText().replace("\n", "@");
						_text = _text.trimmed().simplified();
						content.type = ContentType::Text;
						content.text = _text.replace("@", "\n");
						item.headerContents.append(content);
					}
					else if (xmlReader.isStartElement() && xmlReader.name() == "Image")
					{
						content.type = ContentType::Image;
						content.imageContent = xmlReader.attributes().value("data").toString();
						content.imagePath = xmlReader.readElementText();						
						item.headerContents.append(content);
					}
					else if (xmlReader.isStartElement() && xmlReader.name() == "Table")
					{
						content.type = ContentType::Table;
						content.table.rowNum = xmlReader.attributes().value("rows").toInt();
						content.table.colNum = xmlReader.attributes().value("cols").toInt();
						QList<QString> cells;
						while (!(xmlReader.isEndElement() && xmlReader.name() == "Table"))
						{							
							xmlReader.readNext();
							if (xmlReader.isStartElement() && xmlReader.name() == "Row")
							{
								cells.clear();
								while (!(xmlReader.isEndElement() && xmlReader.name() == "Row"))
								{
									xmlReader.readNext();
									if (xmlReader.isStartElement() && xmlReader.name() == "Cell")
									{
										QString cell = xmlReader.readElementText();
										cells.append(cell);
									}
								}
								content.table.tableData.append(cells);
							}							
						}
						item.headerContents.append(content);
					}										
				}							
			}
			else if (xmlReader.name() == "SubTemplateItemCollection") {
				// 递归解析子项
				item.subTemplateItemCollection = parseTemplateItemCollection(xmlReader, state);
			}
		}
		else if (xmlReader.isEndElement() && xmlReader.name() == "PlanTemplateItem") {
			qDebug() << "Reached end of PlanTemplateItem";
			break;
		}
	}
}

QList<ContentSection> XMLPlanParse::parseFileEndCollection(QXmlStreamReader& xmlReader, int state)
{
	QList<ContentSection> sections;
	// 在这里解析 <FileEndCollection> 的内容，类似之前的示例代码
	// 将解析结果保存到 sections 中
	while (!xmlReader.atEnd()) {
		xmlReader.readNext();
		if (xmlReader.isStartElement()) {
			if (xmlReader.name() == "ContentSection") {
				ContentSection section;
				parseContentSection(xmlReader, section, state);
				sections.append(section);
			}
		}
		else if (xmlReader.isEndElement() && xmlReader.name() == "FileEndCollection") {
			qDebug() << "Reached end of FileEndCollection";
			break;
		}
	}
	return sections;
}

QList<HeaderStyle> XMLPlanParse::parseHeaderStyleCollection(QXmlStreamReader& xmlReader)
{
	QList<HeaderStyle> styles;
	// 在这里解析 <HeaderStyleCollection> 的内容，类似之前的示例代码
	// 将解析结果保存到 styles 中
	while (!xmlReader.atEnd()) {
		xmlReader.readNext();
		if (xmlReader.isStartElement()) {
			if (xmlReader.name() == "HeaderStyle") {
				HeaderStyle style;
				parseHeaderStyle(xmlReader, style);
				styles.append(style);
			}
		}
		else if (xmlReader.isEndElement() && xmlReader.name() == "HeaderStyleCollection") {
			qDebug() << "Reached end of HeaderStyleCollection";
			break;
		}
	}
	return styles;
}

PlanTemplate * XMLPlanParse::parsePlanTemplate(QXmlStreamReader& xmlReader)
{
	m_PlanTemplate = new PlanTemplate();
	QList<ContentSection> titleHeaderCollection;
	QList<PlanTemplateItem> templateItemCollection;
	QList<ContentSection> fileEndCollection;
	QList<HeaderStyle> headerStyleCollection;

	while (!xmlReader.atEnd()) {
		xmlReader.readNext();
		if (xmlReader.isStartElement()) {
			QStringRef name = xmlReader.name();
			if (xmlReader.name() == "Template_Name")
			{
				if (xmlReader.attributes().hasAttribute("state")) {
					// 获取名为 "state" 的属性的值
					int a = xmlReader.attributes().value("state").toInt();
					m_PlanTemplate->templateName.state = xmlReader.attributes().value("state").toInt();
				}
				xmlReader.readNext();
				m_PlanTemplate->templateName.name = xmlReader.text().toString();
			}
			else if (xmlReader.name() == "WordTemplate_Name")
			{
				if (xmlReader.attributes().hasAttribute("state")) {
					// 获取名为 "state" 的属性的值
					m_PlanTemplate->wordTemplateName.state = xmlReader.attributes().value("state").toInt();
				}
				xmlReader.readNext();
				m_PlanTemplate->wordTemplateName.name = xmlReader.text().toString();
			}
			else if (xmlReader.name() == "TitleHeaderCollection") {
				int state;
				if (xmlReader.attributes().hasAttribute("state")) {
					// 获取名为 "state" 的属性的值
					state = xmlReader.attributes().value("state").toInt();
				}
				titleHeaderCollection = parseTitleHeaderCollection(xmlReader, state);
			}
			else if (xmlReader.name() == "TemplateItemCollection") {
				int state;
				if (xmlReader.attributes().hasAttribute("state")) {
					// 获取名为 "state" 的属性的值
					state = xmlReader.attributes().value("state").toInt();
				}
				templateItemCollection = parseTemplateItemCollection(xmlReader, state);
			}
			else if (xmlReader.name() == "FileEndCollection") {
				int state;
				if (xmlReader.attributes().hasAttribute("state")) {
					// 获取名为 "state" 的属性的值
					state = xmlReader.attributes().value("state").toInt();
				}
				fileEndCollection = parseFileEndCollection(xmlReader, state);
			}
			else if (xmlReader.name() == "HeaderStyleCollection") {
				headerStyleCollection = parseHeaderStyleCollection(xmlReader);
			}
		}
		else if (xmlReader.isEndElement() && xmlReader.name() == "ArrayOfPlanTemplate") {
			qDebug() << "Reached end of ArrayOfPlanTemplate";
			break;
		}
	}
	m_PlanTemplate->titleHeaderCollection = titleHeaderCollection;
	m_PlanTemplate->templateItemCollection = templateItemCollection;
	m_PlanTemplate->fileEndCollection = fileEndCollection;
	m_PlanTemplate->headerStyleCollection = headerStyleCollection;
	return m_PlanTemplate;
}

QList<PlanTemplateItem> XMLPlanParse::parseSectionFile(QXmlStreamReader& xmlReader)
{
	QList<PlanTemplateItem> templateItemCollection;
	while (!xmlReader.atEnd()) {
		xmlReader.readNext();
		if (xmlReader.name() == "TemplateItemCollection") {
			int state;
			if (xmlReader.attributes().hasAttribute("state")) {
				// 获取名为 "state" 的属性的值
				state = xmlReader.attributes().value("state").toInt();
			}
			templateItemCollection = parseTemplateItemCollection(xmlReader, state);
		}
	}
	return templateItemCollection;
}
