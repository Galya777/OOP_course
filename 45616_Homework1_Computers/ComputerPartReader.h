#pragma once
#include "ComputerPart.h"
#include <istream>
class ComputerPartReader
{
public:
	ComputerPartReader(std::istream file);

	friend std::istream& operator>>(std::istream& in,const ComputerPart& other);
	virtual void readFromFile(std::istream& file);

	ComputerPart getNewPart() const;
private:
	std::istream oldFile;
	ComputerPart newPart;
};

