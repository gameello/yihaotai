#pragma once

#include <QWidget>
#include "ui_MessageDialog.h"
#include "ui/ModalDialog.h"

namespace Ui {
	class MessageDialog;
}

class MessageDialog : public ModalDialog
{
	Q_OBJECT

public:
	MessageDialog(QWidget *parent = Q_NULLPTR);
	~MessageDialog();

	static MessageDialog *instance(QWidget *parent = Q_NULLPTR);
	static int warn(QString message);

	void setTitle(QString message);
	void setMessage(QString message);

protected slots:
	int YesClick();
	int NoClick();
private:
	void InitWidget();

private:
	Ui::MessageDialog *ui;

	static MessageDialog *m_pInstance;
};
