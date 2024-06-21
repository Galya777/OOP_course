#include "Car.h"
#include <iostream>

const char* Car::getBrand() const
{
    return brand;
}

const Type Car::getBack() const
{
    return back;
}

int Car::getPower() const
{
    return power;
}

int Car::getPlaces() const
{
    return places;
}

Date Car::getDate() const
{
    return date;
}

int Car::getAllPower() const
{
    return allPower;
}

void Car::printCar()
{
    std::cout << brand << " ";
    date.print();
    std::cout << " " << back << " " << power << " " << places;
}

void Car::printCar(std::ofstream& out)
{
    out << brand << " ";
    date.print(out);
    out << " " << back << " " << power << " " << places;
}

void Car::init(const char* brand, Date date, const Type back, int power, int places)
{
    setBrand(brand);
    setDate(date);
    this->back = back;
    setPower(power);
    setPlaces(places);
}

void Car::copy(const Car& other)
{
    init(other.getBrand(),other.getDate(),  other.getBack(), other.getPower(), other.getPlaces());
    this->allPower = other.allPower;
}

void Car::remove()
{
    delete[] brand;
}


Car::Car(std::ifstream& carData)
{
    allPower = 0;
    if (!carData) {
        throw "Problem with file!";
    }
    carData >> (char*)brand;
    date.readFromFile(carData);
    carData >> (char*)back >> power >> places;

    carData.close();
    allPower += power;
}

Car::Car(const char* brand, Date date, const Type back, int power, int places)
{
    allPower += power;
    init(brand, date, back, power, places);
    
}

Car::Car()
{
    Date date = Date();
    init("", date, Type::Hatchback, 0, 0);
    allPower = 0;
}

Car::Car(const Car& other)
{
    copy(other);
}

Car& Car::operator=(const Car& other)
{
    if (this != &other) {
        remove();
        copy(other);
    }
    return *this;
    // TODO: insert return statement here
}

Car::~Car()
{
    remove();
}

void Car::setBrand(const char* brand)
{
    this->brand = new char[strlen(brand) + 1];
    strcpy(this->brand, brand);
}

void Car::setPower(int power)
{
    this->power = power;
}

void Car::setPlaces(int places)
{
    this->places = places;
}

void Car::setDate(Date date)
{
    this->date.setDay(date.getDay());
    this->date.setMonth(date.getMonth());
    this->date.setYear(date.getYear());
}
