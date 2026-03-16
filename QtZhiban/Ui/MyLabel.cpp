#pragma execution_character_set("utf-8")

#include "MyLabel.h"
#include <QMessageBox>
#include "Replay/PlaybackControl.h"
namespace Ui
{
	MyLabel::MyLabel(QWidget* parent, const tw_replayevent_ptr& _replayEvent) :QLabel(parent)
	{
		replayEvent = _replayEvent;
	}

	MyLabel::~MyLabel()
	{

	}

	void MyLabel::enterEvent(QEvent * event)
	{
		/*if (event->type() == QEvent::FocusIn)
		{

		}*/
		this->setCursor(Qt::OpenHandCursor);
	}

	void MyLabel::leaveEvent(QEvent*event)
	{
		this->setCursor(Qt::ArrowCursor);
	}

	void MyLabel::mousePressEvent(QMouseEvent* event)
	{
		//QMessageBox::information(0, QObject::tr("提示"), QObject::tr("程度发生的"), QMessageBox::Ok);
		ReplayManager::instance()->getPlaybackControl()->loadEvent(replayEvent);
	}

	const tw_replayevent_ptr & MyLabel::getReplayEvent() const
	{
		return replayEvent;
	}

	void MyLabel::changeCursor()
	{

	}
}