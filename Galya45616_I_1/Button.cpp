#include "Button.h"
#include <iostream>
const char* Button::settings()
{
    return nullptr;
}

void Button::setName(const char* name) {
	try {
		if (name != "") {
			this->name = new char[strlen(name) + 1];
			strcpy(this->name, name);
		}
		else {
			return;
		}
	}
	catch (char* exc) {
		"Name cannot be empty";
	}


};
void Button::setMessage(const char* message) {
	this->helpMessage = new char[strlen(message) + 1];
	strcpy(this->helpMessage, message);
};

void Button::readFromFile()
{
	std::ifstream file("load", std::ios::binary);
	if (!file.is_open()) {
		std::cout << "Problem opening file!\n";
		return;
	}
	const char* en = new char[6];
	file >> this->id >> this->name >> this->helpMessage >> (char*)en;
	en == "true" ? this->enabled = true : false;
	std::cout << "Information written from file!\n";

	delete[] en;
}

void Button::writeToFile()
{
	std::ofstream file("store", std::ios::binary);
	if (!file.is_open()) {
		std::cout << "Problem opening file!\n";
		return;
	}
	file << "Id: " << this->id << " Name: " << this->name << " Help Message: " << this->helpMessage << " Is active: " << std::boolalpha << (enabled);
	std::cout << "Information saved to file!\n";
}