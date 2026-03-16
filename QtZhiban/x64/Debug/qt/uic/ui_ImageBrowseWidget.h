/********************************************************************************
** Form generated from reading UI file 'ImageBrowseWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEBROWSEWIDGET_H
#define UI_IMAGEBROWSEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageBrowseWidget
{
public:
    QGridLayout *gridLayout;

    void setupUi(QWidget *ImageBrowseWidget)
    {
        if (ImageBrowseWidget->objectName().isEmpty())
            ImageBrowseWidget->setObjectName(QString::fromUtf8("ImageBrowseWidget"));
        ImageBrowseWidget->resize(400, 300);
        gridLayout = new QGridLayout(ImageBrowseWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setVerticalSpacing(4);
        gridLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(ImageBrowseWidget);

        QMetaObject::connectSlotsByName(ImageBrowseWidget);
    } // setupUi

    void retranslateUi(QWidget *ImageBrowseWidget)
    {
        ImageBrowseWidget->setWindowTitle(QApplication::translate("ImageBrowseWidget", "MyQtGuiClass", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImageBrowseWidget: public Ui_ImageBrowseWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEBROWSEWIDGET_H
