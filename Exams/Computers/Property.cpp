#include "Property.h"
#include <iostream>
#include <fstream>
Property::Property(const std::string name, const int quantiny, const double price)
{
	this->name = name;
	this->quantity = quantiny;
	this->priceMultiplier = price;
}

Property::Property()
{
	name = "";
	quantity = 0;
	priceMultiplier = 0;
}

const std::string Property::getName() 
{
	return name;
}

const int Property::getQuantity() 
{
	return quantity;
}

const double Property::getPriceM() 
{
	return priceMultiplier;
}

void Property::setName(std::string name)
{
	this->name = name;
}

void Property::setQuantity(int q)
{
	this->quantity = q;
}

void Property::setPriceMultiplier(double prM)
{
	this->priceMultiplier = prM;
}

void Property::enterProperty()
{
	std::cout << "Enter the name, quantity and pricemultiplier: ";
	std::cin >> name >> quantity >> priceMultiplier;
}

void Property::writeToFile(std::fstream& file)
{
	file << name <<" "<< quantity <<" "<< priceMultiplier;
	file << "\n";
}

void Property::printProperty()
{
	std::cout << name << " " << quantity << " " << priceMultiplier<<std::endl;
}
