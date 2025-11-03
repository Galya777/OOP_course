#pragma once
#include <string>
#include "Registration.h"
#include "Person.h"
class Vehicle 
{
public:
	Vehicle(std::string reg, std::string descr);
	Vehicle();
	void setReg(std::string reg);
	void setDescr(std::string descr);
	std::string getDescr();
	std::string getReg();
	
	void setOwner( Person &someone);
	void removeOwner();
	Person* getOwner();
private:
	Registration uniqueNumber;
	std::string decription;
	Person owner;
	
};

