#include "DataBase.h"

DataBase::DataBase(Table& table, std::string name)
{
	addTable(table, name);
}

DataBase::DataBase()
{
	Alltables.at(size).tables = Table();
	Alltables.at(size).tableName = "";
	++size;
}

void DataBase::addTable(Table& table, std::string name)
{
	Alltables.at(size).tables = table;
	Alltables.at(size).tableName = name;
	++size;
}

void DataBase::import(std::ifstream& fileName)
{
	fileName >> Alltables.at(size).tableName;
	Alltables.at(size).tables.readFromFile(fileName);
}

void DataBase::printAll()
{
	for (int i = 0; i < size; ++i) {
		std::cout << Alltables.at(i).tableName << "\n";
		std::cout << Alltables.at(i).tables.getRow() << "\t" << Alltables.at(i).tables.getCol();
	}
}

void DataBase::printByName(std::string name)
{
	int needed = FindByName(name);
	if (needed > 0) {
		std::cout << Alltables.at(needed).tableName << "\n";
		std::cout << Alltables.at(needed).tables.getRow() << "\t" << Alltables.at(needed).tables.getCol();
	}
	else {
		std::cout << "No table with this name here!";
	}
}

void DataBase::describe(std::string name)
{
	int needed = FindByName(name);
	if (needed > 0) {
		std::cout << Alltables.at(needed).tables.getCol();
	}
	else {
		std::cout << "No table with this name here!";
	}
}

void DataBase::exportTable(std::string name, std::fstream& out)
{
	int needed = FindByName(name);
	if (needed > 0) {
	out << Alltables.at(needed).tableName << "\n";
	Alltables.at(needed).tables.writeToFile(out);
	}
	else {
		std::cout << "No table with this name here!";
	}
}

void DataBase::select(int colomn, TypesOfData& value, std::string name)
{
	int needed = FindByName(name);
	if (needed > 0) {
		std::cout << Alltables.at(needed).tableName << "\n";
		
	}
	else {
		std::cout << "No table with this name here!";
	}
}

void DataBase::addColumn(std::string name, std::string Columnname, std::string type)
{
	int needed = FindByName(name);
	if (needed > 0) {
	 Alltables.at(needed).tables.editTableCell(Alltables.at(needed).tables.getRow(), Alltables.at(needed).tables.getCol()+1, type.c_str());

	}
	else {
		std::cout << "No table with this name here!";
	}
}

void DataBase::update(std::string name, int i, int j, std::string newValue)
{
	int needed = FindByName(name);
	if (needed > 0) {
		Alltables.at(needed).tables.editTableCell(i, j, newValue.c_str());

	}
	else {
		std::cout << "No table with this name here!";
	}
}

void DataBase::del(std::string name)
{
	int needed = FindByName(name);
	if (needed > 0) {
		Alltables.erase(Alltables.begin()+needed);

	}
	else {
		std::cout << "No table with this name here!";
	}

}

int DataBase::FindByName(std::string name)
{
	for (int i = 0; i < size; ++i) {
		if (Alltables.at(i).tableName==name) {
			return i;
		}
	}
	return -1;
}

void DataBase::rename(std::string oldName, std::string newName)
{
	int needed = FindByName(oldName);
	if (needed > 0) {
	 Alltables.at(needed).tableName= newName;

	}
	else {
		std::cout << "No table with this name here!";
	}
}

void DataBase::count()
{
	std::cout << size;
}
