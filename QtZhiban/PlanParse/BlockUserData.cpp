#include "PlanParse/BlockUserData.h"

BlockUserData::BlockUserData(const QString& info)
	:info_(info)
{
}

BlockUserData::~BlockUserData()
{
}

QString BlockUserData::getInfo() const
{
	return info_;
}
