#pragma once
#include "Control.h"
class CheckBox: public Control
{
public:
	CheckBox(int position[2], const char* text);
	CheckBox();

	void checkOrNot(const char* check);
	virtual void showContent();

private:
	bool isChecked;

};

