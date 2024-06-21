#pragma once
#include "TypesOfData.h"
#include "Cell.h"
#include <vector>
class Formula: public Cell
{
public:
	Formula(char* formula); //The code which make the constructor is copied 
	virtual double calculate() const;
	double read(char* reader, int& end) const;
	virtual void writeToFile(std::fstream& out)const;

   
private:
	int firstRow, firstCol;
	int secondRow, secondCol;
	char sign;
	double first, second;

};

