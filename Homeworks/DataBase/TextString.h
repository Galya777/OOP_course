#pragma once
#include <cstring>
#include <string>
#include "Cell.h"
class TextString:public Cell
{
public:
	TextString(const char* str);

	virtual void writeToFile(std::fstream& out) const;
	virtual void print() const;
private:
	std::string text;
};