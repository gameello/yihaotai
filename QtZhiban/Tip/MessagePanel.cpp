#include "MessagePanel.h"

#include <QStyleOption>
#include <QPainter>
#include <QDebug>
#include <QDesktopWidget>

MessagePanel *MessagePanel::m_pInstance = nullptr;
QTimer *MessagePanel::m_pTimer = nullptr;

MessagePanel::MessagePanel(QWidget *parent)
	: QWidget(parent), parent(parent)
{
	ui.setupUi(this);
	
	// 设置消息提醒框的大小和位置
	QDesktopWidget* desktop = QApplication::desktop();
	QRect geometry = desktop->screenGeometry();
	this->setFixedWidth(geometry.width() / 2);
	move((geometry.width()-this->width())/2, 68);
	hide();

	// 设置MessagePanel窗体识别QSS样式
	opt = new QStyleOption();
	opt->init(this);
	QPainter painter(this);
	style()->drawPrimitive(QStyle::PE_Widget, opt, &painter, this);

	// 事件绑定
	connect(ui.pCloseBtn, &QToolButton::clicked, this, &MessagePanel::hide);

	// 定时关闭窗口
	m_pTimer = new QTimer(m_pInstance);
	m_pTimer->callOnTimeout([]() {m_pInstance->close(); });
}

MessagePanel::~MessagePanel()
{
	delete opt;
	opt = nullptr;

	if (m_pTimer) {
		delete m_pTimer;
		m_pTimer = nullptr;
	}

	m_pInstance = nullptr;
}

MessagePanel * MessagePanel::instance(QWidget *parent)
{
	if (!m_pInstance)
	{
		m_pInstance = new MessagePanel(parent);
	}
	return m_pInstance;
}

void MessagePanel::info(QString text, int timeout)
{
	if (m_pInstance)
	{
		m_pInstance->setStyleSheet("QWidget{background:#33007AC0;border:1px solid #007AC0;border-radius:2px;} \
		QLabel{background:transparent;border:none;color:#007AC0;font-family:Microsoft YaHei;font-size:16px;}	\
		#pIconLabel{image: url(:/images/tip/tip-info.png);} \
		#pCloseBtn{image:url(:/images/tip/tip-info_close.png);} \
		QToolButton{background:transparent;border:none;}");
		m_pInstance->setMessage(text);

		// 显示消息提示框
		m_pInstance->show();

		// 开启定时任务，定期关闭窗口
		startTimer(timeout);
	}
}

void MessagePanel::warn(QString text, int timeout)
{
	if (m_pInstance)
	{
		m_pInstance->setStyleSheet("QWidget{background:#33ffae3b;border:1px solid #ffae3b;border-radius:2px;} \
		QLabel{background:transparent;border:none;color:#ffae3b;font-family:Microsoft YaHei;font-size:16px;}	\
		#pIconLabel{image: url(:/images/tip/tip-warn.png);} \
		#pCloseBtn{image:url(:/images/tip/tip-warn_close.png);} \
		QToolButton{background:transparent;border:none;}");
		m_pInstance->setMessage(text);

		// 显示消息提示框
		m_pInstance->show();

		// 开启定时任务，定期关闭窗口
		startTimer(timeout);
	}
}

void MessagePanel::error(QString text, int timeout)
{
	if (m_pInstance)
	{
		m_pInstance->setStyleSheet("QWidget{background:#33ff0000;border:1px solid #ff0000;border-radius:2px;} \
		QLabel{background:transparent;border:none;color:#ff0000;font-family:Microsoft YaHei;font-size:16px;}	\
		#pIconLabel{image: url(:/images/tip/tip-error.png);} \
		#pCloseBtn{image:url(:/images/tip/tip-error_close.png);} \
		QToolButton{background:transparent;border:none;}");
		m_pInstance->setMessage(text);

		// 显示消息提示框
		m_pInstance->show();

		// 开启定时任务，定期关闭窗口
		startTimer(timeout);
	}
}

void MessagePanel::hidePanel()
{
	m_pInstance->hide();
}

/************************************************************************/
/* 继承QWidget后，setStyleSheet设置的样式将不会起作用。                 */
/* 重写此函数，是让setStyleSheet设置的样式生效。                        */
/************************************************************************/
void MessagePanel::paintEvent(QPaintEvent *event)
{
	opt->init(this);
	QPainter painter(this);
	style()->drawPrimitive(QStyle::PE_Widget, opt, &painter, this);

	QWidget::paintEvent(event);
}

void MessagePanel::resizeEvent(QResizeEvent *event)
{
	Q_UNUSED(event)
	this->setFixedWidth(parent->width() / 2);
}

void MessagePanel::mouseDoubleClickEvent(QMouseEvent *event)
{
	Q_UNUSED(event)

	emit doubleClicked();
}

void MessagePanel::setMessage(QString message)
{
	ui.pMessageLabel->setText(message);
}

void MessagePanel::startTimer(int timeout)
{
	if (timeout > 0) {
		m_pTimer->start(timeout);
	}
	else {
		m_pTimer->stop();
	}
}

