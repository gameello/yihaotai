#pragma once

#include "ui/ModalDialog.h"
//#include "publicinterface_global.h"
#include <QColorDialog>

class MyColorDialog : public ModalDialog
{
	Q_OBJECT

public:
	MyColorDialog(QWidget *parent);
	~MyColorDialog();

	QColor getSelectedColor() { return m_color; }

	void setCurrentColor(QColor color);

//protected:
//	virtual void showEvent(QShowEvent *event) override;

private:
	void InitWidget() override;	

public slots:
	void slotColorSelect(const QColor &color);

private:
	QColorDialog *m_ColorDialog;

	QColor m_color;
};
