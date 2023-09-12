#pragma once
#include <fstream>
#include <iostream>
#include <stdio.h>
#include "Store.h"
const int MAX = 100;
class Store_Builder: public BasicForStoreAndConfig
{
public:
	
	Store_Builder();
	~Store_Builder();

    const Store ReturnStore();
	void readFromFile(std::string path);
	void save(char* file);
protected:	
	void addToStore(std::string typeofComponent);
	

private:
	Store store;
	Cpu cpu;
	Ram ram;
	Hdd hdd;
	int size;
	char** type;
};

