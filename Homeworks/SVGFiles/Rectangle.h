#pragma once
#pragma warning(disable:4996)
#include<cstring>
#include<fstream>
#include "Line.h"
class Rectangle:public Line
{
public:
	Rectangle(std::ifstream& in);
	Rectangle();
	void setWidth(double width);
	void setHeight(double height);
	const double getWidth();
	const double getHeight();
	void readfromFile(std::ifstream& in);
private:
	
	double m_width;
	double m_height;
	
};

