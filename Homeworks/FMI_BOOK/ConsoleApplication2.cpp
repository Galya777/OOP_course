#include <iostream>
#include "Posts.h"
#include "Picture.h"
#include "Admins.h"
#include <fstream>
const char MAX_NICK = 100;
const int MAX_COMMAND = 50;
int main()
{
	Admins admin;
	Posts post;
	std::ofstream out;
	char filename[MAX_NICK];
	char nick[MAX_NICK];
	char type[MAX_COMMAND];
	char status[MAX_COMMAND];
	char content[MAX_NICK];
	int age;
	std::cout << "Set admin's nick name and age!" << std::endl;
	std::cin.getline(nick, MAX_NICK);
	std::cin >> age;
	admin.setNick(nick);
	admin.setAge(age);
	char command[MAX_COMMAND];
	std::cout << "Set command!" << std::endl;
	std::cin.ignore();
	std::cin.getline(command, MAX_COMMAND);
	do {
		if (strcmp(command, "add") == 0) {
			std::cout << "Enter status, nickname and age to the person!" << std::endl;
			std::cin.getline(status, MAX_COMMAND);
			std::cin.getline(nick, MAX_NICK);
			std::cin >> age;
			admin.setStatus(status, nick);
			admin.addpeople(nick, age);
			std::cout << "Admin adds successfully" << status << nick << age << std::endl;
		} if (strcmp(command, "remove") == 0) {
			std::cin.getline(nick, MAX_NICK);
			std::cin >> age;
			admin.deletepeople(nick, age);
			std::cout << "Admin deletes successfully" << nick << age << std::endl;
		} if (strcmp(command, "block") == 0) {
			std::cin.getline(nick, MAX_NICK);
			admin.blockpeople(nick);
			std::cout << "Admin blockes successfully" << nick << std::endl;
		} if (strcmp(command, "unblock") == 0) {
			std::cin.getline(nick, MAX_NICK);
			admin.unblockpeople(nick);
			std::cout << "Admin unblockes successfully" << nick << std::endl;
		} if (strcmp(command, "add post") == 0) {
			Users user;
			std::cin.getline(content, MAX_NICK);
			std::cin.getline(type, MAX_COMMAND);
			std::cin.getline(filename, MAX_NICK);
			out.open(filename);
			user.addPost(type, filename, content);
			post.writeInFile(out, post);
		} if (strcmp(command, "remove post") == 0) {
			Users user;
			int numofpost;
			std::cin >> numofpost;
			user.deletePost(numofpost);
		} if (strcmp(command, "info") == 0) {
			out.open(filename);
		}
	} while (strcpy(command, "quit") != 0);
	

	return 0;
}

