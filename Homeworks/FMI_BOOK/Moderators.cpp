#include "Moderators.h"
#include "Posts.h"
#include <iostream>

void Moderators::blockpeople(const char* nick)
{
	Users user;
	user.setNick(nick);
	Posts post;
	post.getContent();
	std::cout << "Person" << nick << "is blocked from the system!" << std::endl;

}

void Moderators::unblockpeople(const char* nick)
{
	std::cout << "Person" << nick << "is unblocked from the system! He can post again!" << std::endl;

}
