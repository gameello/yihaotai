#pragma once

#include <QObject>
#include <QtPlugin>

enum MessageType {
    MT_WARN,
    MT_INFO,
    MT_ERROR
};

enum TipType
{
    TT_PROCESS,
    TT_SUCESS,
    TT_FAILED
};

enum DialogType
{
    DT_INFO,
    DT_WARN,
    DT_ERROR
};


class MessageTipService : public QObject
{
	Q_OBJECT

public:
    MessageTipService();
    ~MessageTipService();
    static MessageTipService *instance();

    void showMessage(QString text, MessageType messageType = MT_WARN, int timeout = 5000) ;
    void hideMessage() ;
    int showDialog(QString text, DialogType dialogType) ;
    void showTip(QString text, TipType tipType = TT_SUCESS, int timeout = 2000) ;
    void hideTip() ;

private:
    static MessageTipService *_instance;
};
