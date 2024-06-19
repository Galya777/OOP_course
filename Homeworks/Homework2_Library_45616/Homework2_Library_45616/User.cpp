#include "User.h"

void User::writeToFile(std::fstream& file) const
{
	file << username;
}

void User::init(const char* username)
{
	setUsername(username);
	numReadPublications = 0;
	readPublications = nullptr;
	currentPublications = nullptr;
	publicationCount = 0;
}

void User::copy(const User& other)
{
	setUsername(other.username);
}

void User::clear()
{
	delete[] username;
}

bool User::operator==(const User& other) const {
    return strcmp(username, other.username) == 0;
}

bool User::operator!=(const User& other) const {
    return strcmp(username, other.username) != 0;
}

bool User::operator<(const User& other) const {
    return numReadPublications < other.numReadPublications;
}

bool User::operator<=(const User& other) const {
    return numReadPublications <= other.numReadPublications;
}

bool User::operator>(const User& other) const {
    return numReadPublications > other.numReadPublications;
}

bool User::operator>=(const User& other) const {
    return numReadPublications >= other.numReadPublications;
}

const char* User::operator[](int publicationNumber) const {
    for (int i = 0; i < numReadPublications; ++i) {
        if (readPublications[i]->getLibraryNumber() == publicationNumber) {
            return "Already read";
        }
    }

    for (int i = 0; i < publicationCount; ++i) {
        if (currentPublications[i]->getLibraryNumber() == publicationNumber) {
            return "Currently borrowed";
        }
    }

    return "Never borrowed";
}

User& User::operator+=(int publicationNumber) {
    Publishing** newCurrentPublications = new Publishing*[publicationCount + 1];
    for (int i = 0; i < publicationCount; ++i) {
        newCurrentPublications[i] = currentPublications[i];
    }
    newCurrentPublications[publicationCount] = publicationNumber;

    delete[] currentPublications;
    currentPublications = newCurrentPublications;
    ++publicationCount;

    return *this;
}

User& User::operator-=(int publicationNumber) {
    for (int i = 0; i < publicationCount; ++i) {
        if (currentPublications[i]->getLibraryNumber() == publicationNumber) {
            for (int j = i; j < publicationCount - 1; ++j) {
                currentPublications[j] = currentPublications[j + 1];
            }
            --publicationCount;
            break;
        }
    }

    return *this;
}

User::User(const char* username)
{
	init(username);
}

User::User()
{
	init("");
}

User& User::operator=(const User& other)
{
	if (this != &other) {
		clear();
		copy(other);
	}
	return *this;
}

User::~User()
{
	clear();
}

void User::setUsername(const char* username)
{
	this->username = new char[strlen(username) + 1];
	strcpy(this->username, username);
}



char* User::getUsername() const
{
	return username;
}

Publishing** User::getBorrowedPublications() const
{
    return currentPublications;
}



std::ostream& operator<<(std::ostream& out, const User& other)
{
	out << other.username << " ";
	return out;

}