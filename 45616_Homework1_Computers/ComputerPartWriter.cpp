#include "ComputerPartWriter.h"

std::ostream& operator<<(std::ostream& out, const ComputerPart& other)
{
	out << other.getTypeText() << " " <<other.getBrand()<<" "<<other.getModel()<<" "<<other.getYearGarantion()<<" "<<other.getPrice();
	return out;
}

ComputerPartWriter::ComputerPartWriter(ComputerPart part)
{
	partToWrite.operator=(part);
	
}

void ComputerPartWriter::writeToFile(std::ostream& file) const
{
	file<< partToWrite.getTypeText() << " " << partToWrite.getBrand() << " "
		<< partToWrite.getModel() << " " << partToWrite.getYearGarantion() << " " << partToWrite.getPrice();
}
