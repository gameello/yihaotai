#ifndef MODALESSDIALOG_H
#define MODALESSDIALOG_H

#include "FramelessWidget.h"
#include <QLabel>
#include <QToolButton>
#include <QStyleOption>
#include <QPainter>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QResizeEvent>

#define SETUP_UI(ui) {    \
        m_widget = new QWidget(this);     \
        ui->setupUi(m_widget);                     \
        AddWidgetToDialogLayout(m_widget);         \
        m_widget->setMinimumSize(m_widget->size());  \
    }

namespace Ui {
	class ModalessDialog;
}

class  ModalessDialog : public Ui::FramelessWidget
{
    Q_OBJECT

public:
    explicit ModalessDialog(QWidget *parent = nullptr);
    ~ModalessDialog();

    /**
     * @brief 初始化数据
     */
    void InitData();

    /**
     * @brief 设置标题栏文本
     */
    void SetTitleText(QString text);	

    /**
     * @brief 添加窗体到对话框布局
     */
    void AddWidgetToDialogLayout(QWidget *widget);

signals:
	void WindowHide();

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


	virtual void hideEvent(QHideEvent *event) override;

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
    QVBoxLayout*				m_pVLayout;

    ///标题栏文本
    QLabel*						m_pTitleText;

    ///关闭按钮
	QToolButton*				m_pCloseBtn;

	///对话框状态栏
	QWidget*                    m_pStatusWidget;

	QWidget * m_widget;
};

#endif // MODALESSDIALOG_H
