#include <cstring>
#include "Beer1.h"

Beer::Beer()
{
	strcpy(brand, " ");
	volume = 0;
}

Beer::Beer(const char* br, int vol)
{
	setBrand(br);
	setVolume(vol);
}

void Beer::setBrand(const char* brand)
{
	strcpy(this->brand, brand);
}

void Beer::setVolume(int vol)
{
	this->volume = vol;
}

const char* Beer::getBrand()
{
	return this->brand;
}

int Beer::getVolume()
{
	return this->volume;
}

void Beer::add(Beer beer1, Beer beer2, int volume)
{
	char beer[] = beer1.brand + beer2.brand;
	int volume = beer1.volume + volume;
	cout << beer << " " << volume << endl;
	cout << beer2 <<" "<< beer2.volume << endl;
}

bool Beer::check(Beer beer1, Beer beer2)
{
	if (beer1.getBrand()) {
		return true;
	}
	else if (beer1 == beer2) {
		return true;
	}
	return false;
}


