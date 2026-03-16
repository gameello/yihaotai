#include "MessageTipService.h"
#include "tip/MessagePanel.h"
#include "tip/MessageDialog.h"
#include "tip/TipPanel.h"

MessageTipService* MessageTipService::_instance = nullptr;
MessageTipService::MessageTipService()
{
}

MessageTipService::~MessageTipService()
{
}

MessageTipService *MessageTipService::instance()
{
    if (_instance == nullptr) {
        _instance = new MessageTipService();
    }
    return _instance;
}

void MessageTipService::showMessage(QString text, MessageType messageType /*= MT_WARN*/, int timeout /*= 5000*/)
{
	switch (messageType)
	{
	case MT_INFO:
		MessagePanel::info(text, timeout);
		break;
	case MT_WARN:
		MessagePanel::warn(text, timeout);
		break;
	case MT_ERROR:
		MessagePanel::error(text, timeout);
		break;
	}
}

int MessageTipService::showDialog(QString text, DialogType dialogType)
{
	return MessageDialog::warn(text);
}

void MessageTipService::showTip(QString text, TipType tipType, int timeout)
{
	switch (tipType)
	{
	case TT_PROCESS:
		TipPanel::progress(text, timeout);
		break;
	case TT_SUCESS:
		TipPanel::success(text, timeout);
		break;
	case TT_FAILED:
		TipPanel::failed(text, timeout);
		break;
	default:
		break;
	}
}

void MessageTipService::hideMessage()
{
	MessagePanel::hidePanel();
}

void MessageTipService::hideTip()
{
	TipPanel::hidePanel();
}

