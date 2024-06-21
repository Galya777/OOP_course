#pragma once
#include <vector>
#include "Cell.h"
#include <fstream>
const int MAX = 1000;// random value for max cells
class Table
{
public:
	Table(Cell& cell);
	Table();

	int getRow() const;
	int getCol() const;
    int maxCellsPerRow() const; //also copied function 
	

	void manageLine(const int curRow, const char* buff);//this function is copied from internet. The idea is to put the information line by line
	virtual void readFromFile(std::ifstream& file);
	virtual void writeToFile(std::fstream& file);
	void editTableCell(int row, int col, const char* filling);
	virtual void printElement(int i, int j);
private:
	std::vector<std::vector<Cell>> table;//I use two dimentional vector to put the cells in the table 
	int row;
	int col;
	
};

