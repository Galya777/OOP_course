#pragma once
#include "Cell.h"
#include <fstream>
#include <iostream>
class Intiger: public Cell
{
public:
	Intiger(const char* dig);
	Intiger();

	virtual void writeToFile(std::fstream& out) const;
	virtual void print() const;


private:
	unsigned int digit;
	
};

