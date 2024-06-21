#include "Commands.h"
#include <iostream>
#pragma warning(disable:4996)
Commands::Commands(const char* com)
{
	command == com;
}

Commands::Commands()
{
	command== "";
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
			table.readFromFile(newFile);
		}
		else {
			CreatenewFile();
			
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

void Commands::CreatenewFile()
{
	oldFile.open(file, std::ios::app);
	oldFile << "New File";
}

void Commands::edit(int row, int col)
{
	try {
		if (row < table.getRow() && col < table.getCol()) {
			Cell c;
			if (c.findType(cellFilling.c_str()) == UNKNOWN) {
				std::cout << "Invalid data!";
			}
			else {
				table.editTableCell(row, col, cellFilling.c_str());
			}
		}	else {
			throw(row);
		}
	}
	catch (char* message) {
		std::cout << "Invalid cell!";
	}
	
}

void Commands::print()
{
	char border = '|';
	for (size_t i = 0; i <= table.maxCellsPerRow(); i++)
	{
		if (i < table.maxCellsPerRow())
		{
			std::cout << border<< (char)('A' + i) << std::setw(table.maxCellsPerRow() + 1);
		}
		else
		{
			std::cout << border << (char)(' ') << std::setw(table.maxCellsPerRow() - 2) << " ";
		}
	}
	std::cout << std::endl;
	for (int i = 0; i < table.getRow(); ++i) {
		std::cout << (i + 1);
		for (int j = 0; j < table.getCol(); ++j) {
			std::cout << border; table.printElement(i, j); std::cout << border;
		}
		std::cout << std::endl;
	}
	
}

void Commands::run()
{
	do {
		std::cout << "Enter your command: ";
		std::cin >> command;
		if (command== "open") {
			open();
			
		}
		else if (command== "close") {
			close();
		}
		else if (command == "save") {
			table.writeToFile(oldFile);
			save();
		}
		else if (command == "save as") {
			table.writeToFile(oldFile);
			saveAs();
		}
		else if (command == "new") {
			CreatenewFile();
		}
		else if (command == "edit") {
			std::cout << "Enter the cell coordinats: ";
			std::cin >> row >> col;
			std::cout << "Now enter the new content of this cell: ";
			std::cin >> cellFilling;
			edit(row, col);
		}
		else if (command == "print") {
			table.writeToFile(oldFile);
			print();
		}
		else if (command != "exit") {
			std::cout << "Invalid command! Try again!"<<std::endl;
		}
	} while (command!= "exit");

}

	

		
	
