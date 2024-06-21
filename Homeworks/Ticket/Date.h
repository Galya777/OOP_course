#pragma once
#include <fstream>
#include <string>
/**
 * @brief 
 * Represents a date in ISO format
 * 
 * Представя дата в ISO формат
*/
class Date
{
public:
	Date();
	/// Parses string
	Date(std::string str);
	/// Sets day, month and year
	Date(unsigned short day, unsigned short month, unsigned short year);

	/// Returns the day
	unsigned short get_day() const;
	/// Sets the day
	bool set_day(unsigned short day);
	/// Returns the month
	unsigned short get_month() const;
	/// Sets the month
	bool set_month(unsigned short month);
	/// Returns the year
	unsigned short get_year() const;
	/// Sets the year
	bool set_year(unsigned short year);

	/// Returns the date as a String object
	std::string createString() const;

	/// Reads date from stream
	void read(std::istream& istr);
	/// Writes date to stream
	void write(std::ostream& ostr);
	/// Compares two dates
	int compare(const Date& other) const;

private:
	unsigned short day;
	unsigned short month;
	unsigned short year;

	bool isLeapYear();
	unsigned short daysInMonth();
};

/// Reads date from stream with >> operator
std::istream& operator>>(std::istream& istr, Date& dt);
/// Writes date to stream with << operator
std::ostream& operator<<(std::ostream& ostr, const Date& dt);

