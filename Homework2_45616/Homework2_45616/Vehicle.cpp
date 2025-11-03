#include "Vehicle.h"

Vehicle::Vehicle(std::string reg, std::string descr)
{
	this->decription = descr;
	uniqueNumber.setReg(reg);
}

Vehicle::Vehicle()
{
	decription = " ";
	uniqueNumber.setReg("0000AAAA");
	owner.setId(0);
}



void Vehicle::setReg(std::string reg)
{
	uniqueNumber.setReg(reg);
}

void Vehicle::setDescr(std::string descr)
{
	this->decription = descr;
}

std::string Vehicle::getDescr()
{
	return decription;
}

std::string Vehicle::getReg()
{
	return uniqueNumber.GetReg();
}

void Vehicle::setOwner( Person &someone)
{
	owner.setName(someone.getNanme());
	owner.setId(someone.getId());
}

void Vehicle::removeOwner()
{
	owner.setName(" ");
	owner.setId(0);
	
}

Person* Vehicle::getOwner()
{
	return &owner;
}
