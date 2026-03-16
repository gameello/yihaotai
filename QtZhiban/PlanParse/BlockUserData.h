#pragma once

#include <QObject>
#include <QTextBlockUserData>

class BlockUserData : public QTextBlockUserData
{
public:
	BlockUserData(const QString& info);
	~BlockUserData();

	QString getInfo() const;

private:
	QString info_;
};
