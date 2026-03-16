#pragma once

#include <QtWidgets/QWidget>
#include "ui_QtZhiban.h"
#include "ui/ModalessDialog.h"
#include "Common/global.h"
#include "ui/MyTitleBar.h"
#include <QPropertyAnimation>		// 窗口抖动
#include <QSystemTrayIcon>
#include "Todo/mainwindow.h"

namespace Ui {
    class QtZhibanClass;
}
class QtZhiban : public QWidget
{
    Q_OBJECT

public:
    QtZhiban(QWidget *parent = nullptr);
    ~QtZhiban();

    void InitWidget();
    void Loadini();
    // 设置状态栏
	void SetStatusWidget();
    ///对话框状态栏
    QWidget* m_pStatusWidget;

private:
    Ui::QtZhibanClass* ui;

    int xiweiID;  // 当前登录的席位
    int currSeeXiweiID;   // 切换早晚汇报时，当前查看的席位
    QWidget* button_widget;
    QVBoxLayout* button_V_layout;
    QGridLayout* button_G_Layout;
    QHBoxLayout* HBlayout;
    MyTitleBar* m_titleBar;
    QPropertyAnimation* pShakeAnimation = nullptr;		// 窗口抖动
    // QSystemTrayIcon* trayIcon;                       // 右下角托盘图标
    QTimer timer_RefreshcurrTime;

public slots:
    void onButtonMinClicked();
    void onButtonRestoreClicked();
    void onButtonMaxClicked();
    void onButtonCloseClicked();

    void btn_clicked();
    void tabwidgetchanged(int index);
    void Table2ExcelByHtml(QTableWidget* table, QString title);
    void widget_shake();						// 窗口抖动
    void onOpacityWindow();                     // 透明度闪烁、
    void onDropWindow();                        // 下坠效果
    // void trayActivated(QSystemTrayIcon::ActivationReason reason);
    void RefreshcurrTime();                     // 与服务器同步时间



    // tree
    void updateActions();
private slots:
    void insertChild();
    bool insertColumn();
    void insertRow();
    bool removeColumn();
    void removeRow();
};