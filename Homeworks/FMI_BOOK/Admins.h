#pragma once
#include"Users.h"
#include "Moderators.h"
class Admins :public Moderators
{
public:
	void deletepeople(const char* nick, int age);
	void addpeople(const char* nick, int age);
	void setStatus(const char* status,const char*nick);
};

