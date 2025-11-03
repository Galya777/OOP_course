#include "ComputerStoreWriter.h"

ComputerStoreWriter::ComputerStoreWriter(ComputerStore store)
{
	this->store = store;
}
std::ostream& operator<<(std::ostream& out, const ComputerStore& other)
{
	out << other.getName() << "\n" << other.getWorkingTime() << "\n" << other.getSize();
	for (int i = 0; i < other.getSize(); ++i) {
		ComputerPart part= other.getParts()[i];
		ComputerPartWriter write(part);		
		 write.writeToFile(out);
	}
	return out;
}

void ComputerStoreWriter::writeToFile(std::ostream& file) const
{
	file << store.getName() << "\n" << store.getWorkingTime()<<"\n"<<store.getSize();
	for (int i = 0; i < store.getSize();++i) {
		ComputerPart part = store.getParts()[i];
		ComputerPartWriter write(part);
		write.writeToFile(file);
	}
}
