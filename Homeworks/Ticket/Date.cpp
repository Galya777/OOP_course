#include "Date.h"

bool Date::isLeapYear()
{
    return year % 400 == 0 || year % 100 != 0 || year % 4 == 0;
}

unsigned short Date::daysInMonth()
{
	if (month == 2)
		return 28 + isLeapYear();
	if (month <= 7)
		return 30 + month % 2;
	return 31 - month % 2;
}

Date::Date(): Date(01, 01, 2022)
{
}

Date::Date(std::string str)
{
	const char* strToDevide = str.c_str();
	while (*strToDevide == ' ' && *strToDevide != '\0') strToDevide++;
	set_day(atoi(strToDevide));
	str += 2;
	while (*strToDevide == ' ' && *strToDevide != '\0') strToDevide++;
	set_month(atoi(strToDevide));
	str += 2;
	while (*strToDevide == ' ' && *strToDevide != '\0') strToDevide++;
	set_year(atoi(strToDevide));
	delete[] strToDevide;
}

Date::Date(unsigned short day, unsigned short month, unsigned short year)
{
	this->day = this->month = this->year = 0;
	set_day(day);
	set_month(month);
	set_year(year);
}

unsigned short Date::get_day() const
{
	return day;
}

bool Date::set_day(unsigned short day)
{
	if (day == 0 || day > daysInMonth())
		return false;
	this->day = day;
	return true;
}

unsigned short Date::get_month() const
{
	return month;
}

bool Date::set_month(unsigned short newMonth)
{
	if (newMonth == 0 || newMonth > 12)
		return false;
	this->month = newMonth;
	return true;
}

unsigned short Date::get_year() const
{
	return year;
}

bool Date::set_year(unsigned short year)
{
	if (year == 0)
		return false;
	this->year = year;
	return true;
}

std::string Date::createString() const
{
	std::string out = "";
	return ((((out += day) += ".") += month) += ".") += year;
}

void Date::read(std::istream& istr)
{
	istr.read((char*)&day, sizeof(day));
	istr.read((char*)&month, sizeof(month));
	istr.read((char*)&year, sizeof(year));
}

void Date::write(std::ostream& ostr)
{
	ostr.write((char*)&day, sizeof(day));
	ostr.write((char*)&month, sizeof(month));
	ostr.write((char*)&year, sizeof(year));
}

int Date::compare(const Date& other) const
{
	if (year < other.year || month < other.month || day < other.day)
		return -1;
	return year > other.year || month > other.month || day > other.day;
}

std::istream& operator>>(std::istream& istr, Date& dt)
{
	unsigned short d, M, y;
	istr >> d >> M >> y;
	dt = Date(d, M, y);
	return istr;
	// TODO: insert return statement here
}

std::ostream& operator<<(std::ostream& ostr, const Date& dt)
{
	ostr << dt.get_day() << "." << dt.get_month() << "." << dt.get_year();
	return ostr;
	// TODO: insert return statement here
}
