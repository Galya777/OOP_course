#pragma once
#include "Control.h"
#include "Label.h"
class RadioButon: public Control
{
public:
	RadioButon(int id, const char* name, const char* helpMessage, bool enabled):
		Control(id, name, helpMessage, enabled) {
		size = 0;
		labels[size] = Label(size, size+1==0?strcat((char*)size+1,"label"):"label", "", true);
			}

	virtual void setName(const char* name) override;
	virtual void setMessage(const char* message) override;

	virtual void print() override;
	virtual const char* settings() override;

	virtual void readFromFile() override;
	virtual void writeToFile() override;

	bool operatorf(int index);

	void addLabel(Label& label);
	void removeLabel(int index);
	Label getLabel(int index);

	
private:
	Label chosenlabel;

	Label labels[16];
	int size;
};


