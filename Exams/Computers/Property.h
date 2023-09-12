#pragma once
#include <string>
class Property
{
public:
	Property(const std::string name, const int quantiny, const double price);
	Property();
	const std::string getName();
	const int getQuantity();
	const double getPriceM();

	void setName(std::string name);
	void setQuantity(int q);
	void setPriceMultiplier(double prM);
	void enterProperty();
	virtual void writeToFile(std::fstream& file);
	void printProperty();
private:
	  std::string name;
	 int quantity;
	 double priceMultiplier;
};

