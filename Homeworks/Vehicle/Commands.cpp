#include "Commands.h"
#include <iostream>
#include "Registration.h"
#include <vector>
#include <iomanip>
#pragma warning(disable:4996)
Commands::Commands(const char* com)
{
	this->command = com;
	per.push_back( Person());
	vec.push_back(Vehicle());
}

Commands::Commands()
{
	command= " ";
}

bool Commands::checkConvertation(const char* com)
{
	int counter = 0;
	for (size_t i = 0; i < strlen(com); ++i) {
		if (isdigit(com[i])) {
			++counter;
		}
	} if (counter == strlen(com)) {
		return true;
	}
	return false;
}

int Commands::convert(const char* com)
{
	return atoi(com);
}

size_t Commands::equalRegPos(std::string number)
{
	for (size_t i = 0; i < vec.size(); ++i) {
		if (vec[i].getReg() == number) {
			return i;
		}
	}
	return vec.size()+3;
}

size_t Commands::equalIdPos(int id)
{
	for (size_t i = 0; i < per.size(); ++i) {
		if (per[i].getId() == id) {
			return i;
		}
	}
	return per.size()+id;
}

void Commands::remove(const char* something)
{
	
	if (checkConvertation(something) == true) {
		int id = convert(something);
		if (equalIds(id)==true) {
			int pos = equalIdPos(id);
			if (per[pos].getVecs().empty()==false) {
				std::cout << "This person has cars. Are you sure if you want to remove him?"<<"\n";
				char answer[3];
				std::cin >> answer;
				if (answer == "YES") {
					for (size_t i = 0; i < per[pos].getSize(); ++i) {
						release(id, per[pos].getVehicleAt(i)->getReg());
					}
						per.erase(this->per.begin() + pos);
					std::cout << "This person is removed!"<<"\n";
				}else{
					std::cout << "We have not changed a thing!"<<"\n";
				}
			}else {
					per.erase(this->per.begin() + pos);
				std::cout << "This person is removed!"<<"\n";
			}
		}
		else {
			std::cout << "There is no person with that id. " << "\n";
		}
	}	else {
		if (equalRegs(something)==true) {
			int pos = equalRegPos(something);
			if (vec[pos].getOwner() != nullptr) {
				std::cout << "This vehicle has an owner. Are you sure if you want to remove it?" << "\n";
				char answer[3];
				std::cin >> answer;
				if (answer != "YES") {
					std::cout << "We have not changed a thing!" << "\n";
				}	else {
					release(vec[pos].getOwner()->getId(), something);
					vec.erase(this->vec.begin() + pos);
					std::cout << "This vehicle is removed!" << "\n";
				}
			}	
			vec.erase(this->vec.begin() + pos);
			std::cout << "This vehicle is removed!" << "\n";
		}
		else {
			std::cout << "There is no vehicle with that registration. " << "\n";
		}
	}
}

void Commands::save()
{
	char* buffer;
	long size;
	std::string path;
	std::cout << "Enter the path: ";
	std::cin>>path;
	if (exists(path)) {
		std::cout << "This file is excisting! Want to save here anyways?";
		std::string com;
		std::cin >> com;
		if (com != "YES") {
			std::cout << "Nothing is changed!";
			return;
		}
	}
	std::ifstream infile(file);
	std::ofstream outfile(path);
	infile.seekg(0, std::ifstream::end);
	size = infile.tellg();
	infile.seekg(0);
	buffer = new char[size];
	infile.read(buffer, size);
	outfile.write(buffer, size);
	delete[] buffer;
	outfile.close();
	infile.close();
	std::cout << "File successfully saved!" << std::endl;
}

void Commands::show(const char* something)
{
	if (something == "person") {
		std::cout << "People in the system: " << "\n";
		for (size_t i = 0; i < per.size(); ++i) {
			std::cout << per[i].getNanme() << " " << per[i].getId() << "\n";
		}
	}else if (something == "vehicle") {
		std::cout << "Vehicles in the system: " << "\n";
		for (size_t i = 0; i < vec.size(); ++i) {
			std::cout << vec[i].getReg() << " " << vec[i].getDescr() << "\n";
		}
	}else {
		int pos=0;
		if (checkConvertation(something) == true) {
			int id = convert(something);
			if (equalIds(id) == true) {
				 pos = equalIdPos(id);
				 std::cout << "This person has "<<per[pos].getSize()<<" vehicles."<<"\n";
				 for (size_t i = 0; i < per[pos].getSize(); ++i) {
					 std::cout << per[pos].getVehicleAt(i)->getReg() << "\n";
				 }
			}else {
				std::cout << "There is no such an id!" << "\n";
			}
		}else {
			if (equalRegs(something) == true) {
				pos = equalRegPos(something);
				if (vec[pos].getOwner() == nullptr) {
					std::cout << "This vehicle has no owner!"<<"\n";
				}else {
					std::cout << "The owner of this vehicle is " << vec[pos].getOwner()->getNanme() << "\n";
				}
			}else {
				std::cout << "There is no such registration number!" << "\n";
			}
		}	
	}
}

