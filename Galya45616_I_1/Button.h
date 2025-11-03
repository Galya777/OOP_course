#pragma once
#include "Control.h"
class Button: public Control
{
public:
	Button(int id, const char* name, const char* helpMessage, bool enabled, void (*func) ):
		Control(id, name, helpMessage, enabled) {}

	virtual void setName(const char* name) override;
	virtual void setMessage(const char* message) override;

	virtual void print() override;
	virtual const char* settings() override;

	virtual void readFromFile() override;
	virtual void writeToFile() override;

private:

};
