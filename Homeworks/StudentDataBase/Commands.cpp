#include "Commands.h"
Commands::Commands()
{
}
void Commands::run()
{
	char command[MAX_COMMAND];
	Student student;
	Decipline decipline;
	Speciality Onespeciality;
	int facultity;
	char theSpeciality[MAX_ADDINPUT_LEN];
	char nameofStudent[MAX_ADDSPEC_LEN];
	do {
		std::cout << "Add a command:" << std::endl;
		std::cin >> command;
		char file[MAX_FILE];
		std::ofstream oldFile;
		std::ifstream newFile;
		if (strcmp(command, "open") == 0) {
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
		}if (strcmp(command, "close") == 0) {
			newFile.close();
			oldFile.close();
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
		} if (strcmp(command, "help") == 0) {
			std::cout << "The following commands are supported:\n";
			std::cout << "open<file>" << "  " << "opens <file>\n";
			std::cout << "close" << "  " << "closes currently opened file\n";
			std::cout << "save" << "  " << "saves the currently opened file\n";
			std::cout << "save as" << "  " << "saves the currently opened file in <file>\n";
			std::cout << "help" << "  " << "prints this information\n";
			std::cout << "exit" << "  " << "exits the program\n";
		} if (strcmp(command, "enroll") == 0) {
			std::cin >> facultity;
			decipline.addStudent(facultity);
			std::cout << "Student is enrolled!" << std::endl;
			continue;
		} if (strcmp(command, "advance") == 0) {
			std::cin >> facultity;
			student.setFacultity(facultity);
			student.setCourse(student.getCourse() + 1);
			std::cout << "Now student is in the next course." << std::endl;
		} if (strcmp(command, "change") == 0) {
			std::cin >> facultity;
			student.setFacultity(facultity);
			std::cin >> theSpeciality;
			student.setSpeciality(theSpeciality);
			std::cout << "The speciality is changed successfully!" << std::endl;
		}if (strcmp(command, "graduate") == 0) {
			std::cin >> facultity;
			student.setFacultity(facultity);
			if (student.isGraduated() == true)
				student.setStatus("graduated");
			std::cout << "Student is graduated!" << std::endl;
		}if (strcmp(command, "interrupt") == 0) {
			std::cin >> facultity;
			student.setFacultity(facultity);
			student.setStatus("interrupted");
			std::cout << "Student is interruptedted!" << std::endl;
		}if (strcmp(command, "resume") == 0) {
			std::cin >> facultity;
			student.setFacultity(facultity);
			student.setStatus("enrolled");
			std::cout << "Student is enrolled again!" << std::endl;
		}if (strcmp(command, "print") == 0) {
			std::cin >> facultity;
			student.setFacultity(facultity);
			std::cout << student.getName() << std::endl;
			std::cout << student.geStatus() << std::endl;
			std::cout << student.getCourse() << std::endl;
			std::cout << student.getGroup() << std::endl;
			std::cout << student.getFacultity() << std::endl;
			std::cout << student.getSpeciality() << std::endl;
		} if (strcmp(command, "printall") == 0) {
			std::cin >> theSpeciality;
			int course;
			std::cin >> course;
			Onespeciality.setSpeciality(theSpeciality);
			Onespeciality.setCourse(course);
			Onespeciality.printStudentsInTHISspeciality();
		} if (strcmp(command, "enroll") == 0) {
			std::cin >> facultity;
			student.setFacultity(facultity);
			std::cin >> nameofStudent;
			decipline.setDeciplineName(nameofStudent);
			decipline.addStudent(student.getFacultity());
		} if (strcmp(command, "addgrade") == 0) {
			std::cin >> facultity;
			student.setFacultity(facultity);
			std::cin >> nameofStudent;
			decipline.setDeciplineName(nameofStudent);
			double grade;
			std::cin >> grade;
			decipline.addGrades(grade);

		}if (strcmp(command, "protocol") == 0) {
			std::cin >> nameofStudent;
			decipline.setDeciplineName(nameofStudent);
			decipline.printStudents();
		}if (strcmp(command, "report") == 0) {
			std::cin >> facultity;
			student.setFacultity(facultity);
			student.printGrades();
		}
	} while (strcmp(command, "exit") != 0);
}
