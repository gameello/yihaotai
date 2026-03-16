#pragma once

#include <QWidget>
#include <QStyleOption>
#include <QTimer>
#include "ui_MessagePanel.h"

class MessagePanel : public QWidget
{
	Q_OBJECT

public:
	MessagePanel(QWidget *parent = Q_NULLPTR);
	~MessagePanel();

	static MessagePanel * instance(QWidget *parent=nullptr);
	static void info(QString text, int timeout = 5000);
	static void warn(QString text, int timeout = 5000);
	static void error(QString text, int timeout = 5000);
	static void hidePanel();

signals:
	void doubleClicked();

protected:
	virtual void paintEvent(QPaintEvent *event) override;
	virtual void resizeEvent(QResizeEvent *event) override;
	virtual void mouseDoubleClickEvent(QMouseEvent *event) override;

	void setMessage(QString message);
	static void startTimer(int timeout);

private:
	Ui::MessagePanel ui;
	QStyleOption *opt;

	QWidget *parent;
	static MessagePanel *m_pInstance;
	static QTimer *m_pTimer;
};