bool Commands::equalIds(int id)
{
	for (size_t i = 0; i < per.size(); ++i) {
		if (per[i].getId()==id) {
			return true;
		}
	}
	return false;
}

bool Commands::equalRegs(std::string number)
{
	for (size_t i = 0; i < vec.size(); ++i) {
		if (vec[i].getReg() == number) {
			return true;
		}
	}
	return false;
}

inline bool Commands::exists(const std::string& name)
{
	if (FILE* file = fopen(name.c_str(), "r")) {
		fclose(file);
		return true;
	}
	else {
		return false;
	}
}

void Commands::addVehicle(std::string reg, std::string des)
{
	try {
		if (equalRegs(reg) == false){
			Vehicle v;
		v.setReg(reg);
		v.setDescr(des);
		vec.push_back(v);
		}else {
			throw (reg);
		}
	}catch (char* reg) {
		std::cout << "Your registration number is repeating! Enter another: ";
		std::cin >> reg;
		addVehicle(reg,des);
	}
}

void Commands::addPerson(std::string name, int id)
{
	try {
		if (equalIds(id) == false) {
			Person p;
			p.setName(name);
			p.setId(id);
			per.push_back(p);
		}	else {
			throw (id);
		}
	}catch (int id) {
		std::cout << "Your identification number is repeating! Enter another: ";
		std::cin >> id;
		addPerson(name, id);
	}
}
void Commands::aquaire(int id, std::string reg)
{	
	if (equalIds(id) == true && equalRegs(reg) == true) {
		int posPer, posVec;
		posPer = equalIdPos(id);
		posVec = equalRegPos(reg);

		if (vec[posVec].getOwner()->getId()!=0) {
			release(id, vec[posVec].getReg());
		}vec[posVec].setOwner(per[posPer]);
		per[posPer].setVehicle(&vec[posVec]);
		std::cout << per[posPer].getNanme() << " you are the owner of car " << reg << "\n";
	}	else {
		std::cout << "No such a car or person here.";
	}
}
void Commands::release(int id, std::string reg)
{	
	if (equalIds(id) == true && equalRegs(reg) == true) {
		int posPer, posVec;
		posPer = equalIdPos(id);
		posVec = equalRegPos(reg);
		vec[posVec].removeOwner();
		int car = per[posPer].retutrPosition(reg);
		per[posPer].removeVehicle(car);
		std::cout << per[posPer].getNanme() << " you are  NO MORE the owner of car " << reg << "\n";
	}	else {
		std::cout << "No such a car or person here.";
	}
}
std::string Commands::capitalize(std::string word)
{
	for (size_t i = 0; word[i] != 0; i++) {
		if (word[i] <= 'z' && word[i] >= 'a')
			word[i] += 'A' - 'a';
	}
	return word;
}
void Commands::run()
{
	std::cout << "Will you read from file?";
	std::cin >> command;
	if (command == "YES") {
		std::cout << "Enter the file: ";
		cin.getline(file, MAX_FILE);
		std::ifstream newFile(file);
		char buffer[MAX_FILE] = { 0 };
		if (!newFile.is_open()) {
			std::cout << "There is no such a file. ";
			return;
		} 
		while (!newFile.eof()) {
			newFile >> buffer;
			memset(buffer, 0, MAX_FILE);
		}

	}
	do {
		char registration[8];
		std::string description;
		std::string name;
		int id;
		std::cout << "Please, enter your command: ";
		std::cin >> command;
		command = capitalize(command);
		if (command == "VEHICLE") {
			std::cout << "Enter a registration number: ";
			std::cin >> registration;
			std::cout << "Enter a description: ";
			std::cin >> description;
			addVehicle(registration, description);
			std::cout << "Vehicle successfully added!" << "\n";
		}else if (command == "PERSON") {
			std::cout << "Enter a name: ";
			std::cin >>std::quoted(name);
			std::cout << "Enter an id: ";
			std::cin >> id;
			addPerson(name, id);
			std::cout << "Pearson successfully added!" << "\n";
		}	else if (command == "ACQUIRE") {
			std::cout << "Enter a registration number: ";
			std::cin >> registration;
			std::cout << "Enter an id: ";
			std::cin >> id;
			aquaire(id, registration);

		}	else if (command == "RELEASE") {
			std::cout << "Enter a registration number: ";
			std::cin >> registration;
			std::cout << "Enter an id: ";
			std::cin >> id;
			release(id, registration);

		}	else if (command == "REMOVE") {
			std::cout << "Enter something: ";
			std::cin >> registration;
			remove(registration);
		}	else if (command == "SAVE") {
			save();
		}else if (command == "SHOW") {
			std::cout << "Enter something: ";
			std::cin >> registration;
			show(registration);
		}else {
			std::cout << "Invalid command! Enter another. "<<"\n";
			
		}
	} while (command!="EXIT");
	std::cout << "End of program!";
}

	

		
	
