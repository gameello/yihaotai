#pragma once

#include <QHeaderView>
#include <QPainter>
#include <QRect>

class CheckBoxHeaderView : public QHeaderView
{
	Q_OBJECT

public:
	CheckBoxHeaderView(int index, Qt::Orientation orientation, QWidget *parent=nullptr,QString text="",int w=21, int l=0);
	~CheckBoxHeaderView();

signals:
	void checkStatusChanged(bool checked);

protected:
	virtual void paintSection(QPainter *painter, const QRect &rect, int logicalIndex) const override;
	virtual  void mousePressEvent(QMouseEvent *e) override;
private:
	bool m_checked;
	int m_index;
	QString str;
	int width;
	int left;
};

