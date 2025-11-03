#pragma once
#include <fstream>
#pragma warning (disable:4996)
class Control
{
public:
	Control(int id, const char* name, const char* helpMessage, bool enabled) {
		this->id = id;
		setName(name);
		setMessage(helpMessage);
		setEnabled(enabled);
	};
	Control(const Control& other);

	const Control& operator=(const Control& other);
	~Control() = default;

	//Getters
	 const int getId() const;
	 const char* getName() const;
	 const char* getMessage() const;
	 const bool getEnabled() const;

	//Setters
	 virtual void setName(const char* name) {
		 try {
			 if (name != "") {
				 this->name = new char[strlen(name) + 1];
				 strcpy(this->name, name);
			 }
			 else {
				return;
			 }
		 }
		 catch (char* exc) {
			  "Name cannot be empty";
		 }


	 };
	 virtual void setMessage(const char* message) {
		 this->helpMessage = new char[strlen(message) + 1];
		 strcpy(this->helpMessage, message);
	 };

	 void setEnabled(bool enabled);

	virtual void print() = 0;
	virtual const char* settings() = 0;

	virtual void readFromFile() = 0;
	virtual void writeToFile() = 0;

	
protected:
	
	void del();
	void copy(const Control& other);

	int id;
	 char* name;
	 char* helpMessage;
	 bool enabled;
};

