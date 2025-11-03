#pragma once
#include "MyString.h"
class Vehicle
{
public:
	Vehicle(const char* registration, const char* description, std::size_t space);
	void setReg(const char* registration);
	void setDesc(const char* description);
	void setPlace(const std::size_t place);
	const char* registration() const;
	const char* description() const;
	std::size_t space() const;

private:
	MyString v_registration;
	MyString v_description;
	std::size_t v_parkingPlaces;
	
};

