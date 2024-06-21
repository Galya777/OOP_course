#include "Users.h"
#include <cstring>
#include <iostream>

Users::Users(const char* name1, int age1, const char* email1)
{
	init(name1, age1, email1);
	this->id = THIS_ID;
	THIS_ID++;
}

Users::Users()
{
	init("", 0, "");
}

Users::Users(const Users& other)
{
	copy(other);
}

Users& Users::operator=(const Users& other)
{
	if (this != &other) {
		del();
		copy(other);
	}
	return *this;
}

Users::~Users()
{
	del();
}

bool Users::isvalidAge()
{
	if (m_age > 90) {
		return false;
	}
	return true;
}

void Users::init(const char* name, int age, const char* email)
{
	m_name = new char[strlen(name) + 1];
	setemail(email);
	strcpy(m_name, name);
	m_age = age;
}

void Users::copy(const Users& other)
{
	m_name = new char[strlen(other.m_name) + 1];
	strcpy_s(m_email, other.m_email);
	strcpy(m_name, other.m_name);
	m_age = other.m_age;
}

void Users::del()
{
	delete[] m_name;
}

void Users::setemail(const char* email)
{
	
	strcpy_s(m_email, email);
}

void Users::setName(const char* name)
{
	m_name = new char[strlen(name) + 1];
	strcpy(m_name, name);
}

void Users::setAge(int age)
{
	m_age = age;
}

const char* Users::getName() const
{
	return m_name;
}

const char* Users::getEmail() const
{
	return m_email;
}

 char* Users::adding(char*name) const
{
		std::cin >> name;
		return name;
}

int Users::getAge() const
{
	return m_age;
}

int Users::getId() const
{
	return id;
}
