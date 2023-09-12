
#include "Hdd.h"

Hdd::Hdd(int terabytes, int ReadingSpeed, int WritingSpeed)
{
	this->terabytes = terabytes;
	this->ReadingSpeed = ReadingSpeed;
	this->WritingSpeed = WritingSpeed;
}

Hdd::Hdd()
{
	terabytes = 0;
	ReadingSpeed = 0;
	WritingSpeed = 0;
}

const int Hdd::getTerabytes() 
{
	return terabytes;
}

const int Hdd::getReadingSpeed() 
{
	return ReadingSpeed;
}

const int Hdd::getWritingSpeed() 
{
	return WritingSpeed;
}

std::ifstream& operator>>(std::ifstream& is, Hdd& hdd)
{
	is >> hdd.terabytes >> hdd.ReadingSpeed >> hdd.WritingSpeed;
	return is;
}
