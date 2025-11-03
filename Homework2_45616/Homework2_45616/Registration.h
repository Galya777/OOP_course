#pragma once
#include<string>

#pragma warning(disable:4996)
class Registration
{
public:
	bool isItValid(std::string reg);
	Registration(std::string reg);
	Registration();
	void setReg(std::string reg);
	std::string GetReg();
private:
	std::string registrationNumber;
};

