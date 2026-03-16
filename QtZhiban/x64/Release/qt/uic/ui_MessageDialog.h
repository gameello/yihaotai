/********************************************************************************
** Form generated from reading UI file 'MessageDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGEDIALOG_H
#define UI_MESSAGEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MessageDialog
{
public:
    QGridLayout *gridLayout_2;
    QWidget *pCenterWidget;
    QGridLayout *gridLayout_3;
    QLabel *pMessageLabel;
    QWidget *pCommandWidget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pAcceptBtn;
    QPushButton *pRejectBtn;

    void setupUi(QWidget *MessageDialog)
    {
        if (MessageDialog->objectName().isEmpty())
            MessageDialog->setObjectName(QString::fromUtf8("MessageDialog"));
        MessageDialog->resize(346, 120);
        MessageDialog->setStyleSheet(QString::fromUtf8("#MessageDialog{\n"
"	border: 2px solid #0A4B8D;\n"
"	border-top:none;\n"
"}\n"
"\n"
"#pCenterWidget{\n"
"	border: none;\n"
"}\n"
"\n"
"#pCommandWidget{\n"
"	border: none;\n"
"	\n"
"}"));
        gridLayout_2 = new QGridLayout(MessageDialog);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(2, 0, 2, 2);
        pCenterWidget = new QWidget(MessageDialog);
        pCenterWidget->setObjectName(QString::fromUtf8("pCenterWidget"));
        gridLayout_3 = new QGridLayout(pCenterWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        pMessageLabel = new QLabel(pCenterWidget);
        pMessageLabel->setObjectName(QString::fromUtf8("pMessageLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        pMessageLabel->setFont(font);
        pMessageLabel->setAlignment(Qt::AlignCenter);
        pMessageLabel->setWordWrap(true);

        gridLayout_3->addWidget(pMessageLabel, 0, 0, 1, 1);


        gridLayout_2->addWidget(pCenterWidget, 0, 0, 1, 1);

        pCommandWidget = new QWidget(MessageDialog);
        pCommandWidget->setObjectName(QString::fromUtf8("pCommandWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pCommandWidget->sizePolicy().hasHeightForWidth());
        pCommandWidget->setSizePolicy(sizePolicy);
        pCommandWidget->setMinimumSize(QSize(0, 35));
        pCommandWidget->setMaximumSize(QSize(16777215, 35));
        gridLayout = new QGridLayout(pCommandWidget);
        gridLayout->setSpacing(5);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(5, 0, 5, 0);
        horizontalSpacer = new QSpacerItem(223, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        pAcceptBtn = new QPushButton(pCommandWidget);
        pAcceptBtn->setObjectName(QString::fromUtf8("pAcceptBtn"));
        pAcceptBtn->setCheckable(false);

        gridLayout->addWidget(pAcceptBtn, 0, 1, 1, 1);

        pRejectBtn = new QPushButton(pCommandWidget);
        pRejectBtn->setObjectName(QString::fromUtf8("pRejectBtn"));
        pRejectBtn->setCheckable(false);

        gridLayout->addWidget(pRejectBtn, 0, 2, 1, 1);


        gridLayout_2->addWidget(pCommandWidget, 1, 0, 1, 1);


        retranslateUi(MessageDialog);

        QMetaObject::connectSlotsByName(MessageDialog);
    } // setupUi

    void retranslateUi(QWidget *MessageDialog)
    {
        MessageDialog->setWindowTitle(QApplication::translate("MessageDialog", "MessageDialog", nullptr));
        pMessageLabel->setText(QString());
        pAcceptBtn->setText(QApplication::translate("MessageDialog", "\346\230\257(&Y)", nullptr));
        pRejectBtn->setText(QApplication::translate("MessageDialog", "\345\220\246(&N)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MessageDialog: public Ui_MessageDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGEDIALOG_H
