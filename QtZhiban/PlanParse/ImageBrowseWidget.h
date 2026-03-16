#pragma once

#include <QWidget>
#include "ui_ImageBrowseWidget.h"

namespace Ui {
	class ImageBrowseWidget;
}

class ImageBrowseWidget : public QWidget
{
	Q_OBJECT

public:
	explicit ImageBrowseWidget(QString & path, QWidget *parent = nullptr);
	~ImageBrowseWidget();
	void InitWidget();

protected:
	// 重写鼠标双击事件
	void mouseDoubleClickEvent(QMouseEvent *event) override;

signals:
	// 定义自定义的双击信号
	void doubleClicked(QString path);

private:
	Ui::ImageBrowseWidget *ui;
	QString m_ImagePath;
};
