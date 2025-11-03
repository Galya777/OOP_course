#include "NumberInput.h"
#include <iostream>
const char* NumberInput::settings()
{
        return (const char*)value;
}

int NumberInput::operator->()
{
    return value;
}
 void NumberInput::setName(const char* name) {
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
 void NumberInput::setMessage(const char* message) {
	this->helpMessage = new char[strlen(message) + 1];
	strcpy(this->helpMessage, message);
};

 void NumberInput::readFromFile()
 {
	 std::ifstream file("load", std::ios::binary);
	 if (!file.is_open()) {
		 std::cout << "Problem opening file!\n";
		 return;
	 }
	 const char* en = new char[6];
	 file >> this->id >> this->name >> this->helpMessage >> (char*)en;
	 file >> beggining >> min >> max;
	 en == "true" ? this->enabled = true : false;
	 std::cout << "Information written from file!\n";

	 delete[] en;
 }

 void NumberInput::writeToFile()
 {
	 std::ofstream file("store", std::ios::binary);
	 if (!file.is_open()) {
		 std::cout << "Problem opening file!\n";
		 return;
	 }
	 file << "Id: " << this->id << " Name: " << this->name << " Help Message: " << this->helpMessage << " Is active: " << std::boolalpha << (enabled);
	 file << beggining << min << max;
	 std::cout << "Information saved to file!\n";
 }

 void NumberInput::operator++()
 {
	 int result = value + 1;
	 if (result <= max) {
		 value = result;
	 }
	 else {
		 std::cout << "Out of range!";
	 }
 }

 void NumberInput::operator--()
 {
	 int result = value - 1;
	 if (result >= min) {
		 value = result;
	 }
	 else {
		 std::cout << "Out of range!";
	 }
 }

 void NumberInput::operator+(int num)
 {
	 int result = value + num;
	 if (result >= min) {
		 value = result;
	 }
	 else {
		 std::cout << "Out of range!";
	 }
 }

 void NumberInput::operator-(int num)
 {
	 int result = value - num;
	 if (result >= min) {
		 value = result;
	 }
	 else {
		 std::cout << "Out of range!";
	 }
 }
