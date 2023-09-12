#pragma once
const char SIZE = 100;
class Medicine
{
public:
	struct Symptoms {
		char syptom[SIZE];
		char illness[SIZE];
	};
	char name[SIZE];
	char firm[SIZE];
	double prize;
	double quantity;
	
};

