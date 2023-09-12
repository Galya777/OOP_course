#include <iostream>
#include "School.h"
using namespace std;
struct Student {
	char* name = new char[10];
	char* surname = new char[10];
	char* lastname = new char[10];
	char* id = new char[10];
	int facultityNum;
	struct Grade {
		char* subject= new char[10];
		int grade;
	};
};
int main()
{
	char* command = new char[10];
	do {
		cout << "Enter your command: ";
		cin.getline(command, 10);
		if (strcmp(command, "add") == 0) {

		}
		else if (strcmp(command, "march") == 0) {

		}
		else if (strcmp(command, "smartest") == 0) {

		}
		else if (strcmp(command, "advanced") == 0) {

		}
	} while (strcmp(command, "exit") != 0);
	delete[] command;
    return 0;
}