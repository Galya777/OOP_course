#include "Registration.h"
#include <iostream>

bool Registration::isItValid(std::string reg)
{
	if (reg.size() != 8) {
		std::cout << "Your number must be 8 symbols!"<<"\n";
		return false;
	}else {
		if (isalpha(reg[0])==false && isalpha(reg[1])==false) {
			std::cout << "Your number must start with capital letters."<<"\n";
			return false;
		}else {
			for (int i = 2; i < 6; ++i) {
				if (isdigit(reg[i]) == false) {
					std::cout << "Your number must have four numbers."<<"\n";
					return false;
				}
			} if (isalpha(reg[6]) == false && isalpha(reg[7]) == false) {
				std::cout << "Your number must ends with capital letters." << "\n";
				return false;
			}
		}	
			return true;
	}
}

Registration::Registration(std::string reg)
{
	this->registrationNumber = reg;
}

Registration::Registration()
{
	registrationNumber = " ";
	
}

void Registration::setReg(std::string reg)
{
	try {
		if (isItValid(reg) == true) {
			this->registrationNumber = reg;
		}
		else {
			throw reg;
		}
	}catch (std::string reg) {
		std::cout << "Your registration number is invalid! Enter another: ";
		std::cin >> reg;
		setReg(reg);
	}
}

std::string Registration::GetReg()
{
	return registrationNumber;
}
