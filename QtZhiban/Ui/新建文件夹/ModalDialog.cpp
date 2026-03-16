#include "ui/ModalDialog.h"
#include <QApplication>
#include <QDesktopWidget>
#include "common/Utils.h"

ModalDialog::ModalDialog(QWidget *parent) : Ui::FramelessDialog(parent)// , ui(new Ui::ModelDialog)
{
    // ui->setupUi(this);
    InitData();

	setModal(true);
}

void ModalDialog::InitData()
{
    // 对话框最前显示
    this->setWindowFlags(windowFlags() | Qt::Tool);
    // 设置窗体透明度
    this->setWindowOpacity(0.95);

	// this->setWindowModality(Qt::ApplicationModal);

    m_pTitleWidget = new QWidget(this);

    //设置标题栏
    SetTitleWidget();

	// 设置整体布局
	setLayout(m_pVLayout);

    //设置样式表
    SetStyleSheet(this, ":/qss/modaldialog.qss");

    //关联关闭按钮信号和槽
    connect(m_pCloseBtn, SIGNAL(clicked()), this, SLOT(SlotCloseBtnClicked()));
}

void ModalDialog::SetTitleWidget()
{
	// 设置标题栏背景
	int nTitleWidgetH = 32;
	m_pTitleWidget->setFixedHeight(nTitleWidgetH);
	/*m_pTitleWidget->setStyleSheet("border:none; background:transparent;color:#FFFFFF;");*/

	// 设置标题栏图标
	int iconWidgetW = 32;
	QWidget *iconWidget = new QWidget(m_pTitleWidget);
	iconWidget->setFixedWidth(iconWidgetW);
    iconWidget->setStyleSheet("background:url(:/images/title/tool-bar_left.png)");

	// 标题栏文本窗口
	QWidget *titleWidget = new QWidget(m_pTitleWidget);
	titleWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    titleWidget->setStyleSheet("border-image:url(:/images/title/tool-bar_moddle.png)");
	QHBoxLayout *titleLayout = new QHBoxLayout(titleWidget);
	titleLayout->setContentsMargins(0, 0, 0, 0);

	// 设置标题栏文本
	int nTitleTextH = 32;
	m_pTitleText = new QLabel();
	m_pTitleText->setFixedHeight(nTitleTextH);
	m_pTitleText->setStyleSheet("background:transparent;border:none;color:#FFFFFF;");
	titleLayout->addWidget(m_pTitleText);
	titleLayout->addStretch();
	titleWidget->setLayout(titleLayout);

	// 设置关闭窗口
    int closeWidgetW = 104;
	QWidget *closeWidget = new QWidget(m_pTitleWidget);
	closeWidget->setFixedWidth(closeWidgetW);
    closeWidget->setStyleSheet("background-image:url(:/images/title/tool-bar_right.png)");
	QHBoxLayout *closeLayout = new QHBoxLayout(closeWidget);
	closeLayout->setContentsMargins(0, 0, 0, 12);

	// 设置关闭按钮
	int nCloseBtnW = 46;
	int nCloseBtnH = 20;
	m_pCloseBtn = new QToolButton();
	m_pCloseBtn->setFixedSize(nCloseBtnW, nCloseBtnH);
	QSpacerItem *horizontalSpacer = new QSpacerItem(25, 20, QSizePolicy::Expanding, QSizePolicy::Fixed);
	closeLayout->addItem(horizontalSpacer);
	closeLayout->addWidget(m_pCloseBtn);
	closeWidget->setLayout(closeLayout);
	m_pCloseBtn->setStyleSheet("QToolButton{background:transparent;}\
		QToolButton:hover,QToolButton:pressed{background:url(:/images/title/close.png);border:none;}");

	// 标题栏添加布局
	QHBoxLayout *pHLayout = new QHBoxLayout();
	pHLayout->setContentsMargins(0, 0, 0, 0);
	pHLayout->setSpacing(0);
	pHLayout->addWidget(iconWidget);
	pHLayout->addWidget(titleWidget);
	pHLayout->addWidget(closeWidget);
	m_pTitleWidget->setLayout(pHLayout);

	// 对话框整体布局
	m_pVLayout = new QVBoxLayout();
	m_pVLayout->setContentsMargins(0, 0, 0, 0);
	m_pVLayout->setSpacing(0);

	// 添加标题栏到整体布局
	m_pVLayout->addWidget(m_pTitleWidget);

	// 设置可拖动窗口的区域
	SetMovableArea(QRect(0, 0, width(), 30));

	// 设置不可改变大小
	SetResizeWidget(false);
}

void ModalDialog::SetTitleText(QString text)
{
    // QString str = tr("LineNode");
    m_pTitleText->setText(tr("%1").arg(text));
}

void ModalDialog::AddWidgetToDialogLayout(QWidget *widget)
{
    m_pVLayout->addWidget(widget);
}

void ModalDialog::SlotCloseBtnClicked()
{
    this->close();
}

void ModalDialog::ShowDialog()
{
	this->show();
}

void ModalDialog::resizeEvent(QResizeEvent* event)
{
    SetMovableArea(QRect(0, 0, width(), 30));

    QDesktopWidget* desktop = QApplication::desktop();
	QRect geometry = desktop->screenGeometry();
	move((geometry.width() - this->width()) / 2, (geometry.height() - this->height()) / 2);
}

void ModalDialog::mouseDoubleClickEvent(QMouseEvent* event)
{
    //禁用鼠标双击事件
}

ModalDialog::~ModalDialog(void)
{
    if (m_pTitleText)
    {
        delete m_pTitleText;
        m_pTitleText = nullptr;
    }

    if (m_pCloseBtn)
    {
        delete m_pCloseBtn;
        m_pCloseBtn = nullptr;
    }

    if (m_pTitleWidget)
    {
        delete m_pTitleWidget;
        m_pTitleWidget = nullptr;
    }

    if (m_pVLayout)
    {
        delete m_pVLayout;
        m_pVLayout = nullptr;
    }
}

