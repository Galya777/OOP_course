#pragma once
#include "Control.h"

class Label: public Control
{
public:
	Label(int position[2], const char* text);
	Label();
	virtual void showContent();


};

