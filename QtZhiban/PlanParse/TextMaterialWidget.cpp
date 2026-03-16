#include "TextMaterialWidget.h"
#include <QDomDocument>

TextMaterialWidget::TextMaterialWidget(QWidget *parent)
	: ModalDialog(parent),ui(new Ui::TextMaterialWidget)
{
	SETUP_UI(ui);
	InitWidget();
}

TextMaterialWidget::~TextMaterialWidget()
{
}

void TextMaterialWidget::InitWidget()
{
	SetTitleText(QString::fromLocal8Bit("添加文本素材"));

	connect(ui->pCommitBtn, &QPushButton::clicked, this, &TextMaterialWidget::addTextMaterial);
	connect(ui->pCancelBtn, &QPushButton::clicked, this, &TextMaterialWidget::close);
}

void TextMaterialWidget::setFileName(QString &name)
{
	ui->pName->setText(name);
}

void TextMaterialWidget::setEditText(QString &content)
{
	ui->textEdit->setText(content);
	
	//QTextCursor cursor = ui->textEdit->textCursor();
	//cursor.movePosition(QTextCursor::End);
	//cursor.insertBlock();
	//QTextBlockFormat blockFormat;
	//blockFormat.setAlignment(Qt::AlignLeft);
	//QTextCharFormat charFormat;
	//charFormat.setFontPointSize(14);
	//charFormat.setFontFamily("Microsoft YaHei");
	//cursor.setBlockFormat(blockFormat);
	//cursor.setCharFormat(charFormat);
	//cursor.insertText(content);
}

void TextMaterialWidget::addTextMaterial()
{
	QString fileName = ui->pName->text();
	if (!fileName.contains(".xml")) fileName = QString("%1%2").arg(fileName).arg(".xml");
	QString filePath = QString("%1/%2/%3").arg(qApp->applicationDirPath()).arg(QString::fromLocal8Bit("文本素材")).arg(fileName);
	QString textStr = ui->textEdit->toPlainText();
	// 创建 QDomDocument 以构建 XML 文档
	QDomDocument xmlDoc;
	// 创建XML声明节点
	QDomNode xmlNode = xmlDoc.createProcessingInstruction("xml","version=\"1.0\" encoding=\"UTF-8\"");
	xmlDoc.appendChild(xmlNode);
	// 创建根元素
	QDomElement root = xmlDoc.createElement("TextMaterial");
	xmlDoc.appendChild(root);
	QDomElement title = xmlDoc.createElement("Title");
	QDomText blockText = xmlDoc.createTextNode(fileName);
	title.appendChild(blockText);
	root.appendChild(title);
	QDomElement content = xmlDoc.createElement("Content");
	blockText = xmlDoc.createTextNode(textStr);
	content.appendChild(blockText);
	root.appendChild(content);

	// 创建一个文件来保存XML数据
	QFile file(filePath);
	//if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
	//	QTextStream stream(&file);
	//	stream.setCodec("UTF-8");
	//	stream << xmlDoc.toString(); // 将XML写入文件
	//	file.close();
	//}
	emit addTextItem(fileName);
	this->close();
}
