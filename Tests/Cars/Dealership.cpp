#include "Dealership.h"
#include <iostream>

Dealership::Dealership(int capacity)
{
	this->capacity = capacity;
	this->cars = new StockCar[capacity];
	this->size = 0;
	this->statistics = new StockCar[capacity];
}

Dealership::~Dealership()
{
	delete[] cars;
	delete[] statistics;
}

void Dealership::addToStatisticks(StockCar newCar)
{
	if (size<capacity) {
		statistics[size] = newCar;
		++size;
	}
	else {
		throw "No more space!";
	}
}

void Dealership::printStatistics()
{
	double allPrice = 0;
	std::cout << "Cars sold: " << size << "/n";
	for (size_t i = 0; i < size; i++)
	{
		cars[i].car.printCar();
		allPrice += cars[i].price;
	}
	std::cout << "Total price for all sold cars is: " << allPrice << "/n";
}

void Dealership::checking(const char* brand)
{
	for (size_t i = 0; i < capacity; i++)
	{
		if (strcmp(cars[i].car.getBrand(), brand) == 0) {
			cars[i].car.printCar();
			std::cout << cars[i].price;
		}
	}
}

void Dealership::checking(double maxPrice)
{
	for (size_t i = 0; i < capacity; i++)
	{
		if (cars[i].price<= maxPrice) {
			cars[i].car.printCar();
			std::cout << cars[i].price;
		}
	}
}

void Dealership::checkingDate(int date)
{
	for (size_t i = 0; i < capacity; i++)
	{
		if (cars[i].car.getDate().getYear()>= date) {
			cars[i].car.printCar();
			std::cout << cars[i].price;
		}
	}
}

void Dealership::add(StockCar newCar)
{
	bool added = false;
	for (size_t i = 0; i < capacity; i++)
	{
		if (cars[i].price == 0) {
			cars[i] = newCar;
			added = true;
			break;
		}
	}
	if (!added) {
		throw "No more space!";
	}
}

void Dealership::sell(int soldCar)
{
	if (soldCar >= capacity) {
		throw "Invalid position!";
	}
	else if (cars[soldCar].price == 0) {
		throw "There is no car parked here!";
	}
	else {
		addToStatisticks(cars[soldCar]);
		StockCar deff;
		deff.car = Car();
		deff.price = 0;
		cars[soldCar] = deff;
		
	}
}
