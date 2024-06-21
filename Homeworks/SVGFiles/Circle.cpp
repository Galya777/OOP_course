#include "Circle.h"


Circle::Circle(std::ifstream& in)
{
	in.read((char*)&l_x, sizeof(l_x));
	in.read((char*)&l_y, sizeof(l_y));
	in.read((char*)&radius, sizeof(radius));
	in.read(l_fill, sizeof(l_fill));
	

}

Circle::Circle()
{
	l_x = 0;
	l_y = 0;
	radius = 0;
	strcpy(l_fill, "");
}

void Circle::setRadius(double radius)
{
	radius = radius;
}

const double Circle::getRadius()
{
	return radius;
}

void Circle::readfromFile(std::ifstream& in)
{
	in.read((char*)&l_x, sizeof(l_x));
	in.read((char*)&l_y, sizeof(l_y));
	in.read((char*)&radius, sizeof(radius));
	in.read((char*)&l_fill, sizeof(l_fill));
}

