#pragma once
#ifndef MYLABEL_H
#define MYLABEL_H

#include <QDesktopWidget>
#include <QLabel>
#include <QMouseEvent>
#include "Data/Entity/TW_ReplayEvent.h"

namespace Ui
{
	class MyLabel :public QLabel {
		Q_OBJECT
	public:
		explicit MyLabel(QWidget* parent, const tw_replayevent_ptr&);
		const tw_replayevent_ptr& getReplayEvent()const;
		~MyLabel();
	signals:
		void clicked();
	protected:
		virtual void enterEvent(QEvent *);
		virtual void leaveEvent(QEvent *);
		virtual void mousePressEvent(QMouseEvent*);
		
		void changeCursor();
	private:
		tw_replayevent_ptr replayEvent;
	};
}
#endif // !MYLABEL_H
