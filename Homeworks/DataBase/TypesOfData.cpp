#include "TypesOfData.h"

TypesOfData::TypesOfData(size_t size, const Data& data):
	data(data)
{
	sizeofData = size;
}

TypesOfData::TypesOfData()
{
	sizeofData = 0;
}

size_t TypesOfData::getSize()
{
	return sizeofData;
}
