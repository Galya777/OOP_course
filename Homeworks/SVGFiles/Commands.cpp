#include "Commands.h"
using namespace std;
Commands::Commands()
{
}
void Commands::run()
{
	char command[MAX_COMMAND];
	Figures shape;
	do {
		std::cout << "Add a command:" << std::endl;
		std::cin >> command;
		char file[MAX_FILE];
		std::ofstream oldFile;
		std::ifstream newFile;
		if (strcmp(command, "open") == 0) {
			cin >> file;
			newFile.open(file);
			if (newFile) {
				char arr[MAX_CONTENT];
				while (!newFile.eof()) {
					newFile.getline(arr, MAX_CONTENT);
					std::cout << arr << endl;
				}
			}
			else {
				oldFile.open(file, std::ios::app);
				oldFile << "New File";
			}
			std::cout << "File successfully opened!" << std::endl;
		}if (strcmp(command, "close") == 0) {
			oldFile.close();
			newFile.close();
			std::cout << "File successfully closed!" << std::endl;
		}if (strcmp(command, "save") == 0) {
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
		}if (strcmp(command, "save as") == 0) {
			char* buffer;
			long size;
			char path[MAX_FILE];
			cout << "Enter the path: ";
			cin >> path;
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
		} if (strcmp(command, "help") == 0) {
			std::cout << "The following commands are supported:\n";
			std::cout << "open<file>" << "  " << "opens <file>\n";
			std::cout << "close" << "  " << "closes currently opened file\n";
			std::cout << "save" << "  " << "saves the currently opened file\n";
			std::cout << "save as" << "  " << "saves the currently opened file in <file>\n";
			std::cout << "help" << "  " << "prints this information\n";
			std::cout << "exit" << "  " << "exits the program\n";
		} if (strcmp(command, "print") == 0) {
			shape.deserialize(file);
			shape.printFigures();
		} if (strcmp(command, "create") == 0) {
			char option[MAX_TYPE];
			cin >> option;
			shape.addFigure(option);
			cout << "Successfully created " << option << " " << shape.getNumber() << endl;
			shape.serialize(oldFile);
		} if (strcmp(command, "erase") == 0) {
			int number;
			cin >> number;
			shape.removeFigure(number);
			cout << "You removed figure " << number;
		} if (strcmp(command, "translate") == 0) {
			int number;
			cin >> number;
			shape.translate(number);
		} if (strcmp(command, "within") == 0) {
			char option[MAX_TYPE];
			cin >> option;
			shape.printType(option);
		}

	} while (strcmp(command, "exit") != 0);
}
