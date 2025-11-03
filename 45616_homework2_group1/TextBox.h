#pragma once
#include "Control.h"
class TextBox:public Control
{
public:
	TextBox(int position[2], const char* text, int lendth, int width);
	TextBox();
	~TextBox();
	virtual void showContent();

private:
	char** separatedText;
};

