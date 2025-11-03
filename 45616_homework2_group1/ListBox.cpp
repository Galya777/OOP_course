#include "ListBox.h"

ListBox::ListBox(int position[2], const char* text)
{
	init(position, text);
	this->size[0] = 1;
	separatedText = new char* [countWords(text)];
	for (size_t i = 0; i < countWords(text); i++)
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
	chosen = 1;
	this->size[1] =text[chosen-1];
	
}

ListBox::ListBox()
{
	int empty[2] = { 0, 0 };
	init(empty, "");
	this->size[0] = 0;
	chosen = 1;
	this->size[1] = text[chosen-1];
	separatedText = new char* [0];
	
}

ListBox::~ListBox()
{
	for (int i = 0; i < size[0]; ++i) {
		delete[] separatedText[i];
	}
	delete[] separatedText;
}

void ListBox::setChosen(int num)
{
	if (num <= size[0]) {
		chosen = num;
		this->size[1] = text[chosen - 1];
	}
}

void ListBox::showContent()
{
	for (int i = 0; i < size[0]; ++i) {
		std::cout << "[";
		//we use chsen-1 because the user will start counting from 1, not from 0
		if (chosen - 1 == i) {
			std::cout << "X";
		}
		else {
			std::cout << " ";
		}
		std::cout << "] ";
		for (int j = 0; j < strlen(separatedText[i]); ++j) {
			std::cout << separatedText[i][j];
		}
		std::cout << std::endl;
	}
}

int ListBox::countWords(const char* text)
{
	char empty = ' ';
	int words = 1;
	for (size_t i = 0; i < strlen(text); ++i)
	{
		if (text[i] == empty) {
			words++;
		}
	}
	return words;
}

