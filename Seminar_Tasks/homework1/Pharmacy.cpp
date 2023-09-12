#include "Pharmacy.h"
#include "Medicine.h"
#include <iostream>
Medicine medicine;
void Pharmacy::add(const char newname[SIZE])
{
	medicine.name[SIZE] += newname[SIZE];
}

void Pharmacy::addquantity(double more)
{
	medicine.quantity += more;
}
void Pharmacy::deletemedicine(const char newname[SIZE])
{
	if (medicine.name == newname) {
		delete[] medicine.name;
		}
}

char* Pharmacy::find(const char newname[SIZE])
{
	if (newname == medicine.name) {
		return medicine.name;
	}
	else {
	std::cout << "There is no such medicine here.";
	}
}

double Pharmacy::buy(const char newname[SIZE])
{
	if (medicine.name[SIZE] = newname[SIZE]) {
		return medicine.quantity;
	}
}




