#pragma once
#include "Control.h"
class RadioButton: public Control
{
public:
	RadioButton(int position[2], const char* text);
	RadioButton();
	~RadioButton();

	void setChosen(int num);
	virtual void showContent();
	
private:
	int countWords(const char* text);
	int lonestWord();
	char** separatedText;
	int chosen;
};

