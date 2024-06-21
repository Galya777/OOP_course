#pragma once
#pragma warning(disable:4996)
#include<cstring>
#include <fstream>
#include "Line.h"
class Circle :public Line
{
public:
	Circle(std::ifstream& in);
	Circle();
	void setRadius(double radius);
	const double getRadius();
	void readfromFile(std::ifstream& in);
private:
	double radius;
};

