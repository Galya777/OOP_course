#include <iostream>
#include "Users.h"
#include <cstring>
#include "Challange.h"
#include <fstream>
const int MAX_COMMAND = 14;
int size = 0;
int sizech = 0;
Users* users = new Users[size];
Challange* all = new Challange[MAX_LIMIT];
void getinfo(Users& person) {
	person.getName();
	person.getEmail();
	person.getAge();
}
void add(Challange &challange) {
	challange.getchallange();
}
int main()
{
	char name[MAX_CAPACITY];
	char command[MAX_COMMAND];;
	char email[MAX_CAPACITY];
	char challange[MAX_CHALLANGE];
	int age;
	do {
		std::cout << "Add a command:" << std::endl;
		std::cin.getline( command, MAX_COMMAND);
		Users person;
		Challange chall;
		if (strcmp(command, "registration") == 0) {
			std::cout << "Enter name: ";
			std::cin.getline(name, MAX_CAPACITY);	
			std::cout << "Enter email: ";
			std::cin.getline( email, MAX_CAPACITY);
			std::cout << "Enter age: ";
			std::cin >> age;
			person.setName(name);
			person.setemail(email);
			person.setAge(age);
			size++;
			std::cout << person.getName() << ", you are succesfully registrated in the system!" << std::endl;
			for (int i = 0; i < size; i++) {
				getinfo(users[i]);
			}
			size++;
			std::cout << "Add a command:" << std::endl;
			std::cin.getline(command, MAX_COMMAND);
		} if (strcmp(command, "challange") == 0) {
			std::cout << "Enter name: ";
			std::cin.getline(name, ' ');
			person.setName(person.adding(name));
			for (int j = 0; j < size; j++) {
				if (strcmp(users[j].getName(), person.getName()) == 0) {
						std::cout << "Enter challange: ";
						std::cin.getline(challange, ' ');
						chall.setchallange(challange);
					}
				}
		}  if (chall.ischallange() == true) {
			for (int j = 0; j < chall.sizechall; j++) {
				if (chall.getchallange() != all[j].getchallange()) {
					sizech++;
					for (int i = 0; i < sizech; i++) {
						add(all[i]);
					}
					sizech++;
					chall.setstatus("new");
				}
				else {
					chall.increaseId();
				}
				if (chall.getid() >= 2 && chall.getid() <= 10) {
					chall.setstatus("quite recently");
				}
				else if (chall.getid() >= 11) {
					chall.setstatus("old");
				}
			}
			int players;
			std::cout << "Enter the number of players";
			std::cin >> players;
			for (int g = 0; g < players; g++) {
				Users player;
				person.setName(person.adding(name));
				player.setName(person.getName());
				for (int j = 0; j < size; j++) {
					if (strcmp(users[j].getName(), person.getName()) == 0) {
						std::cout << "Players are challanged!" << std::endl;
					}
				}
				std::cin.getline(command, ' ');
			}
			if (strcmp(command, "finish") == 0) {
				std::cout << "Enter challange: ";
				std::cin.getline(challange, ' ');
				chall.setchallange(challange);
				float grade;
				std::cout << "Enter grade: ";
				std::cin >> grade;
				chall.setRating(grade);
				std::cin.getline(command, ' ');
			} if (strcmp(command, "profile_info") == 0) {
				std::cout << "Enter name: ";
				std::cin.getline(name, ' ');
				person.setName(person.adding(name));
				for (int j = 0; j < size; j++) {
					if (strcmp(users[j].getName(), person.getName()) == 0) {
						std::cout << users[j].getName() << std::endl;
						std::cout << users[j].getEmail() << std::endl;
						std::cout << users[j].getAge() << std::endl;
						std::cout << users[j].getId() << std::endl;
					}
					else {
						std::cout << "Unknown!" << std::endl;
					}
				}std::cin.getline(command, ' ');
			}
		}if (strcmp(command, "list_by") == 0) {
					char sortWay[MAX_CHALLANGE];
					std::cout << "Enter sortway: ";
					std::cin.getline(sortWay, ' ');
					if (strcmp(sortWay, "new") == 0) {
						for (int i = 0; i < sizech - 1; i++) {
							int currMinIndex = 0;
							for (int j = i + 1; j < sizech; j++)
								if (all[j].getid() < all[currMinIndex].getid())
									currMinIndex = j;
							if (i != currMinIndex)
								std::swap(all[i], all[currMinIndex]);
						}
					} if (strcmp(sortWay, "oldest") == 0) {
						for (int i = 0; i < sizech - 1; i++) {
							int currMaxIndex = 0;
							for (int j = i + 1; j < sizech; j++)
								if (all[j].getid() > all[currMaxIndex].getid())
									currMaxIndex = j;
							if (i != currMaxIndex)
								std::swap(all[i], all[currMaxIndex]);
						}
					} if (strcmp(sortWay, "most_popular") == 0) {
						for (int i = 0; i < sizech - 1; i++) {
							int currMaxIndex = 0;
							for (int j = i + 1; j < sizech; j++)
								if (all[j].getrating() > all[currMaxIndex].getrating())
									currMaxIndex = j;
							if (i != currMaxIndex)
								std::swap(all[i], all[currMaxIndex]);
						}
					}std::cout << "Add a command:" << std::endl;
					std::cin.getline(command, ' ');
				} if (strcmp(command, "load") == 0) {
					const int MAXN = 20;
					char buffer[MAXN] = { 0 };
					std::ifstream Infile("Users.txt");
					std::ifstream Infile1("Challange.bin");
					if (Infile) {
						Infile.clear();
						Infile.seekg(0, std::ios::beg);
						while (!Infile.eof()) {

							Infile.getline(buffer, MAXN);

							if (Infile)
								std::cout << buffer;

							memset(buffer, 0, MAXN);
						}

						Infile.clear();
						Infile.seekg(0, std::ios::beg);
					} 
				}std::cout << "Add a command:" << std::endl; 
				std::cin.getline(command, ' ');
	} while (strcmp(command, "end") != 0);
	return 0;
}