#include "RadioButton.h"

RadioButton::RadioButton(int position[2], const char* text)
{
	init(position, text);
	this->size[0] = countWords(text);
	separatedText = new char* [countWords(text)];
	for (size_t i = 0; i < countWords(text); i++)
	{
		const char* separator = " ";
		int k = 0;
		char* token = strtok((char *)text, separator);// this function is used to separate the text into words 
		while (((token = strtok(NULL, separator)) != NULL))
		{
			//we think that the longest option ever has 100 characters 
			strcpy_s(separatedText[k++], 100, token);
		}
		strcpy(separatedText[i], text);
	}
	this->size[1] = lonestWord()+4;
	chosen = -1;
}

RadioButton::RadioButton()
{
	int empty[2] = { 0, 0 };
	init(empty, "");
	this->size[0] = 0;
	this->size[1] = 0;
	separatedText = new char*[0];
    chosen = -1;
}

RadioButton::~RadioButton()
{
	for (int i = 0; i < size[0]; ++i) {
		delete[] separatedText[i];
	}
	delete[] separatedText;
}

void RadioButton::setChosen(int num)
{
	if (num <= size[0]) {
		chosen = num;
	}
}

void RadioButton::showContent()
{
	for (int i = 0; i < size[0]; ++i) {
		std::cout << "[";
		//we use chsen-1 because the user will start counting from 1, not from 0
		if (chosen-1 == i) {
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

int RadioButton::countWords(const char* text)
{
	char empty=' ';
	int words = 1;
	for (size_t i = 0; i < strlen(text); ++i)
	{
		if (text[i] ==empty) {
			words++;
		}
	}
	return words;
}

int RadioButton::lonestWord()
{
	int longest = strlen(separatedText[0]);
	for (int i = 1; i < size[0]; ++i) {
		if (strlen(separatedText[i]) > longest) {
			longest = strlen(separatedText[i]);
		}
	}
	return longest;
}
