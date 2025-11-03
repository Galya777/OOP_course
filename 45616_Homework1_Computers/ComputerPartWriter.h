#pragma once
#include "ComputerPart.h"
#include <fstream>
class ComputerPartWriter
{
public:

	ComputerPartWriter(ComputerPart part);
	
	friend std::ostream& operator<<(std::ostream& out, const ComputerPart& other);
	virtual void writeToFile(std::ostream& file) const;

private:
	ComputerPart partToWrite;
};

