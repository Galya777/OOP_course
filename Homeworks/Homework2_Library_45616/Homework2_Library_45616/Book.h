#pragma once
#pragma warning(disable:4996)
#include <cstring>
#include <fstream>
#include <vector>
#include <string>
static int THIS_ID = 0;
class Book
{
public:
	Book(const char* title, const char* author, unsigned char characteristic, unsigned char type, unsigned char targetAudience, bool parityControl, const char* description, int year);
	Book();
	Book& operator=(const Book& other);
	~Book();

	void setTitle(const char* title);
	void setAuthor(const char* author);
	void setGanre(unsigned char characteristic, unsigned char type, unsigned char targetAudience, bool parityControl);
	void setDescription(const char* description);
	void setYear(int year);

	const char* getTitle();
	const char* getAuthor();
	uint16_t getGanre();
	const char* getDescription();
	const int getYear();
	const int getUnique();


	friend std::ostream& operator<<(std::ostream& out, const Book& other);
	virtual void writeToFile(std::fstream& file) const;

	void printBook();
private:
	void init(const char* title, const char* author, unsigned char characteristic, unsigned char type, unsigned char targetAudience, bool parityControl, const char* description, int year);
	void copy(const Book& other);
	void clear();

	char* title;
	char* author;
	uint16_t ganre;
	char* description;
	int year;
	int uniqueNumber;
};

