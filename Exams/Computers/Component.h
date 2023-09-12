#pragma once
#include "Property.h"
#include <vector>
class Component
{
public:
	Component(Property& prop, double price);
	Component();
	double getPrice();
	Property getProperty(int i);
const std::vector<Property> getProperties();
virtual void enterComponent();
virtual void writeToFile(std::fstream& file);
void printComponents();
protected:
	void addProperty(Property &prop);
	void removeProperty(std::string name);
	void editPropertyName(std::string oldname, std::string newName);
	void editPropertyQuantity(std::string name, int quant);
	void editPRopertyPriceM(std::string name, double priceM);
	int returnQuantity(std::string name);
	double calculateAndGetPrice();
  
	
    

	bool nameRepeating(std::string name);
protected:
	std::vector<Property> properties;
	size_t vsize = 0;
	double price;

};

