#include "CheckBoxHeaderView.h"
#include <QStyleOptionButton>
#include <QMouseEvent>
#include <QPixMap>

CheckBoxHeaderView::CheckBoxHeaderView(int index, Qt::Orientation orientation, QWidget *parent,QString text,int w, int l)
	: QHeaderView(orientation, parent), m_checked(false), m_index(index),str(text),width(w),left(l)
{
}

CheckBoxHeaderView::~CheckBoxHeaderView()
{
}

void CheckBoxHeaderView::paintSection(QPainter *painter, const QRect &rect, int logicalIndex) const
{
	painter->save();
	QHeaderView::paintSection(painter, rect, logicalIndex);
	painter->restore();

	if (logicalIndex == m_index)
	{
		QStyleOptionButton option;
		option.text = str;
		if(left==0) option.rect = QRect((sectionSize(0) - 16) / 2, 3, width, 21);
		else option.rect = QRect(left, 3, width, 21);
		QRect boxRect(option.rect.topLeft(), QSize(22, 22));
		QRect txtRect(boxRect.right() + 5, 3, width, 21);

		if (m_checked)
		{
			//option.state = QStyle::State_On;
			this->style()->drawItemPixmap(painter, boxRect, Qt::AlignCenter, QPixmap(":/images/checked.png"));
		}
		else
		{
			//option.state = QStyle::State_Off;
			this->style()->drawItemPixmap(painter, boxRect, Qt::AlignCenter, QPixmap(":/images/unchecked.png"));
		}
		//this->style()->drawControl(QStyle::CE_CheckBox, &option, painter);
		this->style()->drawItemText(painter, txtRect, Qt::AlignLeft, QPalette(Qt::black), true, str);
	}
}

void CheckBoxHeaderView::mousePressEvent(QMouseEvent *e)
{
	if (visualIndexAt(e->pos().x()) == m_index)
	{
		m_checked = !m_checked;
		updateSection(m_index);

		emit checkStatusChanged(m_checked);
	}

	QHeaderView::mousePressEvent(e);
}
