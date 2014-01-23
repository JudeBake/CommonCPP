/**
 * \file DateTime.cpp
 * \brief Implementation of the DateTime class.
 *
 * \date Created on: Jan 20, 2014
 * \date Last change on: &DATE&
 *
 * \author Created by: julien 
 * \author Last change by: &AUTHOR&
 *
 * \version Commit Id: &REVISION&
 */

#include <stdlib.h>
#include "DateTime.h"

namespace CommonCPP
{

DateTime* DateTime::getCurrentDateTime(void)
{
	return new DateTime(time(NULL));
}

DateTime::DateTime()
{
	timeData = 0;
	UTCTime = gmtime(&timeData);
	localTime = localtime(&timeData);
}

DateTime::DateTime(const time_t iTime)
{
	timeData = iTime;
	UTCTime = gmtime(&timeData);
	localTime = localtime(&timeData);
}

DateTime::DateTime(const DateTime& iDateTime)
{
	timeData = iDateTime.timeData;
	UTCTime = gmtime(&timeData);
	localTime = localtime(&timeData);
}

DateTime& DateTime::operator=(DateTime iDateTime)
{
	timeData = iDateTime.timeData;
	UTCTime = gmtime(&timeData);
	localTime = localtime(&timeData);
	return *this;
}

void DateTime::setTime(const time_t iTime)
{
	timeData = iTime;
	UTCTime = gmtime(&timeData);
	localTime = localtime(&timeData);
}

time_t DateTime::getTime(void)
{
	return timeData;
}

size_t DateTime::getFormattedStr(char* oStr, size_t iMaxSize,
								 const char* iFormat, const TimeBase iTimeBase)
{
	size_t charNb = -1;

	switch(iTimeBase)
	{
	case UTC:
		if (UTCTime)
		{
			charNb = strftime(oStr, iMaxSize, iFormat, UTCTime);
		}
		break;
	case LOCAL:
		if (localTime)
		{
			charNb = strftime(oStr, iMaxSize, iFormat, localTime);
		}
		break;
	}

	return charNb;
}

double DateTime::operator-(const DateTime& iDateTime2)
{
	return difftime(iDateTime2.timeData, timeData);
}

DateTime::~DateTime()
{
	free(UTCTime);
	free(localTime);
}

} /* namespace CommonLib */
