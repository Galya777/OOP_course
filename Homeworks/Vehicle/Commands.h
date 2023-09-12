#pragma once
#include <fstream>
#include <cstring>
#include <vector>
#include "Person.h"
#include "Vehicle.h"
const int MAX_FILE = 100;
class Commands
{
public:
	Commands(const char* com);
	Commands();
	
	bool checkConvertation(const char* com);
	int convert(const char* com);

	size_t equalRegPos(std::string number);
	size_t equalIdPos(int id);
	bool equalIds(int id);
	bool equalRegs(std::string number);
	inline bool exists(const std::string& name);

	void addVehicle(std::string reg, std::string des);
	void addPerson(std::string name, int id);
	void aquaire(int id, std::string reg);
	void release(int id, std::string reg);
	void remove(const char* something);
	void save();
	void show(const char* something);

	std::string capitalize(std::string word);
	void run();
private:
	std::string command;
	char file[MAX_FILE];
	std::vector <Person> per;
	std::vector <Vehicle> vec;
};

