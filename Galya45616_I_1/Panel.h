#pragma once
#include "Control.h"
class Panel: public Control
{
public:
	Panel(int id, const char* name, const char* helpMessage, bool enabled):
		Control(id, name, helpMessage, enabled) {
	
	}

	virtual void setName(const char* name) override;
	virtual void setMessage(const char* message) override;

	virtual void print() override;
	virtual const char* settings() override;

	virtual void readFromFile() override;
	virtual void writeToFile() override;

	void addLabel(Control& label);
	void removeLabel(int index);
	Control getLabel(int index);

private:
	Control** controls;
	int size;
};
