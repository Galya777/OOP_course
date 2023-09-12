#include "Configuration.h"
#include <iostream>

Configuration::Configuration(Component comp, double price)
{
	this->price = price;
	try {
		if (RepeatingTypes(comp) == false) {
			components.push_back(comp);
		}
		else {
			throw(comp);
		}
	}
	catch (char* message) {
		std::cout << "There is a component with this type in this configuration!";
	}
}

Configuration::Configuration()
{
	price = 0.0;
}

void Configuration::addComponent(Component comp)
{
	try {
		if (RepeatingTypes(comp) == false) {
			components.push_back(comp);
		}
		else {
			throw(comp);
		}
	}
	catch (char* message) {
		std::cout << "There is a component with this type in this configuration!";
	}
}



bool Configuration::RepeatingTypes(Component comp)
{
	
	for (int i = 0; i < components.size(); ++i) {
		
			if (typeid(comp) == typeid(components.at(i)))
				return true;
		}
	
	return false;
}

double Configuration::CalculatePrice()
{
	price = 0;
	for (int i = 0; i < components.size(); ++i) {
		price += components.at(i).getPrice();
	}
	price += 0.07*price;
	return price;
}
