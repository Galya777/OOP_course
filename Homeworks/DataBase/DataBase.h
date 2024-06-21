#pragma once
#include "Table.h"
#include <vector>
#include <iostream>
#include <exception>
struct SingleTable {
     Table tables;
     std::string tableName;
	};
class DataBase
{
public:
	DataBase(Table& table, std::string name);
	DataBase();

	void addTable(Table& table, std::string name);

	void import(std::ifstream& fileName);
	void printAll();
	void printByName(std::string name);
	void describe(std::string name);
	void exportTable(std::string name, std::fstream& out);
	void select(int colomn, TypesOfData& value, std::string name);
	void addColumn(std::string name, std::string Columnname, std::string type);
	void update(std::string name, int i, int j, std::string newValue);
	void del(std::string name);
	void rename(std::string oldName, std::string newName);
	void count();
	


protected:
	int FindByName(std::string name);
	std::vector<SingleTable> Alltables;
	int size=0;
};

