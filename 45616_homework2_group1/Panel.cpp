#include "Panel.h"

Panel::Panel(int position[2], const char* text)
{
	init(position, text);
	this->size[0] = controlsSize;
	this->size[1] = controlsSize;
	controls = new Control * ();
}

Panel::Panel()
{
	int empty[2] = { 0, 0 };
	init(empty, "");
	this->size[0] = 0;
	this->size[1] = 0;
	controls = new Control*();
}

Panel::~Panel()
{
	for (int i = 0; i < controlsSize; ++i) {
		delete[] controls[i];
	}
	delete[] controls;
}

void Panel::addControl(Control* control)
{
	controls[controlsSize] = control;
	++controlsSize;
}

void Panel::showContent()
{
	std::cout << text;
	for (size_t i = 0; i < controlsSize; ++i)
	{
		controls[i]->showContent();
		std::cout << "|";
	}
}
