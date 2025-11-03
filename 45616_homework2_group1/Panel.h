#pragma once
#include "Control.h"
class Panel: public Control
{
public:
	Panel(int position[2], const char* text);
	Panel();
	~Panel();

	void addControl(Control* control);
	virtual void showContent();

private:
	Control** controls;
	int controlsSize = 0;
};

