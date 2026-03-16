/********************************************************************************
** Form generated from reading UI file 'paibanWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAIBANWIDGET_H
#define UI_PAIBANWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_paibanWidgetClass
{
public:
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *cdlabel;
    QPushButton *pushButton;
    QLabel *label_00;
    QLabel *label_01;
    QLabel *label_02;
    QLabel *label_03;
    QLabel *label_04;
    QLabel *label_05;
    QLabel *label_06;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;

    void setupUi(QWidget *paibanWidgetClass)
    {
        if (paibanWidgetClass->objectName().isEmpty())
            paibanWidgetClass->setObjectName(QString::fromUtf8("paibanWidgetClass"));
        paibanWidgetClass->resize(870, 624);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(paibanWidgetClass->sizePolicy().hasHeightForWidth());
        paibanWidgetClass->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(paibanWidgetClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(paibanWidgetClass);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 851, 622));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, -1, 9, -1);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        cdlabel = new QLabel(scrollAreaWidgetContents);
        cdlabel->setObjectName(QString::fromUtf8("cdlabel"));
        cdlabel->setMaximumSize(QSize(16777215, 50));
        cdlabel->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(cdlabel, 0, 1, 1, 6);

        pushButton = new QPushButton(scrollAreaWidgetContents);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_2->addWidget(pushButton, 0, 7, 1, 1);

        label_00 = new QLabel(scrollAreaWidgetContents);
        label_00->setObjectName(QString::fromUtf8("label_00"));
        label_00->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_00, 1, 1, 1, 1);

        label_01 = new QLabel(scrollAreaWidgetContents);
        label_01->setObjectName(QString::fromUtf8("label_01"));
        label_01->setMaximumSize(QSize(16777215, 50));
        label_01->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_01, 1, 2, 1, 1);

        label_02 = new QLabel(scrollAreaWidgetContents);
        label_02->setObjectName(QString::fromUtf8("label_02"));
        label_02->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_02, 1, 3, 1, 1);

        label_03 = new QLabel(scrollAreaWidgetContents);
        label_03->setObjectName(QString::fromUtf8("label_03"));
        label_03->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_03, 1, 4, 1, 1);

        label_04 = new QLabel(scrollAreaWidgetContents);
        label_04->setObjectName(QString::fromUtf8("label_04"));
        label_04->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_04, 1, 5, 1, 1);

        label_05 = new QLabel(scrollAreaWidgetContents);
        label_05->setObjectName(QString::fromUtf8("label_05"));
        label_05->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_05, 1, 6, 1, 1);

        label_06 = new QLabel(scrollAreaWidgetContents);
        label_06->setObjectName(QString::fromUtf8("label_06"));
        label_06->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_06, 1, 7, 1, 1);

        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 2, 1, 1, 1);

        label_2 = new QLabel(scrollAreaWidgetContents);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_2, 2, 2, 1, 1);

        label_3 = new QLabel(scrollAreaWidgetContents);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_3, 2, 3, 1, 1);

        label_4 = new QLabel(scrollAreaWidgetContents);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_4, 2, 4, 1, 1);

        label_5 = new QLabel(scrollAreaWidgetContents);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMaximumSize(QSize(16777215, 50));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_5, 2, 5, 1, 1);

        label_6 = new QLabel(scrollAreaWidgetContents);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_6, 2, 6, 1, 1);

        label_7 = new QLabel(scrollAreaWidgetContents);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_7, 2, 7, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(paibanWidgetClass);

        QMetaObject::connectSlotsByName(paibanWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *paibanWidgetClass)
    {
        paibanWidgetClass->setWindowTitle(QApplication::translate("paibanWidgetClass", "paibanWidget", nullptr));
        cdlabel->setText(QApplication::translate("paibanWidgetClass", "2024\345\271\26411\346\234\210", nullptr));
        pushButton->setText(QApplication::translate("paibanWidgetClass", "\350\277\224\345\233\236", nullptr));
        label_00->setText(QApplication::translate("paibanWidgetClass", "\345\221\250\344\270\200", nullptr));
        label_01->setText(QApplication::translate("paibanWidgetClass", "\345\221\250\344\272\214", nullptr));
        label_02->setText(QApplication::translate("paibanWidgetClass", "\345\221\250\344\270\211", nullptr));
        label_03->setText(QApplication::translate("paibanWidgetClass", "\345\221\250\345\233\233", nullptr));
        label_04->setText(QApplication::translate("paibanWidgetClass", "\345\221\250\344\272\224", nullptr));
        label_05->setText(QApplication::translate("paibanWidgetClass", "\345\221\250\345\205\255", nullptr));
        label_06->setText(QApplication::translate("paibanWidgetClass", "\345\221\250\346\227\245", nullptr));
        label->setText(QApplication::translate("paibanWidgetClass", "TextLabel", nullptr));
        label_2->setText(QApplication::translate("paibanWidgetClass", "TextLabel", nullptr));
        label_3->setText(QApplication::translate("paibanWidgetClass", "TextLabel", nullptr));
        label_4->setText(QApplication::translate("paibanWidgetClass", "TextLabel", nullptr));
        label_5->setText(QApplication::translate("paibanWidgetClass", "TextLabel", nullptr));
        label_6->setText(QApplication::translate("paibanWidgetClass", "TextLabel", nullptr));
        label_7->setText(QApplication::translate("paibanWidgetClass", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class paibanWidgetClass: public Ui_paibanWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAIBANWIDGET_H
