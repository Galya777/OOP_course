#pragma once
#pragma warning(disable:4996)
#include<cstring>
#include "Posts.h"
#include"Picture.h"
#include "Link.h"
class Users
{
public:
	Users(const char* nick, int age);
	Users();
	Users operator=(const Users& other);
	~Users();
	void setNick(const char* nick);
	void setAge(int m_age);
	char* getNick();
	int getAge();
	void addPost(const char* type,const char* file, const char* cont);
	void deletePost(int id);
	void changeNick(const char*newNick);
protected:
	void init(const char* nick, int age);
	void copy(const Users&other);
	void dell();
	char* nickname;
	int age;
};

