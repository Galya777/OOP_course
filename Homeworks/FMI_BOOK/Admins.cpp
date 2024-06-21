#include "Admins.h"
#include <iostream>

void Admins::deletepeople(const char* nick, int age)
{
	std::cout << "Person" << nick << "is deleted from the system!" << std::endl;
	setNick(nick);
	setAge(age);
	delete[] nickname;
}

void Admins::addpeople(const char* nick, int age)
{
	std::cout << "Person" << nick << "is added from the system!" << std::endl;
	setNick(nick);
	setAge(age);
}

void Admins::setStatus(const char* status, const char* nick)
{
	if (strcmp(status, "user") == 0) {
		Users user;
		user.setNick(nick);
	} else if (strcmp(status, "moderator") == 0) {
		Moderators moderator;
		moderator.setNick(nick);
	}
}
