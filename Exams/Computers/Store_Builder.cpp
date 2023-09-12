#include "Store_Builder.h"

Store_Builder::Store_Builder()
{
	size = 0;
}

Store_Builder::~Store_Builder()
{
	delete[] type;
}

void Store_Builder::readFromFile(std::string path)
{
	std::ifstream newFile(path);
			newFile.open(path);
			if (newFile.is_open()) {
				while (!newFile.eof()) {
					newFile >> *type;
					if (*type == "cpu") {
						newFile >> cpu;
						
					}
					else if (*type == "ram") {
						newFile >> ram;
					}
					else if (*type == "hdd") {
						newFile >> hdd;
					}
					else {
						std::cout << "There is no such kind of component in the store right now!";
					}
					addToStore(*type);
				}
				newFile.close();
			}
			else {
				std::cout << "There is no such a file. ";
			std::cin >> path;
			readFromFile(path);
			}
	
	
}

void Store_Builder::save(char* file)
{

	char* buffer;
	long size;

	std::ifstream infile(file, std::ifstream::binary);
	std::ofstream outfile(file, std::ofstream::binary);
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

void Store_Builder::addToStore(std::string typeofComponent)
{
	if (typeofComponent == "cpu") {
		store.addComponent(cpu);
		
	}
	else if (typeofComponent == "ram") {
		store.addComponent(ram);
	}
	else if (typeofComponent == "hdd") {
		store.addComponent(hdd);
	}
	else {
		std::cout << "There is no such kind of component in the store right now!";
	}
}


const Store Store_Builder::ReturnStore()
{
    return store;
}
