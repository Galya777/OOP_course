#pragma once
#include<cstring>
#pragma warning(disable:4996)
#include "Publishing.h"
class Comics : public Publishing {

public:
    Comics(const char* title, const char* description, int libraryNumber, int year,
        const char* author, const char* publisher, unsigned short genre,
        const char* periodicity, int count)
        : Publishing(title, description, libraryNumber, year), genre(genre), count(count) {
        this->author = new char[strlen(author) + 1];
        strcpy(this->author, author);

        this->publisher = new char[strlen(publisher) + 1];
        strcpy(this->publisher, publisher);

        this->periodicity = new char[strlen(periodicity) + 1];
        strcpy(this->periodicity, periodicity);
    }

    ~Comics() {
        delete[] author;
        delete[] publisher;
        delete[] periodicity;
    }

    const char* getType() const override { return "Comics"; }

    

private:
    char* author;
    char* publisher;
    unsigned short genre;
    char* periodicity;
    int count;

};

