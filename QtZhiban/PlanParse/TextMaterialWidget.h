#pragma once

#include <QWidget>
#include "ui_TextMaterialWidget.h"
#include "ui/ModalDialog.h"

namespace Ui {
	class TextMaterialWidget;
}
class TextMaterialWidget : public ModalDialog
{
	Q_OBJECT

public:
	TextMaterialWidget(QWidget *parent = Q_NULLPTR);
	~TextMaterialWidget();
	void InitWidget();

	void setFileName(QString &name);
	void setEditText(QString &content);

public slots:
	void addTextMaterial();

signals:
	void addTextItem(QString &name);

private:
	Ui::TextMaterialWidget *ui;
};
