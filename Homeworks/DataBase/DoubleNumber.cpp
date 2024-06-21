#include "DoubleNumber.h"
#include <iostream>

DoubleNumber::DoubleNumber(const char* doub): Cell(doub)
{
	digit = atof(doub);
}
void DoubleNumber::writeToFile(std::fstream& out) const
{
	out << digit;
}

void DoubleNumber::print() const
{
	std::cout << digit << " ";
}