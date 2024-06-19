#include "Book.h"
#include <iostream>

Book::Book(const char* title, const char* author, unsigned char characteristic, unsigned char type, unsigned char targetAudience, bool parityControl, const char* description, int year)
{
	init(title, author, characteristic,type, targetAudience, parityControl, description, year);
	this->uniqueNumber = THIS_ID;
	THIS_ID++;
}

Book::Book()
{
	init(" ", " ", 0, 0,0, 0, 0, 0);

}

Book& Book::operator=(const Book& other)
{
	if (this != &other) {
		clear();
		copy(other);
	}
	return *this;
}


Book::~Book()
{
	clear();
}

void Book::setTitle(const char* title)
{
	this->title = new char[strlen(title) + 1];
	strcpy(this->title, title);
}

void Book::setAuthor(const char* author)
{
	this->author = new char[strlen(author) + 1];
	strcpy(this->author, author);
}

void Book::setGanre(unsigned char characteristic, unsigned char type, unsigned char targetAudience, bool parityControl)
{
	this->ganre = 0;

	// Побитово комбиниране на компонентите
	ganre |= (characteristic & 0x7F);      // Последните 7 бита за характеристика
	ganre |= ((type & 0x0F) << 7);         // Следващите 4 бита за тип
	ganre |= ((targetAudience & 0x0F) << 11);  // Следващите 4 бита за целева аудитория

	// Проверка за контрол по четност и задаване на контролния бит
	int count = __builtin_popcount(ganre); // Брой на единичните битове
	bool isEven = (count % 2 == 0);
	ganre |= ((isEven == parityControl) << 15); // Най-старшият бит за контрол по четност

}

void Book::setDescription(const char* description)
{
	this->description = new char[strlen(description) + 1];
	strcpy(this->description, description);
}

void Book::setYear(int year)
{
	this->year = year;
}

const char* Book::getTitle()
{
	return title;
}

const char* Book::getAuthor()
{
	return author;
}

uint16_t Book::getGanre()
{
	return ganre;
}

const char* Book::getDescription()
{
	return description;
}

const int Book::getYear()
{
	return year;
}



const int Book::getUnique()
{
	return uniqueNumber;
}

void Book::writeToFile(std::fstream& file) const
{
	file << title << " " << author << " " << ganre << " " << uniqueNumber;
}

void Book::printBook()
{
	std::cout << title << " " << author << " " << ganre << " " << uniqueNumber;
}

void Book::init(const char* title, const char* author, unsigned char characteristic, unsigned char type, unsigned char targetAudience, bool parityControl, const char* description, int year)
{
	setTitle(title);
	setAuthor(author);
	setGanre(characteristic, type, targetAudience, parityControl);
	setDescription(description);
	setYear(year);

}

void Book::copy(const Book& other)
{
	setTitle(other.title);
	setAuthor(other.author);
	this->ganre = other.ganre;
	setDescription(other.description);
	setYear(other.year);
}

void Book::clear()
{
	delete[] author;
	delete[] description;
	delete[] title;

}

std::ostream& operator<<(std::ostream& out, const Book& other)
{
	out << other.title << " " << other.author << " " << other.description << " " << other.ganre << " " << other.uniqueNumber;
	return out;
}