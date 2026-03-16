/********************************************************************************
** Form generated from reading UI file 'calandarWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALANDARWIDGET_H
#define UI_CALANDARWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_calandarWidgetClass
{
public:
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label_6;
    QLabel *label_1;
    QPushButton *nextYearButton;
    QPushButton *nextMonthButton;
    QPushButton *lastYearButton;
    QLabel *label_0;
    QLabel *cdlabel;
    QPushButton *lastMonthButton;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_5;

    void setupUi(QWidget *calandarWidgetClass)
    {
        if (calandarWidgetClass->objectName().isEmpty())
            calandarWidgetClass->setObjectName(QString::fromUtf8("calandarWidgetClass"));
        calandarWidgetClass->resize(1212, 899);
        gridLayout = new QGridLayout(calandarWidgetClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(calandarWidgetClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 1, 2, 1, 1);

        label_6 = new QLabel(calandarWidgetClass);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 1, 6, 1, 1);

        label_1 = new QLabel(calandarWidgetClass);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_1, 1, 1, 1, 1);

        nextYearButton = new QPushButton(calandarWidgetClass);
        nextYearButton->setObjectName(QString::fromUtf8("nextYearButton"));

        gridLayout->addWidget(nextYearButton, 0, 6, 1, 1);

        nextMonthButton = new QPushButton(calandarWidgetClass);
        nextMonthButton->setObjectName(QString::fromUtf8("nextMonthButton"));

        gridLayout->addWidget(nextMonthButton, 0, 5, 1, 1);

        lastYearButton = new QPushButton(calandarWidgetClass);
        lastYearButton->setObjectName(QString::fromUtf8("lastYearButton"));

        gridLayout->addWidget(lastYearButton, 0, 0, 1, 1);

        label_0 = new QLabel(calandarWidgetClass);
        label_0->setObjectName(QString::fromUtf8("label_0"));
        label_0->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_0, 1, 0, 1, 1);

        cdlabel = new QLabel(calandarWidgetClass);
        cdlabel->setObjectName(QString::fromUtf8("cdlabel"));
        cdlabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(cdlabel, 0, 2, 1, 3);

        lastMonthButton = new QPushButton(calandarWidgetClass);
        lastMonthButton->setObjectName(QString::fromUtf8("lastMonthButton"));

        gridLayout->addWidget(lastMonthButton, 0, 1, 1, 1);

        label_4 = new QLabel(calandarWidgetClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 1, 4, 1, 1);

        label_3 = new QLabel(calandarWidgetClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 1, 3, 1, 1);

        label_5 = new QLabel(calandarWidgetClass);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 1, 5, 1, 1);


        retranslateUi(calandarWidgetClass);

        QMetaObject::connectSlotsByName(calandarWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *calandarWidgetClass)
    {
        calandarWidgetClass->setWindowTitle(QApplication::translate("calandarWidgetClass", "calandarWidget", nullptr));
        label_2->setText(QApplication::translate("calandarWidgetClass", "\345\221\250\344\270\211", nullptr));
        label_6->setText(QApplication::translate("calandarWidgetClass", "\345\221\250\346\227\245", nullptr));
        label_1->setText(QApplication::translate("calandarWidgetClass", "\345\221\250\344\272\214", nullptr));
        nextYearButton->setText(QApplication::translate("calandarWidgetClass", ">>", nullptr));
        nextMonthButton->setText(QApplication::translate("calandarWidgetClass", ">", nullptr));
        lastYearButton->setText(QApplication::translate("calandarWidgetClass", "<<", nullptr));
        label_0->setText(QApplication::translate("calandarWidgetClass", "\345\221\250\344\270\200", nullptr));
        cdlabel->setText(QApplication::translate("calandarWidgetClass", "2024\345\271\26411\346\234\210", nullptr));
        lastMonthButton->setText(QApplication::translate("calandarWidgetClass", "<", nullptr));
        label_4->setText(QApplication::translate("calandarWidgetClass", "\345\221\250\344\272\224", nullptr));
        label_3->setText(QApplication::translate("calandarWidgetClass", "\345\221\250\345\233\233", nullptr));
        label_5->setText(QApplication::translate("calandarWidgetClass", "\345\221\250\345\205\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class calandarWidgetClass: public Ui_calandarWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALANDARWIDGET_H
