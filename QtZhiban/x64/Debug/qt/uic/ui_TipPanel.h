/********************************************************************************
** Form generated from reading UI file 'TipPanel.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIPPANEL_H
#define UI_TIPPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TipPanel
{
public:
    QGridLayout *gridLayout_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *pIconLabel;
    QLabel *pTextLabel;

    void setupUi(QWidget *TipPanel)
    {
        if (TipPanel->objectName().isEmpty())
            TipPanel->setObjectName(QString::fromUtf8("TipPanel"));
        TipPanel->resize(248, 66);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TipPanel->sizePolicy().hasHeightForWidth());
        TipPanel->setSizePolicy(sizePolicy);
        TipPanel->setMinimumSize(QSize(143, 66));
        TipPanel->setMaximumSize(QSize(16777215, 66));
        TipPanel->setStyleSheet(QString::fromUtf8(""));
        gridLayout_2 = new QGridLayout(TipPanel);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(TipPanel);
        widget->setObjectName(QString::fromUtf8("widget"));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(28, -1, 28, 9);
        pIconLabel = new QLabel(widget);
        pIconLabel->setObjectName(QString::fromUtf8("pIconLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pIconLabel->sizePolicy().hasHeightForWidth());
        pIconLabel->setSizePolicy(sizePolicy1);
        pIconLabel->setMinimumSize(QSize(30, 30));
        pIconLabel->setMaximumSize(QSize(30, 30));

        gridLayout->addWidget(pIconLabel, 0, 0, 1, 1);

        pTextLabel = new QLabel(widget);
        pTextLabel->setObjectName(QString::fromUtf8("pTextLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pTextLabel->sizePolicy().hasHeightForWidth());
        pTextLabel->setSizePolicy(sizePolicy2);
        pTextLabel->setMaximumSize(QSize(16777215, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft Yahei"));
        pTextLabel->setFont(font);
        pTextLabel->setStyleSheet(QString::fromUtf8("#pTextLabel{\n"
"	font-family: Microsoft Yahei;\n"
"	font-size: 17px;\n"
"	color: #333333;\n"
"}"));
        pTextLabel->setWordWrap(true);

        gridLayout->addWidget(pTextLabel, 0, 1, 1, 1);


        gridLayout_2->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(TipPanel);

        QMetaObject::connectSlotsByName(TipPanel);
    } // setupUi

    void retranslateUi(QWidget *TipPanel)
    {
        TipPanel->setWindowTitle(QApplication::translate("TipPanel", "TipPanel", nullptr));
        pIconLabel->setText(QString());
        pTextLabel->setText(QApplication::translate("TipPanel", "\345\256\214\346\210\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TipPanel: public Ui_TipPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIPPANEL_H
