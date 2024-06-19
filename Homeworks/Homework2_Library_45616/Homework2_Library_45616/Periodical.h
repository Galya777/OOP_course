#pragma once
#include "Publishing.h"
#include <cstring>
#pragma warning(disable:4996)
class Periodical : public Publishing {
private:
    char* periodicity;
    int count;

public:
    Periodical(const char* title, const char* description, int libraryNumber, int year,
        const char* periodicity, int count)
        : Publishing(title, description, libraryNumber, year), count(count) {
        this->periodicity = new char[strlen(periodicity) + 1];
        strcpy(this->periodicity, periodicity);
    }

    ~Periodical() {
        delete[] periodicity;
    }

    const char* getType() const override { return "Periodical"; }

};

