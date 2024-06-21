#pragma once
#include <cstddef>
enum Data {
	UNKNOWN=-1,
	EMPTY,
	INTIGER,
	DOUBLE, 
	FORMULA,
	STRING
};
class TypesOfData
{
public:
	TypesOfData(size_t size, const Data& data=EMPTY);
	TypesOfData();
    size_t getSize();
protected:
	Data data;
	std::size_t sizeofData;
};

