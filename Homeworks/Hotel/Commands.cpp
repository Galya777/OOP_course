#include "Commands.h"
#include <iostream>

Commands::Commands(const char* com)
{

}

Commands::Commands()
{
	command= " ";
}

void Commands::open()
{
	std::cin >> file;
	newFile.open(file);
	if (newFile) {
		char arr[MAX_CONTENT];
		while (!newFile.eof()) {
			newFile.getline(arr, MAX_CONTENT);
			std::cout << arr << std::endl;
		}
	}
	else {
		oldFile.open(file, std::ios::app);
		oldFile << "New File";
	}
	std::cout << "File successfully opened!" << std::endl;
	}

void Commands::close()
{
	oldFile.close();
	newFile.close();
	std::cout << "File successfully closed!" << std::endl;
}

void Commands::save()
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

void Commands::saveAs()
{
	char* buffer;
	long size;
	char path[MAX_FILE];
	std::cout << "Enter the path: ";
	std::cin >> path;
	std::ifstream infile(file, std::ifstream::binary);
	std::ofstream outfile(path, std::ofstream::binary);
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

void Commands::run()
{
	HotelMaker H("h.rooms");
	Interface::createHeader(H);
	do
	{
		Interface::beginDay();
	} while (H.workDay());

}

	

		
	
