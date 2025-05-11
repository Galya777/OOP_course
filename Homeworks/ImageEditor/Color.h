#pragma once
#include <fstream>
#include <iostream>
/*
* this class represents a color in RGB.
* The color is shown by numbers from 0 to 255 of every of three main colors of RGB
*/
class Color
{
public:
	/// constructor 
	Color(int red, int green, int blue);
	/// default value: creates black 
	Color();

	///operator for checking if two colors are equal
	Color& operator=(const Color& other);

	///getters
	int getRed() const;
	int getGren() const;
	int getBlue() const;
	///setters 
   void setRED(int value);
   void setGREEN(int value);
   void setBLUE(int value);
	
	/// returns true if it is a white colour
	bool isWhite() const;
	/// returns true if it is a grey colour
	bool isGrey() const;

	/// substracts value to every colour value in RGB
	Color& operator-(int value);

	/// compares every colour to a given value
	bool operator>(int value);

	friend std::ostream& operator<<(std::ostream& out, Color& other);

private:
	int red;
	int green;	
	int blue;
};
/// output operator for a RGB pixel
std::ostream& operator<<(std::ostream& out, Color& other);