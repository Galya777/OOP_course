#include "Color.h"

Color::Color(int red, int green, int blue)
{
  setRED(red);
  setGREEN(green);
  setBLUE(blue);
}

Color::Color()
{
	setRED(0);
	setGREEN(0);
	setBLUE(0);
}

Color& Color::operator=(const Color& other)
{
	red = other.red;
	green = other.green;
	blue = other.blue;
	return *this;
	// TODO: insert return statement here
}

int Color::getRed() const
{
	return red;
}

int Color::getGren() const
{
	return green;
}

int Color::getBlue() const
{
	return blue;
}

void Color::setRED(int value)
{
	try {
		if (value >= 0 && value <= 255) {
			red = value;
		}
		else {
			throw value;
		}
	}
	catch (int value) {
		std::cout << "Wrong value!";
	}
}

void Color::setGREEN(int value)
{
	try {
		if (value >= 0 && value <= 255) {
			green = value;
		}
		else {
			throw value;
		}
	}
	catch (int value) {
		std::cout << "Wrong value!";
	}
}

void Color::setBLUE(int value)
{
	try {
		if (value >= 0 && value <= 255) {
			blue = value;
		}
		else {
			throw value;
		}
	}
	catch (int value) {
		std::cout << "Wrong value!";
	}
}

bool Color::isWhite() const
{
	if (red == 255 && green == 255 && blue == 255) {
		return true;
	}
	return false;
}

bool Color::isGrey() const
{
	///rgb(128, 128, 128) is the color code of grey in RGB 
	if (red == 128 && green == 128 && blue == 128) {
		return true;
	}
	return false;
}

Color& Color::operator-(int value)
{
	red -= value;
	blue -= value;
	green -= value;
	return *this;
	// TODO: insert return statement here
}

bool Color::operator>(int value)
{
	if (red > value && green > value && blue > value) {
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& out, Color& other)
{
	out << other.red << other.green << other.blue;
	return out;
	// TODO: insert return statement here
}
