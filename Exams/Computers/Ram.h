#pragma once
#include "Component.h"
#include <fstream>
class Ram:public Component
{
public:
	Ram(int gygabites, int cips, int colors);
	Ram();
	const int getGygabites();
	const int getCips();
	const int getColors();
	friend std::ifstream& operator>>(std::ifstream& is, Ram& ram);
private:
	int gygabites;
	int cips;
	int colors;
};
