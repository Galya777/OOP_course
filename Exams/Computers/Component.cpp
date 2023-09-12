#include "Component.h"
#include <iostream>
#include <fstream>


Component::Component(Property& prop, double price)
{
	properties.push_back(prop);
	vsize++;
	this->price = price;
	
}

Component::Component()
{
	properties.push_back(Property());
	vsize++;
	price = 0;
}

void Component::addProperty(Property& prop)
{
	properties.push_back(prop);
	vsize++;
}

void Component::removeProperty(std::string name)
{
	for (int i = 0; i < vsize; ++i) {
		if (properties.at(i).getName() == name) {
			properties.erase(properties.begin() + i);
		}
	}
}

void Component::editPropertyName(std::string oldname, std::string newName)
{
	try {
		for (size_t i = 0; i < vsize; ++i) {
			if (properties.at(i).getName() == oldname) {
				properties.at(i).setName(newName);
			}
			else {
				throw(oldname);
			}
		}
	}
	catch (char* message) {
		std::cout << "There is no such name in the system!";
	}
}

void Component::editPropertyQuantity(std::string name, int quant)
{
	try {
		for (size_t i = 0; i < vsize; ++i) {
			if (properties.at(i).getName() == name) {
				properties.at(i).setQuantity(quant);
			}
			else {
				throw(name);
			}
		}
	}
	catch (char* message) {
		std::cout << "There is no such name in the system!";
	}
}

void Component::editPRopertyPriceM(std::string name, double priceM)
{
	try {
		for (size_t i = 0; i < vsize; ++i) {
			if (properties.at(i).getName() == name) {
				properties.at(i).setPriceMultiplier(priceM);
			}
			else {
				throw(name);
			}
		}
	}
	catch (char* message) {
		std::cout << "There is no such name in the system!";
	}
}



int Component::returnQuantity(std::string name)
{
	try {
		for (size_t i = 0; i < vsize; ++i) {
			if (properties.at(i).getName() == name) {
				return properties.at(i).getQuantity();
			}
			else {
				throw(name);
			}
		}
	}catch(char* message){
		std::cout << "There is no such name in the system!";
	}
}

double Component::calculateAndGetPrice() 
{
	for (size_t i = 0; i < vsize; ++i) {
		price += properties.at(i).getQuantity()* properties.at(i).getPriceM();
	}
	
	return price;
}

void Component::writeToFile(std::fstream& file)
{
	for (int i = 0; i < properties.size(); ++i) {
		properties.at(i).writeToFile(file);
	}
	file <<" " << price;
}

void Component::printComponents()
{
	for (int i = 0; i < properties.size(); ++i) {
		properties.at(i).printProperty();
	}
	std::cout<<" " << price;
}

void Component::enterComponent()
{
	for (int i = 0; i < properties.size(); ++i) {
		properties.at(i).enterProperty();
	}
	std::cout << "Enter price: ";
	std::cin >> price;
}

 double Component::getPrice() 
{
	return price;
}

const std::vector<Property> Component::getProperties()
{
	return properties;
}

Property Component::getProperty(int i)
{
	return properties.at(i);
}

bool Component::nameRepeating(std::string name)
{
	for (size_t i = 0; i < vsize; ++i) {
		if (properties.at(i).getName() == name) {
			return true;
		}
	}
	return false;
}
