#include "Users.h"

Users::Users(const char* nick, int age)
{
	init(nick, age);
}

Users::Users()
{
	init("",0);
}

Users Users::operator=(const Users& other)
{
	if (this != &other)
	{

		dell();

		copy(other);
	}

	return *this;
}

Users::~Users()
{
	dell();
}

void Users::setNick(const char* nick)
{
	nickname = new char[strlen(nick) + 1];
	strcpy(nickname, nick);
}

void Users::setAge(int m_age)
{
	age = m_age;
}

char* Users::getNick()
{
	return nickname;
}

int Users::getAge()
{
	return age;
}

void Users::addPost(const char* type, const char*file, const char* cont)
{
	if (strcmp(type, "picture") == 0) {
		Picture newPicture;
		newPicture.makePicture(file,cont);
	}
	else if (strcmp(type, "link") == 0) {
		Link newlink;
		newlink.makeLink(file, cont, cont);
	} if (strcmp(type, "text") == 0) {
		Posts newPost;
		newPost.makeText(file,cont);
	}
}

void Users::deletePost(int id)
{
	Posts post;
	if (post.getid() == id) {
		post.~Posts();
	}
}

void Users::changeNick(const char* newNick)
{
	delete[] nickname;
	nickname = new char[strlen(newNick) + 1];
	strcpy(nickname, newNick);
}

void Users::init(const char* nick, int age)
{
	nickname = new char[strlen(nick) + 1];
	age = age;
	strcpy(nickname,nick);
}

void Users::copy(const Users& other)
{
	nickname = new char[strlen(other.nickname) + 1];
	strcpy(nickname, other.nickname);
	age = other.age;
}

void Users::dell()
{
	delete[] nickname;
}
