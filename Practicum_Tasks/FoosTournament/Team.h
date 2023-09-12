#pragma once
#include "SoftwareEngineer.h"
class Team
{
public:
	bool isValid() const;
	int getCeoCount() const;
	int getCtoCount() const;
	void print() const;

public:
	Team();
	Team(SoftwareEngineer _first, SoftwareEngineer _second);

private:
	SoftwareEngineer first;
	SoftwareEngineer second;
};

