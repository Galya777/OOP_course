#pragma once
#include "Cell.h"
class DoubleNumber: public Cell
{
public:
	DoubleNumber(const char* doub);

	virtual void writeToFile(std::fstream& out) const;
	virtual void print() const;
private:
	 double digit;
};

