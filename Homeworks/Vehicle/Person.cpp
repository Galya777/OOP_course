#include "Person.h"
#include "Vehicle.h"
Person::Person(std::string name, int id)
{
	name.operator=(name);
	this->identificator = id;
	vecs.push_back(new Vehicle());
}

Person::Person()
{
	name = " ";
	identificator = 0;
	
}



void Person::setName(std::string name)
{
	this->name = name;
}

void Person::setId(int id)
{
	this->identificator = id;
}

void Person::setVehicle( Vehicle* vec)
{
	vecs.push_back(vec);
	vsize++;
}



void Person::removeVehicle(int pos)
{
	vecs.erase(vecs.begin() + pos);
}

Vehicle* Person::getVehicleAt(int pos)
{
	return vecs.at(pos);
}



int Person::retutrPosition(std::string reg)
{
	for (size_t i = 0; i < vecs.size(); ++i) {
		if (vecs[i]->getReg() == reg) {
		return i;
		}
	}
	
}

std::string Person::getNanme()
{
	return name;
}

size_t Person::getSize()
{
	return vsize;
}

int Person::getId()
{
	return identificator;
}

std::vector<Vehicle*> Person::getVecs()
{
	return vecs;
}
