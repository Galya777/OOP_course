#pragma once
#include "ComputerPart.h"
class Configuration
{
public:
	Configuration();

	ComputerPart getPartAt(int index);
	int getSize() const;
private:
	ComputerPart* parts;
	int size;
};

