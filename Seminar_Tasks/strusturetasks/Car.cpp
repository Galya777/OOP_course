#include "Car.h"
#include <cstring>
#include <iostream>
#pragma warning(disable : 4996)
Car::Car(const char* brand, const char* colour, int reginumber)
{
	init(brand, colour, reginumber);
}

Car::Car()
{
	init("", "", 0);
}

Car::Car(const Car& other)
{
	copy(other);
}

Car& Car::operator=(const Car& other)
{
	if (this != &other) {
		del();
		copy(other);
	}
	return *this;
}

Car::~Car()
{
	del();
}

char* Car::getbrand()
{
	return Car::m_brand;
}

char* Car::getcolour()
{
	return m_colour;
}

int Car::getnumber()
{
	return m_reginumber;
}

void Car::setbrand(const char* brand)
{
	delete[] m_brand;
	m_brand = new char[strlen(brand) + 1];
	strcpy(m_brand, brand);
}

void Car::setnumber(int number)
{
	m_reginumber = number;
}

bool Car::isvalid()
{
	if (m_reginumber<1000 && m_reginumber > 10000) {
		return false;
	} 
	return true;
}

void Car::print()
{
	std::cout << m_brand << m_colour << m_reginumber << std::endl;
}


void Car::init(const char* brand, const char* colour, int reginumber)
{
	m_brand = new char[strlen(brand) + 1];
	strcpy(m_colour, colour);
	m_reginumber = reginumber;
}

void Car::copy(const Car& other)
{
	m_brand = new char[strlen(other.m_brand) + 1];
	strcpy(m_colour, other.m_colour);
	m_reginumber = other.m_reginumber;
}

void Car::del()
{
	delete[] m_brand;
}
