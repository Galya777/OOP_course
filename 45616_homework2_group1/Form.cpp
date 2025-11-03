#include "Form.h"
const int MAX_TEXT = 1000;
void Form::init(const char* name)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	controls = new Control * [MAX_TEXT];
}

void Form::copy(const Form& other)
{
	strcpy(this->name, other.name);
	controls = other.controls;
	size = other.size;
}

void Form::clear()
{
	delete[] name;
	for (int i = 0; i < size; ++i) {
		delete[] controls[i];
	}
	delete[] controls;
}

void Form::add(Control* control)
{
	if (control == nullptr)
	{
		throw std::invalid_argument("null pointer passed");
	}

	Control** newControls = new Control * [size + 1];

	for (int i = 0; i < size; ++i)
	{
		newControls[i] = controls[i];
	}
	newControls[size] = control;
	delete[] controls;
	newControls = newControls;
}

Form::Form(const char* name)
{
	init(name);
}

Form::Form()
{
	init("");
}

Form::Form(const Form& other)
{
	copy(other);
}

Form& Form::operator=(const Form& other)
{
	if (this != &other) {
		clear();
		controls = new Control * [other.size];
		for (int i = 0; i < other.size; ++i)
		{
			controls[i] = other.controls[i];
		}

		size = other.size;
	}
	return *this;
}

Form::~Form()
{
	clear();
}

ControlType Form::getTheType() const
{
	ControlType t=ControlType::CONTROL;
	std::cout << "What type of control you want to add?\n";
	std::cout << "1. CHECKBOX\n" << "2. LABEL\n" << "3. LISTBOX\n" << "4. PANEL\n" << "5. RADIOBUTTON\n" << "6. TEXTBOX";
	int num;
	std::cout << "Please enter the number: \n";
	std::cin >> num;
	while (num > 6) {
		std::cout << "Option not excisting! Try again!";
		std::cin >> num;
	}
	switch (num) {
	case 1:
		t = ControlType::CHECKBOX;
		break;
	case 2:
		t = ControlType::LABEL;
		break;
	case 3:
		t = ControlType::LISTBOX;
		break;
	case 4:
		t = ControlType::PANEL;
		break;
	case 5:
		t = ControlType::RADIOBUTTON;
		break;
	case 6:
		t = ControlType::TEXTBOX;
		break;
	}
	return t;
}

int* Form::getPosition() const
{
	int position[2];
	position[0] = size;
	position[1] = size % 3;
	return position;
}

void Form::changeText(int identificator, const char* newText)
{
	for (size_t i = 0; i < size; i++)
	{
		if (controls[i]->getIdent() == identificator) {
			controls[i]->setText(newText);
		}
	}
	
}

void Form::makeBoxChecked(CheckBox& box)
{
	char* check= new char[3];
		std::cout << "Is your box checked?\n";
		std::cin.getline(check, 10);
		box.checkOrNot(check);	
		delete[] check;
}

void Form::makeListChecked(ListBox& list)
{
	char* check=new char[3];
	int n;
	std::cout << "Wanna check something?\n";
	std::cin.getline(check, 10);
	if (check == "yes") {
		std::cout << "Enter number of position you want to check: ";
		std::cin >> n;
		list.setChosen(n);
	}
	delete[] check;
}

void Form::makeRadioChecked(RadioButton& radio)
{
	char* check= new char[3];
	int n;
	std::cout << "Wanna check something?\n";
	std::cin.getline(check, 10);
	if (check == "yes") {
		std::cout << "Enter number of position you want to check: ";
		std::cin >> n;
	radio.setChosen(n);
	}
	delete[] check;
}

void Form::addControl(Control* control)
{
	ControlType t = getTheType();
	int* pos = getPosition();
	char* text= new char[MAX_TEXT];
	switch (t) {
	case ControlType::CHECKBOX:
		std::cout << "Please, enter the text: ";
		std::cin.getline(text, MAX_TEXT);
		add(new CheckBox(pos, text));		
		break;

	case ControlType::LABEL:
		std::cout << "Please, enter the text: ";
		std::cin.getline(text, MAX_TEXT);
		add(new Label(pos, text));
		break;

	case ControlType::LISTBOX:
		std::cout << "Please, enter the text: ";
		std::cin.getline(text, MAX_TEXT);
		add(new ListBox(pos, text));
		
		break;

	case ControlType::PANEL:
		std::cout << "Please, enter the text: ";
		std::cin.getline(text, MAX_TEXT);
		//makes empty panel. Users can add controls to it later 
		add(new Panel(pos, text));
		break;

	case ControlType::RADIOBUTTON:
		std::cout << "Please, enter the text: ";
		std::cin.getline(text, MAX_TEXT);
		add(new RadioButton(pos, text));
		break;

	case ControlType::TEXTBOX:
		std::cout << "Please, enter the text: ";
		std::cin.getline(text, MAX_TEXT);
		int width, lendth;
		std::cout << "Please, enter legth and width of your text: ";
		std::cin >> width >> lendth;
		add(new TextBox(pos, text, lendth, width));
		break;
	}
	++size;
	delete[]text;
}

void Form::print()
{
	std::cout << name;
	for (size_t i = 0; i < size; ++i)
	{
		controls[i]->showContent();
		std::cout << "|";
	}
}

Control& Form::operator[](int identificator)
{
	Control* curr = nullptr;
	for (size_t i = 0; i < size; i++)
	{
		if (controls[i]->getIdent()==identificator) {
			curr = controls[i];
		}
	}
	return *curr;
	// TODO: insert return statement here
}


