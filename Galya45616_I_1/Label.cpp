#include "Label.h"
#include <iostream>
#include <exception>


void Label::setName(const char* name)
{
	std::cout << "Name cannot be changed after the object is created!\n";
}

void Label::setMessage(const char* message)
{
	std::cout << "Message cannot be changed after the object is created!\n";

}

void Label::print()
{
	std::cout << "Id: " << this->id << " Name: " << this->name << " Help Message: " << this->helpMessage << " Is active: " << std::boolalpha<< (enabled);
}

const char* Label::settings()
{
	return "";
}

void Label::readFromFile()
{
	std::ifstream file("load", std::ios::binary);
	if (!file.is_open()) {
		std::cout << "Problem opening file!\n";
		return;
	}
	const char* en= new char[6];
	file >> this->id >> this->name >> this->helpMessage >> (char*)en;
	en == "true" ? this->enabled = true : false;
	std::cout << "Information written from file!\n";

	delete[] en;
}

void Label::writeToFile()
{
	std::ofstream file("store", std::ios::binary);
	if (!file.is_open()) {
		std::cout << "Problem opening file!\n";
		return;
	}
	file << "Id: " << this->id << " Name: " << this->name << " Help Message: " << this->helpMessage << " Is active: " << std::boolalpha << (enabled);
	std::cout << "Information saved to file!\n";
}


