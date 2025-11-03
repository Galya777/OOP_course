#include "ComputerPart.h"
#pragma warning(disable:4996)
void ComputerPart::init(int type, int years, float price, const char* brand, const char* model)
{
	//validate and initialize the type
	while (type < 0 || type>6) {
		std::cout << "Invalid type! Try again!";
		std::cin >> type;
	}
	setType(type); //giving the value of type 

	//validate and initialize the years of garantion
	while (years < 0) {
		std::cout << "Invalid years! Try again!";
		std::cin >> years;
	}
	this->yarsGarantion = years;

	setPrice(price);

	this->brand = new char[strlen(brand) + 1];
	strcpy(this->brand, brand);

	this->model = new char[strlen(model) + 1];
	strcpy(this->model, model);
}

void ComputerPart::copy(ComputerPart& other)
{
	this->type = other.type;
	this->yarsGarantion = other.yarsGarantion;
	this->price = other.price;
	strcpy(this->brand,other.brand);
	strcpy(this->model,other.model);
}

void ComputerPart::clear()
{
	delete[] brand;
	delete[] model;
}

void ComputerPart::setType(int type)
{
	switch (type) {
	case 0: this->type=MONITOR; break;
	case 1: this->type=COMPUTER; break;
	case 2: this->type=LAPTOP; break;
	case 3: this->type=MOUSE; break;
	case 4: this->type=KEYBOARD; break;
	case 5: this->type=HEADPHONES; break;
	case 6: this->type=CAMERA; break;
	}
}

ComputerPart::ComputerPart(int type, int years, float price, const char* brand, const char* model)
{
	init(type, years, price, brand, model);
}

ComputerPart::ComputerPart()
{
	init(-1, 0, 0.0, "", "");
}

ComputerPart::ComputerPart(ComputerPart& other)
{
	copy(other);
}

ComputerPart ComputerPart::operator=(ComputerPart& other)
{
	if (this != &other)
	{

		clear();

		copy(other);
	}

	return *this;
}

ComputerPart::~ComputerPart()
{
	clear();
}

TYPE ComputerPart::getType() const
{
	return type;
}

const char* ComputerPart::getTypeText() const
{
	switch (type) {
	case MONITOR: return "MONITOR"; break;
	case COMPUTER: return "COMPUTER"; break;
		case LAPTOP: return "LAPTOP"; break;
		case MOUSE: return "MOUSE"; break;
		case KEYBOARD: return "KEYBOARD"; break;
		case HEADPHONES: return "HEADPHONES"; break;
		case CAMERA: return "CAMERA"; break;
	}
	return "";
}

int ComputerPart::getYearGarantion() const
{
	return yarsGarantion;
}

float ComputerPart::getPrice() const
{
	return price;
}

char* ComputerPart::getBrand() const
{
	return brand;
}

char* ComputerPart::getModel() const
{
	return model;
}

void ComputerPart::setPrice(float newPrice)
{
	//validate and initialize the price
	while (newPrice < 0) {
		std::cout << "Invalid price! Try again!";
		std::cin >> newPrice;
	}
	this->price = newPrice;
}
