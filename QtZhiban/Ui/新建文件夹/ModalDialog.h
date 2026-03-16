#ifndef MODALDIALOG_H
#define MODALDIALOG_H

#include <QLabel>
#include <QToolButton>
#include <QToolButton>
#include <QStyleOption>
#include <QPainter>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QResizeEvent>
#include "FramelessDialog.h"
//#include "publicinterface_global.h"
//#include <service/event/ctkEventAdmin.h>
//#include "bean/ScenarioInfo.h"
//#include "constant/widget_constant.h"
//#include "bean/MapPoint.h"


#define SETUP_UI(ui) {    \
        m_widget = new QWidget(this);     \
        ui->setupUi(m_widget);                     \
        AddWidgetToDialogLayout(m_widget);         \
        m_widget->setMinimumSize(m_widget->size());  \
    }


namespace Ui {
	class ModalDialog;
}

class ModalDialog : public Ui::FramelessDialog
{
    Q_OBJECT

public:
    explicit ModalDialog(QWidget *parent = nullptr);
    ~ModalDialog();

    /**
     * @brief 初始化数据
     */
    virtual void InitData();

    /**
     * @brief 设置标题栏文本
     */
    void SetTitleText(QString text);

    /**
     * @brief 添加窗体到对话框布局
     */
    void AddWidgetToDialogLayout(QWidget *widget);

private:
    /**
     * @brief 设置标题栏
     */
    void SetTitleWidget();
	/**
	* @brief 设置状态栏
	*/
	void SetStatusWidget();

protected:
    /**
    * @brief 鼠标双击事件响应
    */
    virtual void mouseDoubleClickEvent(QMouseEvent* event);

    /**
    * @brief 大小改变事件响应
    */
    virtual void resizeEvent(QResizeEvent* event);

    virtual void InitWidget() = 0;

public slots:
    /**
     * @brief 关闭按钮槽函数
     */
    virtual void SlotCloseBtnClicked();

	void ShowDialog();

protected:

    ///对话框标题栏
    QWidget*					m_pTitleWidget;

    ///对话框整体布局
    QVBoxLayout*					m_pVLayout;

 
    ///标题栏文本
    QLabel*						m_pTitleText;

    ///关闭按钮
    QToolButton*				m_pCloseBtn;

	///对话框状态栏
	QWidget*                    m_pStatusWidget;

	QWidget * m_widget;

	

};

#endif // MODALDIALOG_H
