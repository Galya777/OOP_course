#include "ComputerStore.h"
#pragma warning(disable:4996)
void ComputerStore::referenceForWinnedMoney()
{
	std::cout << winnedMoney;
}
void ComputerStore::init(const char* name, const char* workingTime, float winnedMoney)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

	this->workingTime = new char[strlen(workingTime) + 1];
	strcpy(this->workingTime, workingTime);

	this->winnedMoney = winnedMoney;

	partst = new ComputerPart[sizeParts + 1];
}

void ComputerStore::copy(const ComputerStore& other)
{
	init(other.name, other.workingTime, other.winnedMoney);
}

void ComputerStore::clear()
{
	delete[] name;
	delete[] workingTime;
	delete[] partst;
}

ComputerStore::ComputerStore(const char* name, const char* workingTime, float winnedMoney)
{
	init(name, workingTime, winnedMoney);
}

ComputerStore::ComputerStore()
{
	init("", "00:00", 0);
}

ComputerStore& ComputerStore::operator=(const ComputerStore& other)
{
	if (this != &other) {
		copy(other);
		clear();
	}
	return *this;
	// TODO: insert return statement here
}

ComputerStore::~ComputerStore()
{
	clear();
}

char* ComputerStore::getName() const
{
	return name;
}

char* ComputerStore::getWorkingTime() const
{
	return workingTime;
}

float ComputerStore::getWinned() const
{
	return winnedMoney;
}

int ComputerStore::getSize() const
{
	return sizeParts;
}

ComputerPart* ComputerStore::getParts() const
{
	return partst;
}

void ComputerStore::addPart(ComputerPart newPart)
{
	partst[sizeParts] = newPart;
	sizeParts++;
}

