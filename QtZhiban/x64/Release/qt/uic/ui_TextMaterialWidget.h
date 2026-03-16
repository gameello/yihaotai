/********************************************************************************
** Form generated from reading UI file 'TextMaterialWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTMATERIALWIDGET_H
#define UI_TEXTMATERIALWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TextMaterialWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *pName;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pCommitBtn;
    QPushButton *pCancelBtn;

    void setupUi(QWidget *TextMaterialWidget)
    {
        if (TextMaterialWidget->objectName().isEmpty())
            TextMaterialWidget->setObjectName(QString::fromUtf8("TextMaterialWidget"));
        TextMaterialWidget->resize(342, 356);
        verticalLayout = new QVBoxLayout(TextMaterialWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(TextMaterialWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        pName = new QLineEdit(TextMaterialWidget);
        pName->setObjectName(QString::fromUtf8("pName"));

        horizontalLayout_2->addWidget(pName);


        verticalLayout->addLayout(horizontalLayout_2);

        textEdit = new QTextEdit(TextMaterialWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pCommitBtn = new QPushButton(TextMaterialWidget);
        pCommitBtn->setObjectName(QString::fromUtf8("pCommitBtn"));

        horizontalLayout->addWidget(pCommitBtn);

        pCancelBtn = new QPushButton(TextMaterialWidget);
        pCancelBtn->setObjectName(QString::fromUtf8("pCancelBtn"));

        horizontalLayout->addWidget(pCancelBtn);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(TextMaterialWidget);

        QMetaObject::connectSlotsByName(TextMaterialWidget);
    } // setupUi

    void retranslateUi(QWidget *TextMaterialWidget)
    {
        TextMaterialWidget->setWindowTitle(QApplication::translate("TextMaterialWidget", "MyQtGuiClass", nullptr));
        label->setText(QApplication::translate("TextMaterialWidget", "\346\226\207\344\273\266\345\220\215\357\274\232", nullptr));
        pCommitBtn->setText(QApplication::translate("TextMaterialWidget", "\346\217\220\344\272\244", nullptr));
        pCancelBtn->setText(QApplication::translate("TextMaterialWidget", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TextMaterialWidget: public Ui_TextMaterialWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTMATERIALWIDGET_H
