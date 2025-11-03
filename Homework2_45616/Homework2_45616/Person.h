#pragma once
#include <string>
#include <fstream>
#include <vector>
using namespace std;
class Vehicle;
class Person
{
public:
	Person(std::string name, int id);
	Person();
	void setName(std::string name);
	void setId(int id);
	void setVehicle( Vehicle* vec);
	void removeVehicle(int pos);
	Vehicle* getVehicleAt(int pos);
	int retutrPosition(std::string reg);
	std::string getNanme();
	size_t getSize();
	int getId();
	std::vector<Vehicle*> getVecs();
private:
	std::string name;
	int identificator;
	std::vector<Vehicle*>vecs;
	size_t vsize = 0;
};

