#include "MyColorDialog.h"

MyColorDialog::MyColorDialog(QWidget *parent)
	: ModalDialog(parent)
{
	InitWidget();
}

MyColorDialog::~MyColorDialog()
{
	int a = 1;
}

void MyColorDialog::setCurrentColor(QColor color)
{
	m_ColorDialog->setCurrentColor(color);
	m_ColorDialog->show();
}

void MyColorDialog::InitWidget()
{
	SetTitleText(QString::fromLocal8Bit("ÑÕÉ«¶Ô»°¿ò"));
	//setWindowModality(Qt::WindowModal);

	m_ColorDialog = new QColorDialog();
	m_ColorDialog->setOption(QColorDialog::ShowAlphaChannel);
	m_ColorDialog->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
	AddWidgetToDialogLayout(m_ColorDialog);

	connect(m_pCloseBtn, SIGNAL(clicked()), m_ColorDialog, SIGNAL(rejected()));
	connect(m_ColorDialog, SIGNAL(colorSelected(QColor)), this, SLOT(slotColorSelect(QColor)));
	connect(m_ColorDialog, &QDialog::rejected, [=] {
		m_color = "";
		this->hide();
	});
}

//void MyColorDialog::showEvent(QShowEvent *event)
//{
//	m_ColorDialog->show();
//}

void MyColorDialog::slotColorSelect(const QColor &color)
{
	m_color = color;
	this->hide();
}
