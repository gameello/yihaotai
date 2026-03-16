#ifndef COLORCOMBOBOX_H
#define COLORCOMBOBOX_H

#include <QToolButton>
#include <QRgb>
#include <QString>
//#include "publicinterface_global.h"
#include "MyColorDialog.h"

class  ColorComboBox : public QToolButton
{
    Q_OBJECT

public:
    ColorComboBox(QWidget *parent = 0);

public:
    //设置颜色下拉框当前颜色
    void setColor(QRgb color);
    //获得颜色下拉框当前颜色
    QRgb getColor();
    //获得字符串颜色值
    QString getStrColor();
	//设置十六进制颜色值
	void setHexColor(QString color);
	//获得十六进制颜色值
	QString getHexColor();
	//获得QColor类型的颜色值
	QColor getQColor();
	//设置QColor类型的颜色值
	void setQColor(QColor color);

private slots:
    void OnShowColorBoard();
    void changedColor(QColor color);

private:
    QColor m_color;
	MyColorDialog *m_MyColorDialog;
};

#endif
