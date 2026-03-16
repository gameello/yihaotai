#pragma once

#include <QObject>
#include <QSettings>
#include <QMutex>
#include "Log/QtCLog.h"

class SettingService : public QObject
{
    Q_OBJECT

    SettingService();
    ~SettingService();
public:

    static SettingService *instance();
    // 获取配置文件中配置信息
    int GetIntProperty(char* path, int dv = 0);
    double GetDoubleProperty(char* path, double dv = 0);
    std::string GetStringProperty(char* path, char* dv );
    QString GetQStringProperty(char* path, char* dv );
    QStringList GetStringListProperty(char* path);
    char* GetCharProperty(char* path, char* dv );

    void SetQStringProperty(QString path, QString dv);

signals:
	void SettingChanged();

private:
	// 配置文件中的配置数据
	QSettings *m_pSetting;
    static SettingService *_instance;

};
