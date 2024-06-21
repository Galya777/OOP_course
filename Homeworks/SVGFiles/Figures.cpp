#include "Figures.h"
#include "Rectangle.h"
#include"Line.h"
#include <iostream>
#include<fstream>
#include<cstring>
Figures::Figures(std::ifstream& in)
{
	while (!in.eof()) {
		in.getline(m_option, sizeof(m_option));
		if (strcmp(m_option, "rectangle") == 0|| strcmp(m_option, "rect") == 0) {
			m_rectangle.readfromFile(in);
			figures.push_back(new Figures(m_option, m_rectangle));
		} if (strcmp(m_option, "line") == 0) {
			l_line.readfromFile(in);
			figures.push_back(new Figures(m_option, l_line));
		} if (strcmp(m_option, "circle") == 0) {
			c_circle.readfromFile(in);
			figures.push_back(new Figures(m_option, c_circle));
		}
		
	}
}
Figures::Figures(const char* option, Rectangle& rectangle)
{
	strcpy(m_option, option);
	m_rectangle.setX(rectangle.getX());
	m_rectangle.setY(rectangle.getY());
	m_rectangle.setWidth(rectangle.getWidth());
	m_rectangle.setHeight(rectangle.getHeight());
	m_rectangle.setFill(rectangle.getFill());
}

Figures::Figures(const char* option, Line& line)
{
	strcpy(m_option, option);
	l_line.setX(line.getX());
	l_line.setY(line.getY());
	l_line.setFill(line.getFill());
}

Figures::Figures(const char* option, Circle& circle)
{
	strcpy(m_option, option);
	c_circle.setX(circle.getX());
	c_circle.setY(circle.getY());
	c_circle.setRadius(circle.getRadius());
	c_circle.setFill(circle.getFill());
}

Figures::Figures(const int size, const char* option)
{
	strcpy(m_option, option);
	this->number = THIS_ID;
	THIS_ID++;
}

Figures::Figures()
{
	strcpy(m_option, "");
}

void Figures::addFigure(const char* option)
{
	double x, y, width, length, radius;
	char fill[MAX_COLOUR1];
	strcpy(m_option, option);
	if (strcmp(option,"rectangle") == 0) {
		std::cin >> x >> y >> width >> length >> fill;
		m_rectangle.setX(x);
		m_rectangle.setY(y);
		m_rectangle.setWidth(width);
		m_rectangle.setHeight(length);
		m_rectangle.setFill(fill);
		figures.push_back(new Figures(option, m_rectangle));
	}
	if (strcmp(option, "line") == 0) {
		std::cin >> x >> y >> fill;
		l_line.setX(x);
		l_line.setY(y);
		l_line.setFill(fill);
		figures.push_back(new Figures(option, l_line));
		
	}
	if (strcmp(option, "circle") == 0) {
		std::cin >> x >> y >> radius >> fill;
		c_circle.setX(x);
		c_circle.setY(y);
		c_circle.setRadius(radius);
		c_circle.setFill(fill);
		figures.push_back(new Figures(option, c_circle));
	}
	number++;
}

int Figures::getNumber()
{
	return number;
}


void Figures::printFigures()
{
	for (int i = 0; i < figures.size(); i++) {
		std::cout << figures.at(i)->m_option<<" ";
		if (strcmp(figures.at(i)->m_option, "line") == 0) {
			std::cout << figures.at(i)->l_line.getX()<< " "<< figures.at(i)->l_line.getY()<<" "<< figures.at(i)->l_line.getFill()<< std::endl;
		}if (strcmp(figures.at(i)->m_option, "rectangle") == 0) {
			std::cout << figures.at(i)->m_rectangle.getX() << " " << figures.at(i)->m_rectangle.getY() << " " << figures.at(i)->m_rectangle.getHeight()<<" "<< figures.at(i)->m_rectangle.getWidth()<<" "<< figures.at(i)->m_rectangle.getFill() << std::endl;
		}if (strcmp(figures.at(i)->m_option, "circle") == 0) {
			std::cout << figures.at(i)->c_circle.getX() << " " << figures.at(i)->c_circle.getY() << " " << figures.at(i)->c_circle.getRadius() << " " << figures.at(i)->c_circle.getFill() << std::endl;
		}
	}
}

void Figures::removeFigure(int newnumber)
{
	 figures.erase(newnumber);
}

void Figures::translate(int number)
{
	double x, y;
		if (figures.at(number)!=0) {
			std::cin >> x>> y;
			std::swap(x, y);
			std::cout << "Figure "<<number<<" translated!"<<std::endl;
		} else {
			std::cin >> x >> y;
				std::swap(x, y);
			
			std::cout << "All figures are translated!"<<std::endl;
		}
}

void Figures::printType(char* type)
{
	for (int i = 0; i < figures.size(); i++) {
		if (strcmp(figures.at(i)->m_option,type)==0) {
			std::cout << getFig(type)<<std::endl;
		}
	}
}

Figures* Figures::getFig(const char* option) const
{
	for (size_t i = 0; i < figures.size(); i++)
		if (strcmp(option, figures.at(i)->m_option) == 0)
			return figures.at(i);

	return nullptr;
}

void Figures::serialize(std::ofstream& out)
{
	out.write((const char*)m_option, sizeof(m_option));
	if (strcmp(m_option, "rectangle") == 0) {
		m_rectangle.serialize(out);
	} if (strcmp(m_option, "line") == 0) {
		l_line.serialize(out);
	} if (strcmp(m_option, "circle") == 0) {
		c_circle.serialize(out);
	}
}

bool Figures::serialize(const char*filename) const
{
	std::ofstream out(filename);

	if (!out) {
		std::cout << "Cannot open " << filename << " file for writing!" << std::endl;
		return false;
	}

	size_t len = figures.size();
	out.write((const char*)&len, sizeof(len));
	for (size_t i = 0; i < len; i++)
		figures[i]->serialize(out);

	out.close();
	return true;
}

bool Figures::deserialize(const char* filename) 
{
	std::ifstream in(filename);
	if (!in)
		return false;

	for (size_t i = 0; i < figures.size(); i++) {
		figures.push_back(new Figures(in));
	}
	in.close();
	return true;
}
