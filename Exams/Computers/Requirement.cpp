#include "Requirement.h"
#include <iostream>
Requirement::Requirement(Component comp)
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

Requirement::Requirement()
{
}

bool Requirement::hasSameTypes(Configuration& con)
{
	for (int i = 0; i < components.size(); ++i) {

		if (typeid(con.getComponent(i)) == typeid(components.at(i)))
			return true;
	}
	return false;
}

bool Requirement::hasBetterCharacteristics(Configuration& con)
{
	
	for (int i = 0; i < components.size(); ++i) {
		if (con.getComponent(i).getPrice() < components.at(i).getPrice()) {
			return true;
		} 
		int size = con.getComponent(i).getProperties().size();
		for (int j = 0; j < size; ++j) {
			if (con.getComponent(i).getProperty(i).getQuantity() > components.at(i).getProperty(i).getQuantity()) {
				return true;
			}
		}
	}
	return false;
}

void Requirement::enterRequirement(int numberOfComponents)
{
	for (int i = 0; i < numberOfComponents; ++i) {
		components.at(i).enterComponent();
	}
}

bool Requirement::RepeatingTypes(Component comp)
{
	for (int i = 0; i < components.size(); ++i) {

		if (typeid(comp) == typeid(components.at(i)))
			return true;
	}

	return false;
}
