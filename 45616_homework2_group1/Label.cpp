#include "Label.h"

Label::Label(int position[2], const char* text)
{
	init(position, text);
	size[0] = 1;
	size[1] = strlen(text);
}

Label::Label()
{
	int empty[2] = { 0, 0 };
	init(empty, "");
	size[0] = 1;
	size[1] = strlen(text);
}

void Label::showContent()
{
	for (int i = 0; i < strlen(text); ++i) {
    std::cout << text[i];
	}
	std::cout << std::endl;
}
