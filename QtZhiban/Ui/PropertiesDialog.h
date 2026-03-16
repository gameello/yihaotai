#ifndef PROPERTIESDIALOG_H
#define PROPERTIESDIALOG_H

#include <QWidget>
#include "ModalessDialog.h"
#include "publicinterface_global.h"

namespace Ui {
    class PropertiesDialog;
}

class PUBLICINTERFACE_EXPORT PropertiesDialog : public ModalessDialog
{
    Q_OBJECT
public:
    explicit PropertiesDialog(QWidget *parent = nullptr);

signals:

public slots:

    // QWidget interface
protected:
    virtual void resizeEvent(QResizeEvent *event) override;
};

#endif // PROPERTIESDIALOG_H
