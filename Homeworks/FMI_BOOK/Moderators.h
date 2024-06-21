#pragma once
#include "Users.h"
class Moderators :public Users
{
public:
	void blockpeople(const char* nick);
	void unblockpeople(const char* nick);
};

