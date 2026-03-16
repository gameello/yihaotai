#include "TipPanel.h"
#include <QPainter>
#include <QDesktopWidget>

TipPanel *TipPanel::m_pInstance = nullptr;
QTimer *TipPanel::m_pTimer = nullptr;

TipPanel::TipPanel(QWidget *parent)
	: QWidget(parent), m_pParent(parent)
{
	ui.setupUi(this);

	// 设置窗口无边框且置于顶层
	setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);

	m_pMovie = new QMovie(this);
	ui.pIconLabel->setMovie(m_pMovie);

	// 设置MessagePanel窗体识别QSS样式
	opt = new QStyleOption();
	opt->init(this);
	QPainter painter(this);
	style()->drawPrimitive(QStyle::PE_Widget, opt, &painter, this);

	// 定时关闭窗口
	m_pTimer = new QTimer(m_pInstance);
	m_pTimer->callOnTimeout([]() {
		m_pInstance->close(); 
	});

	// 默认隐藏窗口
	hide();

	setStyleSheet("QWidget{background:#0F02BA5D;} \
		#TipPanel{border:1px solid #0F02BA5D; border-radius:5px; } \
		QLabel{background:transparent;}	\
		QToolButton{background:transparent;}");
}

TipPanel::~TipPanel()
{
	delete m_pMovie;
	m_pMovie = nullptr;

	delete opt;
	opt = nullptr;

	if (m_pTimer) {
		delete m_pTimer;
		m_pTimer = nullptr;
	}

	m_pInstance = nullptr;
}

TipPanel * TipPanel::instance(QWidget *parent)
{
	if (!m_pInstance)
	{
		m_pInstance = new TipPanel(m_pInstance);
	}
	return m_pInstance;
}

void TipPanel::success(QString text, int timeout)
{
	if (m_pInstance)
	{
		m_pInstance->setStyleSheet("#widget{background:#0F02BA5D;border:1px solid #0F02BA5D;border-radius: 5px; } \
		QLabel{background:transparent;}	\
		QToolButton{background:transparent;}");
		m_pInstance->setMessage(text);

		// 设置Icon
		if (m_pInstance->m_pMovie)
		{
			m_pInstance->m_pMovie->stop();
			m_pInstance->m_pMovie->setFileName(":/images/tip/success.png");
			m_pInstance->m_pMovie->start();
		}

		// 显示消息提示框
		m_pInstance->show();

		// 开启定时任务，定期关闭窗口
		startTimer(timeout);
	}
}

void TipPanel::failed(QString text, int timeout)
{
	if (m_pInstance)
	{
		m_pInstance->setStyleSheet("#widget{background:#0FBE2901;border:1px solid #0FBE2901;border-radius: 5px; } \
		QLabel{background:transparent;}	\
		QToolButton{background:transparent;}");
		m_pInstance->setMessage(text);
		m_pInstance->setMessage(text);

		// 设置Icon
		if (m_pInstance->m_pMovie)
		{
			m_pInstance->m_pMovie->stop();
			m_pInstance->m_pMovie->setFileName(":/images/tip/failed.png");
			m_pInstance->m_pMovie->start();
		}

		// 显示消息提示框
		m_pInstance->show();

		// 开启定时任务，定期关闭窗口
		startTimer(timeout);
	}
}

void TipPanel::progress(QString text, int timeout)
{
	if (m_pInstance)
	{
		m_pInstance->setStyleSheet("#widget{background:#0F000000;border:1px solid #0F000000;border-radius: 5px; } \
		QLabel{background:transparent;}	\
		QToolButton{background:transparent;}");
		m_pInstance->setMessage(text);

		// 设置Icon
		if (m_pInstance->m_pMovie)
		{
			m_pInstance->m_pMovie->stop();
			m_pInstance->m_pMovie->setFileName(":/images/tip/progress.gif");
			m_pInstance->m_pMovie->start();
		}

		// 显示消息提示框
		m_pInstance->show();

		// 开启定时任务，定期关闭窗口
		startTimer(timeout);
	}
}

void TipPanel::hidePanel()
{
	m_pInstance->m_pMovie->stop();
	m_pInstance->close();
}

/************************************************************************/
/* 继承QWidget后，setStyleSheet设置的样式将不会起作用。                 */
/* 重写此函数，是让setStyleSheet设置的样式生效。                        */
/************************************************************************/
void TipPanel::paintEvent(QPaintEvent *event)
{
	opt->init(this);
	QPainter painter(this);
	style()->drawPrimitive(QStyle::PE_Widget, opt, &painter, this);

	QWidget::paintEvent(event);
}

void TipPanel::resizeEvent(QResizeEvent *event)
{
	Q_UNUSED(event)

	QDesktopWidget* desktop = qApp->desktop();
	QRect geometry = desktop->screenGeometry();
	move((geometry.width() - this->width()) / 2, (geometry.height() - this->height()) / 2);
}

void TipPanel::setMessage(QString message)
{
	ui.pTextLabel->setText(message);
}

void TipPanel::startTimer(int timeout)
{
	if (timeout > 0) {
		m_pTimer->start(timeout);
	}
	else {
		m_pTimer->stop();
	}
}
