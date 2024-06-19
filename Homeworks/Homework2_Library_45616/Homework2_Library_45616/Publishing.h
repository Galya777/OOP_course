#pragma once
#include <cstring>
#include <fstream>
class Publishing {

public:
    Publishing(const char* title, const char* description, int year);
    Publishing();
    Publishing(Publishing& other);
    virtual ~Publishing() {
        delete[] title;
        delete[] description;
    }

    //setters
    void setTitle(const char* title);
    void setDescription(const char* description);
    void setYear(int year);

    //getters
    const char* getTitle() const { return title; }
    const char* getDescription() const { return description; }
    int getLibraryNumber() const { return uniqueNumber; }
    int getYear() const { return year; }

    void readFromFile(std::ifstream& file) const;
    void writeToFile(std::fstream& file) const;
    void print() const;
    virtual const char* getType() const = 0;
    bool isBorrowed();

protected:
    char* title;
    char* description;
    int uniqueNumber;
    int year;
};