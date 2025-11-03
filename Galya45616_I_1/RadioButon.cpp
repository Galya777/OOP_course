#include "RadioButon.h"
#include <iostream>
#include <stdexcept>
void RadioButon::setName(const char* name) {
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
void RadioButon::setMessage(const char* message) {
	this->helpMessage = new char[strlen(message) + 1];
	strcpy(this->helpMessage, message);
};

void RadioButon::readFromFile()
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

void RadioButon::writeToFile()
{
	std::ofstream file("store", std::ios::binary);
	if (!file.is_open()) {
		std::cout << "Problem opening file!\n";
		return;
	}
	file << "Id: " << this->id << " Name: " << this->name << " Help Message: " << this->helpMessage << " Is active: " << std::boolalpha << (enabled);

	std::cout << "Information saved to file!\n";
}
bool RadioButon::operatorf(int index)
{
	if (index > 0 && index < 16) {
		chosenlabel = Label(labels[index]);
		return true;
	}
    return false;
}
void RadioButon::addLabel(Label& label)
{
	int result = size + 1; 
	if (result < 16) {
		labels[size] = label;
		size++;
	}
	else {
		std::cout << "No more space!\n";
	}

}
void RadioButon::removeLabel(int index)
{
	if (index > 0 && index < 16) {
		for (size_t i = index; i < 15; i++)
		{
			labels[i] = labels[i + 1];
		}
		size--;
	}
	else {
		std::cout << "Invalid index!\n";
	}
}
Label RadioButon::getLabel(int index)
{
	try {
		if (index > 0 && index < 16) {
			return labels[index];
		}
		else {
			throw std::out_of_range("Invalid index");
		}
	}
	catch (char* e) {
		throw std::out_of_range("Invalid index");
	}
}
void RadioButon::print()
{
	std::cout << "Id: " << this->id << " Name: " << this->name << " Help Message: " << this->helpMessage << " Is active: " << std::boolalpha << (enabled);
}

const char* RadioButon::settings()
{
	return chosenlabel.getName()!=nullptr?chosenlabel.getName():"";
}
