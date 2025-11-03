#include "Control.h"

void Control::init(int position[2],  const char* text)
{
	this->identificator = THIS_ID;
	THIS_ID++;
	this->position[0] = position[0];
	this->position[1] = position[1];
	//dafult values
	//will be initialized later in children classes
	this->size[0] = 0; 
	this->size[1] = 0;
	this->text = new char[strlen(text) + 1];
	strcpy(this->text, text);
}

void Control::copy(const Control& other)
{
	this->position[0] = other.position[0];
	this->position[1] = other.position[1];
	this->size[0] = other.size[0];
	this->size[1] = other.size[1];
	this->text = new char[strlen(other.text) + 1];
	strcpy(this->text, other.text);
}

void Control::clear()
{
	delete[] text;
}


Control::Control(int position[2], const char* text)
{
	init(position, text);
}

Control::Control()
{
	int empty[2] = { 0, 0 };
	init(empty, "");
}

Control::Control(const Control& other)
{
	copy(other);
}

Control& Control::operator=(const Control& other)
{
	if (this != &other) {
		clear();
		copy(other);
	}
	return *this;
}

Control::~Control()
{
	clear();
}

int Control::getIdent() const
{
	return identificator;
}

void Control::setText(const char* text)
{
	this->text = new char[strlen(text) + 1];
	strcpy(this->text, text);
}
