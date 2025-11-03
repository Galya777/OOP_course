#pragma once
#pragma warning(disable:4996)
#include <cstring>
#include <iostream>
static int THIS_ID = 0;
class Control
{
public:
	Control(int position[2], const char* text);
	Control();
	Control(const Control& other);
    Control& operator=(const Control& other);
	~Control();

	int getIdent() const;

	void setText(const char* text);

	virtual void showContent() = 0;

protected:
	void init(int position[2], const char* text);
	void copy(const Control& other);
	void clear();



	int identificator;
	int position[2];
	int size[2];
	char* text;
};

