#include "TextString.h"
#include <iostream>

TextString::TextString(const char* str) : Cell(str)
{
	text = str;
}
void TextString::writeToFile(std::fstream& out) const
{
	out << text;
}

void TextString::print() const
{
	std::cout << text << " ";
}