#pragma once
#include "ComputerStore.h"
#include "ComputerPartWriter.h"
class ComputerStoreWriter
{
public:
	ComputerStoreWriter(ComputerStore store);

	friend std::ostream& operator<<(std::ostream& out, const ComputerPart& other);
	virtual void writeToFile(std::ostream& file) const;
private:
	ComputerStore store;
};

