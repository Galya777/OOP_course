#pragma once
#pragma warning(disable:4996)
#include <fstream>
#include "Rectangle.h"
#include "Line.h"
#include "Circle.h"
#include "Vector.h"
const int MAX_TYPE = 100;
static int THIS_ID = 0;
class Figures
{
public:
	Figures(std::ifstream& in);
	Figures(const char*option, Rectangle& rectangle);
	Figures(const char* option, Line& line);
	Figures(const char* option, Circle& circle);
	Figures(const int size, const char* option);
	Figures();
	void addFigure(const char* option);
	int getNumber();
	void printFigures();
	void removeFigure(int newnumber);
	void translate(int number);
	void printType(char* type);
	Figures* getFig(const char* name) const;

	void serialize(std::ofstream& out);

	bool serialize(const char*filename) const;
	bool deserialize(const char* filename);
private:
	char m_option[MAX_TYPE];
	Rectangle m_rectangle;
	Line l_line;
	Circle c_circle;
	int number;
	Vector<Figures*>figures;
	friend class Line;
};

