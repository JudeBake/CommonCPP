/**
 * \file DateTime.h
 * \class CommonCPP::DateTime
 * \brief Representation of a date/time.
 *
 * This class is the representation of a date/time value.It actually wraps the
 * standard C time module as point in the human time line. It also provides a
 * static method to get the current date/time.
 *
 * \date Created on: Jan 20, 2014
 * \date Last change on: &DATE&
 *
 * \author Created by: julien 
 * \author Last change by: &AUTHOR&
 *
 * \version Commit Id: &REVISION&
 */

#ifndef DATETIME_H_
#define DATETIME_H_

#include <ctime>

namespace CommonCPP
{

class DateTime
{
public:
	/**
	 * \enum TimeBase
	 * \brief The time base constant used for getting a formatted strig.
	 *
	 * The choices are:
	 * - UTC: time base UTC.
	 * - LOCAL: time base local (system setting dependent).
	 */
	typedef enum
	{
		UTC,
		LOCAL
	} TimeBase;

private:
	time_t timeData;
	struct tm UTCTime;
	struct tm localTime;

public:
	/**
	 * \brief Static method the get the current date/time from the system.
	 *
	 * \return Pointer to a new DateTime reference initialized to the current
	 * system date/time.
	 */
	static DateTime* getCurrentDateTime(void);

	/**
	 * \brief Basic DateTime constructor.
	 *
	 * The DateTime is initialized at 00:00:00 1970/01/01.
	 */
	DateTime(void);

	/**
	 * \brief DateTime constructor with a given time.
	 *
	 * \param iTime The given time to which initialize the DateTime.
	 */
	DateTime(const time_t iTime);

	/**
	 * \brief DateTime copy constructor.
	 *
	 * \param iDateTime The reference DateTime from which to initialize.
	 */
	DateTime(const DateTime& iDateTime);

	/**
	 * \brief DateTime assignment operator.
	 *
	 * \param iDateTime The DateTime to copy.
	 *
	 * \return A new DateTime reference.
	 */
	DateTime& operator=(DateTime iDateTime);

	/**
	 * \brief DateTime time setter.
	 *
	 * \param iTime The time value from which to set the time.
	 */
	void setTime(const time_t iTime);

	/**
	 * \brief DateTime time getter.
	 *
	 * \return The time value of DateTime.
	 */
	time_t getTime(void);

	/**
	 * \brief DateTime string formatter.
	 *
	 * \param oStr Pointer to the destination char array.
	 * \param iMaxSize The maximal length of the output string (\0 included).
	 * \param iFormat The format of the desired string (see strftime from ctime).
	 * \param iTimeBase The time base from which to compute the string (see TimeBase enum).
	 *
	 * \return The number of character in the formatted string (\0 not included).
	 * 0 if the string was to long to fit max size and -1 if bad time base is used
	 * or was unable to format the string.
	 */
	size_t getFormattedStr(char* oStr, size_t iMaxSize, const char* iFormat,
						   const TimeBase iTimeBase);

	/**
	 * \brief DateTime operator -. Give the difference between two DateTime.
	 *
	 * \param iDateTime2 The DateTime reference that serve as second operand.
	 *
	 * \return The number of second between the to operands as a double.
	 */
	double operator-(const DateTime& iDateTime2);

	/**
	 * \brief Destructor of DateTime class.
	 */
	virtual ~DateTime();
};

} /* namespace CommonCPP */

#endif /* DATETIME_H_ */
