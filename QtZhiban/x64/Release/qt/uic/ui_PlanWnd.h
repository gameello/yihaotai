/********************************************************************************
** Form generated from reading UI file 'PlanWnd.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLANWND_H
#define UI_PLANWND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlanWnd
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;

    void setupUi(QWidget *PlanWnd)
    {
        if (PlanWnd->objectName().isEmpty())
            PlanWnd->setObjectName(QString::fromUtf8("PlanWnd"));
        PlanWnd->resize(1664, 1207);
        gridLayout = new QGridLayout(PlanWnd);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(PlanWnd);
        widget->setObjectName(QString::fromUtf8("widget"));

        gridLayout->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(PlanWnd);

        QMetaObject::connectSlotsByName(PlanWnd);
    } // setupUi

    void retranslateUi(QWidget *PlanWnd)
    {
        PlanWnd->setWindowTitle(QApplication::translate("PlanWnd", "PlanWnd", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlanWnd: public Ui_PlanWnd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLANWND_H
