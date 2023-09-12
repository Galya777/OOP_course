#pragma once
#include <vector>
#include "Component.h"
#include <typeinfo>
#include<fstream>
class BasicForStoreAndConfig:public Component
{
public:
	BasicForStoreAndConfig();
	
	Component getComponent(int i);
	const std::vector <Component> getComponents();
	const int getSize();
	virtual void writeToFile(std::fstream& file);
	void printConfig();
protected:
	std::vector<Component> components;
	int size = 0;

};

