#pragma once
#include "Component.h"
#include <fstream>
class Cpu: public Component
{
public:
	Cpu(int core, double frequency);
	Cpu();
	const int getCore();
	const double getFrequency();
	friend std::ifstream& operator>>(std::ifstream& is, Cpu& cpu);
private:
	int core;
	double frequency;
};

