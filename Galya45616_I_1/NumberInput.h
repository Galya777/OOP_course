#pragma once
#include "Control.h"
class NumberInput: public Control
{
public: 
	NumberInput(int id, const char* name, const char* helpMessage, bool enabled,
		int beggining, int min, int max):
		Control(id, name, helpMessage, enabled) {
		this->beggining = beggining;
		if (min < max) {
			this->min = min;
			this->max = max;
		}
		else {
			this->min = max;
			this->max = min;
		}
		this->value = beggining;
	
	}

	virtual void setName(const char* name) override;
	virtual void setMessage(const char* message) override;

	virtual void print() override {};
	virtual const char* settings() override;

	virtual void readFromFile() override;
	virtual void writeToFile() override;

	void operator++();
	void operator--();
	void operator+(int num);
	void operator-(int num);

	 int operator->();
	
private:
	int value;

	int beggining;
	int min;
	int max;
};

