#pragma once
#pragma warning(disable:4996)
#include "Control.h"
#include "CheckBox.h"
#include "Label.h"
#include "ListBox.h"
#include "Panel.h"
#include "RadioButton.h"
#include "TextBox.h"
enum ControlType {
CHECKBOX=1,
LABEL=2, 
LISTBOX=3, 
PANEL=4, 
RADIOBUTTON=5,
TEXTBOX=6,
CONTROL=0
};
class Form
{
public:
	Form(const char* name);
	Form();
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

	ControlType getTheType() const;
	int* getPosition() const;
	void changeText(int identificator, const char* newText);

	void makeBoxChecked(CheckBox& box);
	void makeListChecked(ListBox& list);
	void makeRadioChecked(RadioButton& radio);
	

	void addControl(Control* control);
	void print();

	Control& operator[](int identificator);

private:
	void init(const char* name);
	void copy(const Form& other);
	void clear();

	void add(Control* conrol);

	char* name;
	Control** controls;
	int size = 0;
};

