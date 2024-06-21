#include "Intiger.h"

Intiger::Intiger(const char* dig):Cell(dig)
{
	digit = atoi(dig);
	
}

Intiger::Intiger()
{
	digit = 0;
}

void Intiger::writeToFile(std::fstream& out) const
{
	out << digit;
}

void Intiger::print() const
{
	std::cout << digit << " ";
}
