#pragma once
#include "Component.h"
#include <fstream>
class Hdd :public Component
{
public:
	Hdd(int terabytes, int ReadingSpeed, int WritingSpeed);
	Hdd();
	const int getTerabytes();
	const int getReadingSpeed();
	const int getWritingSpeed();
	friend std::ifstream& operator>>(std::ifstream& is, Hdd& hdd);
private:
	int terabytes;
	int ReadingSpeed;
	int WritingSpeed;
};
