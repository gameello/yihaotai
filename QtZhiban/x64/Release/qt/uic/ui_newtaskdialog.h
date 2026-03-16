/********************************************************************************
** Form generated from reading UI file 'newtaskdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWTASKDIALOG_H
#define UI_NEWTASKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewTaskDialog
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QDateEdit *datepicker;
    QLabel *label_2;
    QLineEdit *title_et;
    QSlider *slider;
    QLabel *label_4;
    QPlainTextEdit *description_ed;
    QLabel *percent_lbl;
    QPushButton *savebtn;
    QPushButton *cancelbtn;
    QPushButton *deletebtn;

    void setupUi(QDialog *NewTaskDialog)
    {
        if (NewTaskDialog->objectName().isEmpty())
            NewTaskDialog->setObjectName(QString::fromUtf8("NewTaskDialog"));
        NewTaskDialog->resize(482, 334);
        formLayoutWidget = new QWidget(NewTaskDialog);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(20, 10, 441, 271));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        datepicker = new QDateEdit(formLayoutWidget);
        datepicker->setObjectName(QString::fromUtf8("datepicker"));

        formLayout->setWidget(0, QFormLayout::FieldRole, datepicker);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        title_et = new QLineEdit(formLayoutWidget);
        title_et->setObjectName(QString::fromUtf8("title_et"));

        formLayout->setWidget(1, QFormLayout::FieldRole, title_et);

        slider = new QSlider(formLayoutWidget);
        slider->setObjectName(QString::fromUtf8("slider"));
        slider->setOrientation(Qt::Horizontal);

        formLayout->setWidget(2, QFormLayout::FieldRole, slider);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        description_ed = new QPlainTextEdit(formLayoutWidget);
        description_ed->setObjectName(QString::fromUtf8("description_ed"));

        formLayout->setWidget(3, QFormLayout::FieldRole, description_ed);

        percent_lbl = new QLabel(formLayoutWidget);
        percent_lbl->setObjectName(QString::fromUtf8("percent_lbl"));
        percent_lbl->setMinimumSize(QSize(90, 0));

        formLayout->setWidget(2, QFormLayout::LabelRole, percent_lbl);

        savebtn = new QPushButton(NewTaskDialog);
        savebtn->setObjectName(QString::fromUtf8("savebtn"));
        savebtn->setGeometry(QRect(370, 300, 89, 25));
        cancelbtn = new QPushButton(NewTaskDialog);
        cancelbtn->setObjectName(QString::fromUtf8("cancelbtn"));
        cancelbtn->setGeometry(QRect(270, 300, 89, 25));
        deletebtn = new QPushButton(NewTaskDialog);
        deletebtn->setObjectName(QString::fromUtf8("deletebtn"));
        deletebtn->setGeometry(QRect(20, 300, 89, 25));

        retranslateUi(NewTaskDialog);

        QMetaObject::connectSlotsByName(NewTaskDialog);
    } // setupUi

    void retranslateUi(QDialog *NewTaskDialog)
    {
        NewTaskDialog->setWindowTitle(QApplication::translate("NewTaskDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("NewTaskDialog", "\346\227\245\346\234\237", nullptr));
        label_2->setText(QApplication::translate("NewTaskDialog", "\346\240\207\351\242\230", nullptr));
        label_4->setText(QApplication::translate("NewTaskDialog", "\346\217\217\350\277\260", nullptr));
        percent_lbl->setText(QApplication::translate("NewTaskDialog", "\345\256\214\346\210\220\347\231\276\345\210\206\346\257\224", nullptr));
        savebtn->setText(QApplication::translate("NewTaskDialog", "\344\277\235\345\255\230", nullptr));
        cancelbtn->setText(QApplication::translate("NewTaskDialog", "\345\217\226\346\266\210", nullptr));
        deletebtn->setText(QApplication::translate("NewTaskDialog", "\345\210\240\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewTaskDialog: public Ui_NewTaskDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWTASKDIALOG_H
