#pragma once
#include "BasicForStoreAndConfig.h"

class Configuration:public BasicForStoreAndConfig
{
public:
	Configuration(Component comp, double price);
	Configuration();
	void addComponent(Component comp);
protected:
	virtual bool RepeatingTypes(Component comp);
	double CalculatePrice();
private:
	double price;
};

