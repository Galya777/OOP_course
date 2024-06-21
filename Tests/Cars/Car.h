#pragma once
#include <fstream>
#include "Date.h"
#pragma warning(disable:4996)
enum Type {
	Sedan,
	Kombi,
	Hatchback
};
class Car
{
public:
	Car(std::ifstream& carData);
	Car(const char* brand, Date date,  const Type back,	int power, int places);
	Car();
	Car(const Car& other);
	Car& operator=(const Car& other);
	~Car();


	void setBrand(const char* brand);
	void setPower(int power);
	void setPlaces(int places);
	void setDate(Date date);

	const char* getBrand() const;
	const Type getBack() const;
	int getPower() const;
	int getPlaces() const;
	Date getDate() const;
	

	int getAllPower() const;

	void printCar();
	void printCar(std::ofstream& out);

private:
	void init(const char* brand,Date date, const Type back, int power, int places);
	void copy(const Car& other);
	void remove();


	char* brand;
	Date date;
    Type back;
	int power;
	int places;

	int allPower;
};

