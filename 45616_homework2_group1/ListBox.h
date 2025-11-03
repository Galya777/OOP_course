#pragma once
#include "Control.h"
class ListBox: public Control
{
public:
	ListBox(int position[2], const char* text);
	ListBox();
	~ListBox();

	void setChosen(int num);
	virtual void showContent();

private:
	int countWords(const char* text);
	char** separatedText;
	int chosen;
};

