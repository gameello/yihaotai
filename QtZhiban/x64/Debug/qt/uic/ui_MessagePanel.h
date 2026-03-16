/********************************************************************************
** Form generated from reading UI file 'MessagePanel.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGEPANEL_H
#define UI_MESSAGEPANEL_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MessagePanel
{
public:
    QGridLayout *gridLayout;
    QLabel *pIconLabel;
    QLabel *pMessageLabel;
    QSpacerItem *horizontalSpacer;
    QToolButton *pCloseBtn;

    void setupUi(QWidget *MessagePanel)
    {
        if (MessagePanel->objectName().isEmpty())
            MessagePanel->setObjectName(QString::fromUtf8("MessagePanel"));
        MessagePanel->resize(306, 50);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MessagePanel->sizePolicy().hasHeightForWidth());
        MessagePanel->setSizePolicy(sizePolicy);
        MessagePanel->setMaximumSize(QSize(16777215, 16777215));
        MessagePanel->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	font-family: Microsoft Yahei;\n"
"}\n"
"\n"
"QLabel{\n"
"	background:transparent;\n"
"}\n"
"\n"
"QToolButton{\n"
"	background:transparent;\n"
"	border:none;\n"
"}"));
        gridLayout = new QGridLayout(MessagePanel);
        gridLayout->setSpacing(5);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(5, 0, 5, 0);
        pIconLabel = new QLabel(MessagePanel);
        pIconLabel->setObjectName(QString::fromUtf8("pIconLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pIconLabel->sizePolicy().hasHeightForWidth());
        pIconLabel->setSizePolicy(sizePolicy1);
        pIconLabel->setMinimumSize(QSize(30, 30));
        pIconLabel->setMaximumSize(QSize(30, 30));
        pIconLabel->setStyleSheet(QString::fromUtf8(""));
        pIconLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(pIconLabel, 0, 0, 1, 1);

        pMessageLabel = new QLabel(MessagePanel);
        pMessageLabel->setObjectName(QString::fromUtf8("pMessageLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft Yahei"));
        font.setPointSize(10);
        pMessageLabel->setFont(font);
        pMessageLabel->setStyleSheet(QString::fromUtf8("background:transparent;"));

        gridLayout->addWidget(pMessageLabel, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(443, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        pCloseBtn = new QToolButton(MessagePanel);
        pCloseBtn->setObjectName(QString::fromUtf8("pCloseBtn"));
        pCloseBtn->setMinimumSize(QSize(30, 30));
        pCloseBtn->setMaximumSize(QSize(30, 30));
        pCloseBtn->setStyleSheet(QString::fromUtf8(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/tip/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        pCloseBtn->setIcon(icon);

        gridLayout->addWidget(pCloseBtn, 0, 3, 1, 1);


        retranslateUi(MessagePanel);

        QMetaObject::connectSlotsByName(MessagePanel);
    } // setupUi

    void retranslateUi(QWidget *MessagePanel)
    {
        MessagePanel->setWindowTitle(QApplication::translate("MessagePanel", "MessagePanel", nullptr));
        pIconLabel->setText(QString());
        pMessageLabel->setText(QApplication::translate("MessagePanel", "\345\274\200\345\247\213\346\240\207\347\273\230\351\233\267\350\276\276\350\243\205\345\244\207\357\274\214\347\202\271\345\207\273\345\217\263\351\224\256\345\217\226\346\266\210\346\240\207\347\273\230", nullptr));
        pCloseBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MessagePanel: public Ui_MessagePanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGEPANEL_H
