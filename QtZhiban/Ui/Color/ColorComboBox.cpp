#include "ColorComboBox.h"
#include <QObject>
#include <QAction>
#include <QGridLayout>
#include <QMenu>
#include <QPainter>
#include <QColorDialog>

ColorComboBox::ColorComboBox(QWidget *parent) :
    QToolButton(parent)
{
	m_MyColorDialog = new MyColorDialog(this);

	setAutoFillBackground(true);
	//setBackgroundRole(QPalette::Foreground);

	connect(this, SIGNAL(clicked()), this, SLOT(OnShowColorBoard()));

    this->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
}

void ColorComboBox::OnShowColorBoard()
{
	m_MyColorDialog->setCurrentColor(m_color);
	m_MyColorDialog->exec();
	QColor color = m_MyColorDialog->getSelectedColor();
	if (color.isValid())
	{
		m_color = color;
		changedColor(color);
	}
}

void ColorComboBox::changedColor(QColor color)
{
    QString strstyle = QString("QToolButton{background-color:rgba(%1,%2,%3,%4);}").arg(QString::number(color.red()),QString::number(color.green()),QString::number(color.blue()),QString::number(color.alpha()));
    this->setStyleSheet(strstyle);
}

void ColorComboBox::setColor(QRgb color)
{
    this->m_color = (QColor)color;
	changedColor(color);
}

QRgb ColorComboBox::getColor()
{
    QRgb mRgb = qRgba(m_color.red(),m_color.green(),m_color.blue(),m_color.alpha());
    return mRgb;
}

QString ColorComboBox::getStrColor()
{
    QRgb mRgb = qRgba(m_color.red(), m_color.green(), m_color.blue(),m_color.alpha());
    QColor curColor = (QColor)mRgb;
    QString strColor = QString("background-color:rgba(%1,%2,%3,%4);").arg(QString::number(curColor.red()),QString::number(curColor.green()),QString::number(curColor.blue()),QString::number(curColor.alpha()));
    return strColor;
}


void ColorComboBox::setHexColor(QString color)
{
	//color.replace("#", "0x");
	this->m_color = QColor(color);
	changedColor(m_color);
}

QString ColorComboBox::getHexColor()
{
	QString str = m_color.name(QColor::HexRgb);
	return str;
}

QColor ColorComboBox::getQColor()
{
	return m_color;
}

void ColorComboBox::setQColor(QColor color)
{
	this->m_color = color;
	changedColor(color);
}
