#include "Publishing.h"
#include <iostream>

Publishing::Publishing(const char* title, const char* description, int year)
{
	setTitle(title);
	setDescription(description);
	setYear(year);
}

Publishing::Publishing()
{
	setTitle("");
	setDescription("");
	setYear(0);
}

Publishing::Publishing(Publishing& other)
{
	setTitle(other.title);
	setDescription(other.description);
	setYear(other.year);
}

void Publishing::setTitle(const char* title)
{
	this->title = new char[strlen(title) + 1];
	strcpy(this->title, title);
}
void Publishing::setDescription(const char* description)
{
	this->description = new char[strlen(description) + 1];
	strcpy(this->description, description);
}

void Publishing::setYear(int year)
{
	this->year = year;
}
void Publishing::readFromFile(std::ifstream& file) const
{
	file.read((char*)uniqueNumber, sizeof(uniqueNumber));
	file.read((char*)title, sizeof(title));
	file.read((char*)description, sizeof(description));

}

void Publishing::writeToFile(std::fstream& file) const
{
	file << title << " " << "publishing seria" << " " << uniqueNumber;
}

void Publishing::print() const
{
	std::cout << title << " " << "publishing seria" << " " << uniqueNumber;
}

bool Publishing::isBorrowed()
{
	return false;
}
