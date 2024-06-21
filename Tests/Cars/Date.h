#pragma once
#pragma warning(disable:4996)
#include <fstream>
class Date
{
public:
	Date(short day, short month, unsigned short year);
	Date(const char* date);
	Date();


	void setDay(short day);
	void setMonth(short month);
	void setYear(short year);

	short getDay() const;
	short getMonth() const;
	unsigned short getYear() const;

	void print();
	void print(std::ofstream& out);

   void readFromFile(std::ifstream& in);

private:
	short day;
	short month;
	unsigned short year;

	bool validDate(const char* date);
	
};

