#include "ui/PropertiesDialog.h"
#include <QApplication>
#include <QDesktopWidget>

PropertiesDialog::PropertiesDialog(QWidget *parent) : ModalessDialog(parent)
{
	this->setWindowModality(Qt::NonModal);
}

void PropertiesDialog::resizeEvent(QResizeEvent *event)
{
	Q_UNUSED(event)

    SetMovableArea(QRect(0, 0, width(), 30));

    QDesktopWidget* desktop = QApplication::desktop();
	QRect geometry = desktop->screenGeometry();
    move((geometry.width() - this->width())-30, (geometry.height() - this->height()) / 3);
}
