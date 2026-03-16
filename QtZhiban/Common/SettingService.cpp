
#include <QCoreApplication>
#include <QDebug>
#include <QTextCodec>
#include "SettingService.h"
#include <QFileInfo>

SettingService* SettingService::_instance = nullptr;
SettingService* SettingService::instance() {
    if (_instance == nullptr) {
        _instance = new SettingService();
    }
    return _instance;
}

SettingService::SettingService() {
    // 初始化配置文件
    QString configPath = qApp->applicationDirPath() + "/config/config.ini";
    QFileInfo configFile(configPath);
    if (!configFile.exists()) {
        LOG_ERROR(QString::fromLocal8Bit("配置文件不存在！"));
        qDebug() << "配置文件不存在！";
        return;
    }
    m_pSetting = new QSettings(configPath, QSettings::IniFormat);
    m_pSetting->setIniCodec(QTextCodec::codecForName("UTF-8"));


    // 注册日志服务
    //context->registerService<SettingService>(this);
}

SettingService::~SettingService() {

}

int SettingService::GetIntProperty(char* path, int dv)
{
    QVariant v = m_pSetting->value(path);
    if (v.isValid()) {
        return v.toInt();
    }
    return dv;
}

double SettingService::GetDoubleProperty(char* path, double dv)
{
    QVariant v = m_pSetting->value(path);
    if (v.isValid()) {
        return v.toDouble();
    }
    return dv;
}

std::string SettingService::GetStringProperty(char* path, char* dv /*= ""*/)
{
    return GetCharProperty(path, dv);
}

QString SettingService::GetQStringProperty(char* path, char* dv /*= ""*/)
{
    return QString(GetCharProperty(path, dv));
}

QStringList SettingService::GetStringListProperty(char* path)
{
    QVariant v = m_pSetting->value(path);
    if (v.isValid()) {
        return v.toStringList();
    }
    return QStringList();
}

char* SettingService::GetCharProperty(char* path, char* dv /*= ""*/)
{
    char* data = dv;

    QVariant v = m_pSetting->value(path);
    if (v.isValid()) {
        data = new char[v.toString().toLocal8Bit().size()];
        strcpy(data, v.toString().toLocal8Bit().data());
    }

    return data;
}

void SettingService::SetQStringProperty(QString path, QString dv)
{
    m_pSetting->setValue(path, dv);
}
