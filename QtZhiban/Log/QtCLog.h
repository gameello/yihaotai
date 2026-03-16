#pragma once

#include <QFile>

class  CLog : public QObject
{
    Q_OBJECT
public:

    // 日志等级
    enum CLOG_LEVEL
    {
        INFO,               /*!<    提示  */
        WARNING,            /*!<    警告  */
        ERROR               /*!<    错误  */
    };
    Q_FLAG(CLOG_LEVEL)

        struct LogConfig
    {
        bool isRecord2File;     /*!< 是否记录到文件 */
        int level;              /*!< 记录日志等级，大于等于此level的日志将被记录 */
    };

    CLog();

    void setLogLevel(const CLog::CLOG_LEVEL& level);
    CLog::CLOG_LEVEL getLogLevel() { return logLevel; }

    static bool init(CLog::LogConfig& logConfig);
    static bool createDir(QString dirPath);

    static void log(CLOG_LEVEL nLevel, QString fileDesc, QString functionDesc, int lineNum, QString data, ...);

private:
    static QString getLeveDesc(CLOG_LEVEL level);

private:
    static bool isRecord2File;
    static bool isFileReady;
    static CLOG_LEVEL logLevel;
};

#ifdef Q_OS_WIN
#define FILE_SEPARATOR '\\'
#else
#define FILE_SEPARATOR '/'
#endif

#define FUNC_SEPARATOR '::'

#ifndef QT_NO_DEBUG
#define __FILENAME__ (strrchr(__FILE__, FILE_SEPARATOR) ? (strrchr(__FILE__, FILE_SEPARATOR) + 1):__FILE__)
#define __FUNNAME__ (strrchr(__FUNCTION__,FUNC_SEPARATOR)?(strrchr(__FUNCTION__, FUNC_SEPARATOR) + 1):__FUNCTION__)
#else
#define __FILENAME__ NULL
#define __FUNNAME__ NULL
#endif

#define LOG_INFO(...)       CLog::log(CLog::INFO,__FILENAME__,__FUNNAME__,__LINE__, __VA_ARGS__)
#define LOG_WARNING(...)    CLog::log(CLog::WARNING, __FILENAME__,__FUNNAME__, __LINE__,__VA_ARGS__)
#define LOG_ERROR(...)      CLog::log(CLog::ERROR,__FILENAME__,__FUNNAME__,__LINE__,__VA_ARGS__)
