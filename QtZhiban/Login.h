#pragma once

#include <QWidget>
#include "ui_Login.h"
#include "Ui/ModalessDialog.h"
#include "Ui/ModalDialog.h"
#include "Common/global.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LoginClass; };
QT_END_NAMESPACE

class Login : public ModalDialog
{
	Q_OBJECT

public:
	Login(QWidget *parent = nullptr);
	~Login();
	void InitWidget() ;

private slots:
	void on_btn_signin_clicked();

private:
	Ui::LoginClass *ui;
};
