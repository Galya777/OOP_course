#include "CheckBox.h"

CheckBox::CheckBox(int position[2], const char* text)
{
	init(position, text);
	this->size[0] = 1;
	this->size[1] = strlen(text) + 4;
	isChecked = false;
}

CheckBox::CheckBox()
{
	int empty[2] = { 0, 0 };
	init(empty, "");
	this->size[0] = 1;
	this->size[1] = strlen(text) + 4;
	isChecked = false;
}

void CheckBox::checkOrNot(const char* check)
{
	if (strcmp(check, "Checked") == 0) {
		isChecked = true;
	}
}

void CheckBox::showContent()
{
		std::cout << "[";
		if (isChecked == true) {
			std::cout << "V";
		}
		else {
			std::cout << " ";
		}
		std::cout << "] " << text;
	
}
