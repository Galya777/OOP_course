#pragma once
#include <iostream>
enum TYPE {
	UNDEFINED=-1,
MONITOR, 
COMPUTER,
LAPTOP,
MOUSE,
KEYBOARD, 
HEADPHONES, 
CAMERA
	};
class ComputerPart
{
public:
	ComputerPart(int type, int years, float price, const char*brand, const char* model);
	ComputerPart();
	ComputerPart(ComputerPart& store);
	ComputerPart operator=(ComputerPart& other);
	~ComputerPart();

	TYPE getType() const;
	const char* getTypeText() const;
	int getYearGarantion() const;
	float getPrice() const;
	char* getBrand() const;
	char* getModel() const;

	void setPrice(float newPrice);


private:
	void init(int type, int years, float price, const char* brand, const char* model);
	void copy(ComputerPart& other);
	void clear();

	void setType(int type);
		
	TYPE type;
	int yarsGarantion;
	float price;
	char* brand;
	char* model;


};

