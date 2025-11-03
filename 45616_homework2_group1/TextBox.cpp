#include "TextBox.h"

TextBox::TextBox(int position[2], const char* text, int lendth, int width)
{
	init(position, text);
	this->size[0] = lendth;
	this->size[1] = width;
	separatedText = new char* [lendth];
	for (size_t i = 0; i < lendth; i++)
	{
		const char* separator = " ";
		int k = 0;
		char* token = strtok((char*)text, separator);// this function is used to separate the text into words 
		while (((token = strtok(NULL, separator)) != NULL))
		{
			//we think that the longest option ever has 100 characters 
			strcpy_s(separatedText[k++], 100, token);
		}
		strcpy(separatedText[i], text);
	}
}

TextBox::TextBox()
{
	int empty[2] = { 0, 0 };
	init(empty, "");
}

TextBox::~TextBox()
{
	for (int i = 0; i < size[0]; ++i) {
		delete[] separatedText[i];
	}
	delete[] separatedText;
}

void TextBox::showContent()
{
	for (size_t i = 0; i < size[0]; i++)
	{
		for (size_t j = 0; j < size[1]; j++)
		{
			std::cout << separatedText[i][j];
		}
		std::cout << std::endl;
	}
}
