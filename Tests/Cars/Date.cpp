#include "Date.h"
#include <iostream>

Date::Date(short day, short month, unsigned short year)
{
	setDay(day);
	setMonth(month);
	setYear(year);
}

Date::Date(const char* date)
{
	if (validDate(date)) {
		this->day = date[0]*10 + date[1];
		this->month = date[3] * 10 + date[4];
		this->year = date[6] * 10000 + date[7]*100+ date[8]*10+ date[9];

	}
	else {
		throw "Invalid date!";
	}
}

Date::Date()
{
	setDay(0);
	setMonth(0);
	setYear(0);
}

void Date::setDay(short day)
{
	if (day <= 31) {
		this->day = day;
	}
	else {
		throw "Invalid date!";
	}
}

void Date::setMonth(short month)
{
	if (month <= 15) {
		this->month = month;
	}
	else {
		throw "Invalid date!";
	}
}

void Date::setYear(short year)
{
	if (year <= 63) {
		this->year = year;
	}
	else {
		throw "Invalid date!";
	}
}

short Date::getDay() const
{
	return day;
}

short Date::getMonth() const
{
	return month;
}

unsigned short Date::getYear() const
{
	return year;
}

void Date::print()
{
	std::cout << day << "/" << month << "/" << year;
}

void Date::print(std::ofstream& out)
{
	out << day << "/" << month << "/" << year;
}

void Date::readFromFile(std::ifstream& in)
{
	in >> day >> month >> year;
}



bool Date::validDate(const char* date)
{
	if (strlen(date) != 10)
		return false;

	for (size_t i = 0; i < strlen(date); i++)
	{

	}
	return true;
}
