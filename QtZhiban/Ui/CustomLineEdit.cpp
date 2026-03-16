#include "ui/CustomLineEdit.h"

#include <QVBoxLayout>

CustomLineEdit::CustomLineEdit(QWidget *parent) : QLineEdit(parent)
{
	toolTipWidget = new QWidget();
	toolTipWidget->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
	QVBoxLayout *layout = new QVBoxLayout();
	layout->setContentsMargins(10, 0, 10, 0);
	tipLabel = new QLabel(toolTipWidget);
	tipLabel->setWordWrap(true);
	toolTipWidget->setStyleSheet("background:#024c87;color:#FFFFFF;font-family:Microsoft YaHei;font-size:14px;");
	layout->addWidget(tipLabel);
	setStyleSheet("QLineEdit{border:1px solid #0175ae;background:#024c87;border-radius:2px;padding:0px 0px 0px 12px; height:26px;color:#FFFFFF;font-family:Microsoft YaHei;font-size:14px;}\
              QLineEdit:hover,QLineEdit:focus{border:1px solid #ffae3b;}\
              QLineEdit:disabled {color: #0175ae;border: 1px solid #0175ae;}");
	toolTipWidget->setLayout(layout);
	toolTipWidget->hide();
}


void CustomLineEdit::enterEvent(QEvent *event)
{
	QLineEdit::enterEvent(event);
	QString content = this->text();
	tipLabel->setText(content);
	content.replace(";", "<br>");
	toolTipWidget->setFixedWidth(this->width());
	// 通过<br>，控制QLabel换行
	tipLabel->setFixedHeight((content.count("<br>")) * 24);
	QPoint pt = mapToGlobal(QPoint(0, 0));
	// 设置提示框的位置
	toolTipWidget->move(pt.x(), pt.y() + this->height());
	toolTipWidget->show();
}

void CustomLineEdit::leaveEvent(QEvent *event)
{
	QLineEdit::leaveEvent(event);
	toolTipWidget->hide();
}
