#include "ComputerPartReader.h"
const int MAX = 1000;
void ComputerPartReader::readFromFile(std::istream& file)
{
		file.seekg((0) * sizeof(ComputerPart) + sizeof(unsigned));
		file.read((char*)this, sizeof(ComputerPart));	
}


std::istream& operator>>(std::istream& in, ComputerPart& other)
{
	//find solution to this 
	//in >> other.getTypeText() >> other.getBrand() >> other.getModel() >> other.getYearGarantion()>> other.getPrice();
	return in;
}
