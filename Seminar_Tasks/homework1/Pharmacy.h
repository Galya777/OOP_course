#pragma once
#include "Medicine.h"
class Pharmacy
{
public: 
	void add(const char name[SIZE]);
	void addquantity(double more);
	void deletemedicine(const char newname[SIZE]);
	char* find(const char newname[SIZE]);
	double buy(const char newname[SIZE]);
	

private:
	Medicine medicine;
};

