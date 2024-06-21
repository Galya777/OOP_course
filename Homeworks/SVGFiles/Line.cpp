#include "Line.h"

#include <iostream>

Line::Line(std::ifstream& in)
{
	in.read((char*)&l_x, sizeof(l_x));
	in.read((char*)&l_y, sizeof(l_y));
	in.read(l_fill, sizeof(l_fill));
}

Line::Line(double x, double y, const char* fill)
{
	l_x = x;
	l_y = y;
	strcpy(l_fill, fill);
}
Line::Line() {
	l_x = 0;
	l_y = 0;
	strcpy(l_fill, "");
}
void Line::setX(double x)
{
	l_x = x;
}

void Line::setY(double y)
{
	l_y = y;
}

void Line::setFill(const char* fill)
{
	strcpy(l_fill, fill);
}

const double Line::getX()
{
	return l_x;
}

const double Line::getY()
{
	return l_y;
}

const char* Line::getFill()
{
	return l_fill;
}

void Line::serialize(std::ofstream& file)
{
	file.write((const char*)&l_x,sizeof(l_x));
	file.write((const char*)&l_y, sizeof(l_y));
	int fill_lenght = strlen(l_fill);
	file.write((const char*)l_fill,sizeof(fill_lenght));
}

void Line::deserialize(std::ifstream& file)
{
	file.read((char*)&l_x, sizeof(l_x));
	file.read((char*)&l_y, sizeof(l_y));
	int fill_lenght = strlen(l_fill);
	file.read((char*)l_fill, sizeof(fill_lenght));

}

void Line::readfromFile(std::ifstream& in)
{
	in.read((char*)&l_x, sizeof(l_x));
	in.read((char*)&l_y, sizeof(l_y));
	in.read((char*)&l_fill, sizeof(l_fill));
}
