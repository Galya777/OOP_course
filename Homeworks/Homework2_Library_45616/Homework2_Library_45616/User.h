#pragma once
#pragma warning(disable:4996)
#include <cstring>
#include <iostream>
#include <fstream>
#include "Publishing.h"
class User
{
public:
	User(const char* username);
	User();
	User& operator=(const User& other);
	~User();

	bool operator==(const User& other) const;
	bool operator!=(const User& other) const;
	bool operator<(const User& other) const;
	bool operator<=(const User& other) const;
	bool operator>(const User& other) const;
	bool operator>=(const User& other) const;
	const char* operator[](int publicationNumber) const;
	User& operator+=(int publicationNumber);
	User& operator-=(int publicationNumber);

	void setUsername(const char* username);


	char* getUsername() const;
	Publishing** getBorrowedPublications() const;
	
	friend std::ostream& operator<<(std::ostream& out, const User& other);
	virtual void writeToFile(std::fstream& file) const;

	

private:
	void init(const char* username);
	void copy(const User& other);
	void clear();


	char* username;
	int numReadPublications;
	Publishing** readPublications;
	Publishing** currentPublications;
	int publicationCount;


};
