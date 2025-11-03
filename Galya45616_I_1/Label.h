#pragma once
#include "Control.h"
class Label: public Control
{
public:
	Label(int id, const char* name, const char* helpMessage, bool enabled):
	Control(id, name, helpMessage, enabled){}

	//there is way better way to solve this by using clone() virtual finction but not enough time to implement it 
	Label():Control(0, "no", "", false){

	};
	


	virtual void setName(const char* name) override;
	virtual void setMessage(const char* message) override;

	virtual void print() override;
	virtual const char* settings() override;

	virtual void readFromFile() override;
	virtual void writeToFile() override;

	
private:

};

