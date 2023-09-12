#include "BasicForStoreAndConfig.h"
#include <iostream>

BasicForStoreAndConfig::BasicForStoreAndConfig()
{
	components.push_back(Component());
}
Component BasicForStoreAndConfig::getComponent(int i)
{
	return components.at(i);
}

const std::vector<Component> BasicForStoreAndConfig::getComponents()
{
	return components;
}

const int BasicForStoreAndConfig::getSize()
{
	return size;
}

void BasicForStoreAndConfig::writeToFile(std::fstream& file)
{
	for (size_t i = 0; i < components.size(); i++)
	{
			components.at(i).writeToFile(file);
		    file << "\n";
	}

}

void BasicForStoreAndConfig::printConfig()
{
	for (size_t i = 0; i < components.size(); i++)
	{
		components.at(i).printComponents();
		std::cout << "\n";
	}
}
