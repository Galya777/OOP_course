#pragma once
#include "ComputerPart.h"
class ComputerStore
{
public:
	ComputerStore(const char* name, const char* workingTime, float winnedMoney);
	ComputerStore();
	ComputerStore& operator=(const ComputerStore& other);
	~ComputerStore();

    char* getName() const;
	char* getWorkingTime() const;
	float getWinned() const;
	int getSize() const;
	ComputerPart* getParts() const;

	void addPart(ComputerPart newPart);
	void removePart(int index);
	ComputerPart searchByType(TYPE type);
	ComputerPart searchByBrand(const char* brand);
	void referenceForWinnedMoney();

private:
	void init(const char* name, const char* workingTime, float winnedMoney);
	void copy(const ComputerStore& other);
	void clear();

	char* name;
	char* workingTime; 
	float winnedMoney;
	ComputerPart* partst;
	int sizeParts=0;
};

