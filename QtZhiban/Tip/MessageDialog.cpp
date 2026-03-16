#include "MessageDialog.h"

MessageDialog *MessageDialog::m_pInstance = nullptr;
MessageDialog::MessageDialog(QWidget *parent)
	: ModalDialog(parent), ui(new Ui::MessageDialog)
{
	SETUP_UI(ui);

	InitWidget();

	connect(ui->pAcceptBtn, &QPushButton::clicked, this, &MessageDialog::YesClick);
	connect(ui->pRejectBtn, &QPushButton::clicked, this, &MessageDialog::NoClick);
}

MessageDialog::~MessageDialog()
{
	delete ui;

	m_pInstance = nullptr;
}

MessageDialog * MessageDialog::instance(QWidget *parent)
{
	if (!m_pInstance)
	{
		m_pInstance = new MessageDialog(parent);
	}
	return m_pInstance;
}

int MessageDialog::warn(QString message)
{
	////临时取消单例模式，因为单例模式在二次弹出的时候会保存pushbutton的点击状态显示2次会出现两个选中的按钮
	//m_pInstance->setTitle(QString::fromLocal8Bit("警告"));
	//m_pInstance->setMessage(message);
	//return m_pInstance->exec();
	MessageDialog *pInstance = new MessageDialog(nullptr);
	pInstance->setTitle(QString::fromLocal8Bit("警告"));
	pInstance->setMessage(message);
	return pInstance->exec();
}

void MessageDialog::setTitle(QString title)
{
	SetTitleText(title);
}

void MessageDialog::setMessage(QString message)
{
	ui->pMessageLabel->setText(message);
}

int MessageDialog::YesClick()
{
	accept();
	return 1;
}

int MessageDialog::NoClick()
{
	reject();
	return 0;
}
void  MessageDialog::InitWidget()
{

}
