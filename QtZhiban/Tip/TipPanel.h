#pragma once

#include <QWidget>
#include <QStyleOption>
#include <QTimer>
#include <QMovie>
#include "ui_TipPanel.h"

class TipPanel : public QWidget
{
	Q_OBJECT

public:
	TipPanel(QWidget *parent = Q_NULLPTR);
	~TipPanel();

	static TipPanel * instance(QWidget *parent = nullptr);
	static void success(QString text, int timeout = 2000);
	static void failed(QString text, int timeout = 2000);
	static void progress(QString text, int timeout = 2000);
	static void hidePanel();

protected:
	virtual void paintEvent(QPaintEvent *event) override;
	virtual void resizeEvent(QResizeEvent *event) override;

	void setMessage(QString message);

	static void startTimer(int timeout);

private:
	Ui::TipPanel ui;

	QStyleOption *opt;

	QWidget *m_pParent;
	static TipPanel *m_pInstance;
	static QTimer *m_pTimer;
	QMovie *m_pMovie;
};
