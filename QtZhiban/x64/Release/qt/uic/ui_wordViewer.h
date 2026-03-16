/********************************************************************************
** Form generated from reading UI file 'wordViewer.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORDVIEWER_H
#define UI_WORDVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_wordViewerClass
{
public:

    void setupUi(QWidget *wordViewerClass)
    {
        if (wordViewerClass->objectName().isEmpty())
            wordViewerClass->setObjectName(QString::fromUtf8("wordViewerClass"));
        wordViewerClass->resize(850, 511);

        retranslateUi(wordViewerClass);

        QMetaObject::connectSlotsByName(wordViewerClass);
    } // setupUi

    void retranslateUi(QWidget *wordViewerClass)
    {
        wordViewerClass->setWindowTitle(QApplication::translate("wordViewerClass", "wordViewer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class wordViewerClass: public Ui_wordViewerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORDVIEWER_H
