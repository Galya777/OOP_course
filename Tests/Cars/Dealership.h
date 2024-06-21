#pragma once
#include "Car.h"
struct StockCar {
	Car car;
	double price;
};
class Dealership
{
public:
	Dealership(int capacity);
	~Dealership();

	void add(StockCar newCar);
	void sell(int soldCar);

	void addToStatisticks(StockCar newCar);
	void printStatistics();

	void checking(const char* brand);
	void checking(double maxPrice);
	void checkingDate(int date);

private:
	StockCar* cars;
	int size;
	StockCar* statistics;

	int capacity;
};

