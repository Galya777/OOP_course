#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(std::ifstream& in)
{
	
	in.read((char*)&l_x, sizeof(l_x));
	in.read((char*)&l_y, sizeof(l_y));
	in.read((char*)&m_width, sizeof(m_width));
	in.read((char*)&m_height, sizeof(m_height));
	in.read(l_fill, sizeof(l_fill));
}

Rectangle::Rectangle()
{
	l_x = 0;
	l_y = 0;
	m_height = 0;
	m_width = 0;
	strcpy(l_fill, "");
}

void Rectangle::setWidth(double width)
{
	m_width = width;
}

void Rectangle::setHeight(double height)
{
	m_height = height;
}



const double Rectangle::getWidth()
{
	return m_width;
}

const double Rectangle::getHeight()
{
	return m_height;
}

void Rectangle::readfromFile(std::ifstream& in)
{
	in.read((char*)&l_x, sizeof(l_x));
	in.read((char*)&l_y, sizeof(l_y));
	in.read((char*)&m_height, sizeof(m_height));
	in.read((char*)&m_width, sizeof(m_width));
	in.read((char*)&l_fill, sizeof(l_fill));
}
