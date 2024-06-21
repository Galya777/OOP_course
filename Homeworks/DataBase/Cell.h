#pragma once
#include "TypesOfData.h"
#include <cstring>
#include <fstream>
class Cell:public TypesOfData
{
public:
	Cell(const char* content);
	Cell();
	Cell operator=(Cell& other);
	~Cell();

	void fillCell(const char* fill);
	friend std::ostream& operator<<(std::ostream& out, const Cell& other);
	virtual void writeToFile(std::fstream& file) const;
	virtual void editCell(const char* NewContent);
	virtual void print() const;
	void setSize();
	Data findType(const char* _content);

	
	bool operation(char& sym);
protected:

	char* content; 
	Data typeOfCell;
private:
	void init(const char* content);
	void copy(Cell& other);
	void clear();
};

