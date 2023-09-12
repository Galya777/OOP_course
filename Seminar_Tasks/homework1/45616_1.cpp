#pragma once
#pragma warning (disable:C4996) //wrong syntax
#include <fstream>
#include<iostream>
const int MAX_PRIORITY = 100; //THE MAX PRIORITY FOR ALL TASKS 
class Task
{
public:
	//The big four
	Task(const char* description, int priority, int munutes);
	Task();
	Task(const Task& other);
	Task& operator=(const Task& other);
	~Task();

	//getters
	char* getDescription() const;
	int getPriority() const;
	bool getDone() const;
	int getMinutes() const;

	//setters
	void setFinished();
	void setPriority(int priority);
	void setMinutes(int minutes);

	friend std::ofstream& operator<<(std::ofstream& out, const Task& other);
	friend std::istream& operator>>(std::istream& in, const Task& other); //finish if have time left
	Task(std::ifstream& in);
	Task mostImportant(Task& other);

private:
	void init(const char* description, int priority, int munutes);
	void copy(const Task& other);
	void clear();

	char* description;
	int priority;
	bool done;
	int minutes;
};

#include "Task.h"

Task Task::mostImportant(Task& other)
{
	if (this->priority > other.priority) {
		return *this;
	}
	else if (this->priority < other.priority) {
		return other;
	}
	else {
		if (this->minutes < other.minutes) {
			return *this;
		}
	}
	return *this;
}

void Task::init(const char* description, int priority, int munutes)
{
	//initialize the desceiption
	this->description = new char[strlen(description) + 1];
	strcpy(this->description, description);

	//initialize the priority
	setPriority(priority);

	this->done = false;

	setMinutes(minutes);

}

void Task::copy(const Task& other)
{
	init(other.description, other.priority, other.minutes);
	this->done = other.done; //if the other task is already done, its copy should be done also
}

void Task::clear()
{
	delete[] description;
}

Task::Task(const char* description, int priority, int munutes)
{
	init(description, priority, minutes);
}

Task::Task()
{
	init("", 0, 0);
}

Task::Task(const Task& other)
{
	copy(other);
}

Task& Task::operator=(const Task& other)
{
	if (this != &other) {
		clear();
		copy(other);
	}
	return *this;
	// TODO: insert return statement here
}


Task::~Task()
{
	clear();
}

char* Task::getDescription() const
{
	return description;
}

int Task::getPriority() const
{
	return priority;
}

bool Task::getDone() const
{
	return done;
}

int Task::getMinutes() const
{
	return minutes;
}

void Task::setFinished()
{
	if (done == false) {
		done = true;
		std::cout << "Task marked as done!";
	}
	else {
		std::cout << "The task is already done!";
	}
}

void Task::setPriority(int priority)
{
	while ((priority > MAX_PRIORITY) || (priority < 0)) {
		std::cout << "Incorect priority! Try smaller  or positive number!";
		std::cin >> priority;
	}
	this->priority = priority;
}

void Task::setMinutes(int minutes)
{
	while (minutes < 0) {
		std::cout << "Incorect time! Try positive number!";
		std::cin >> minutes;
	}
	this->minutes = minutes;
}

std::ofstream& operator<<(std::ofstream& out, const Task& other)
{
	out << other.priority << " " << other.description << " " << other.minutes << " " << other.done;
	return out;
	// TODO: insert return statement here
}

std::ifstream& operator>>(std::ifstream& in, const Task& other)
{

	return in;
	// TODO: insert return statement here
}


#pragma once
#include "Task.h"
struct Tasks {
	Task task;
	int day;
	int hour;
};
class MonthlyPlanner
{
public:
	MonthlyPlanner(const char* month);
	MonthlyPlanner();
	MonthlyPlanner(const MonthlyPlanner& other);
	MonthlyPlanner& operator=(const MonthlyPlanner& other);
	~MonthlyPlanner();

	char* getMonth() const;
	int getSize() const;

	void addTasks(Task task, int day, int hour);
	void allForTheDay(int day);
	void markAsFinished(int day, int hour);
	void writeToFile(std::ofstream& out);
	void readFromFile(std::ifstream& in);

private:

	void init(const char* month);
	void copy(const MonthlyPlanner& other);
	void clear();

	char* month;
	Tasks Newtask;
	Tasks* tasks;
	int size = 0;
};

#include "MonthlyPlanner.h"

void MonthlyPlanner::init(const char* month)
{
	this->month = new char[strlen(month) + 1];
	strcpy(this->month, month);
	Newtask.day = 0;
	Newtask.hour = 0;
	Newtask.task = Task();
	tasks[size] = Newtask;
}

void MonthlyPlanner::copy(const MonthlyPlanner& other)
{
	init(other.month);
	for (int i = 0; i < other.size; ++i) {
		tasks[i] = other.tasks[i];
	}
}

void MonthlyPlanner::clear()
{
	delete[] month;
	delete[] tasks;
}

MonthlyPlanner::MonthlyPlanner(const char* month)
{
	init(month);
}

MonthlyPlanner::MonthlyPlanner()
{
	init("");

}

MonthlyPlanner::MonthlyPlanner(const MonthlyPlanner& other)
{
	copy(other);
}

MonthlyPlanner& MonthlyPlanner::operator=(const MonthlyPlanner& other)
{
	if (this != &other) {
		copy(other);
		clear();
	}
	return *this;
	// TODO: insert return statement here
}

MonthlyPlanner::~MonthlyPlanner()
{
	clear();
}

char* MonthlyPlanner::getMonth() const
{
	return month;
}

int MonthlyPlanner::getSize() const
{
	return size;
}

void MonthlyPlanner::addTasks(Task task, int day, int hour)
{
	while ((day < 0) || (day > 31)) {
		std::cout << "Incorect day!";
		std::cin >> day;
	}
	this->Newtask.day = day;
	while ((hour < 0) || (hour > 23)) {
		std::cout << "Incorect hour!";
		std::cin >> hour;
	}
	if (hour + (task.getMinutes() / 60) > 24) {
		std::cout << "Task must be finished this day!";
	}
	else {
		this->Newtask.hour = hour;
		this->Newtask.task = task;
		tasks[size] = Newtask;
		++size;
	}

}

void MonthlyPlanner::allForTheDay(int day)
{
	for (int i = 0; i < size; ++i) {
		if (tasks[i].day == day) {
			std::cout << tasks[i].task.getDescription() << " " << tasks[i].task.getPriority() << " " << tasks[i].task.getMinutes() << " " << tasks[i].task.getDone();
		}
	}
}

void MonthlyPlanner::markAsFinished(int day, int hour)
{
	for (int i = 0; i < size; ++i) {
		if (tasks[i].day == day && tasks[i].hour == hour) {
			tasks[i].task.setFinished();
		}
	}
}

void MonthlyPlanner::writeToFile(std::ofstream& out)
{
	out << month << "\n";
	for (int i = 0; i < size; ++i) {
		out << tasks[i].task;
		out << tasks[i].day;
		out << tasks[i].hour;
	}
}
