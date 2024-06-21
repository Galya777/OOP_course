#pragma once
#pragma warning(disable:4996)
#include<cstring>
#include<fstream>
const int MAX_COLOUR1 = 50;
class Line 
{
public:
	Line(std::ifstream& in);
	Line(double x, double y, const char* fill);
	Line();
	void setX(double x);
	void setY(double y);
	void setFill(const char* fill);
	const double getX();
	const double getY();
    const char* getFill();
	void serialize(std::ofstream& file); 
	void deserialize(std::ifstream& file);
	void readfromFile(std::ifstream& in);
protected:
	double l_x;
	double l_y;
	char l_fill[MAX_COLOUR1];
};

