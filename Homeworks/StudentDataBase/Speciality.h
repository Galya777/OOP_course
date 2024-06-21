#pragma once
#include "Student.h"
#include"Decipline.h"
class Speciality
{
public:
	Speciality(const char* sname, int course);
	Speciality();
	~Speciality();
	Decipline** Specialdecipline =nullptr;
	Student** Specialstudent = nullptr;
	void addStudent(const char* name);
	void printStudentsInTHISspeciality();
	void setSpeciality(const char* speciality);
	void setCourse(int course);
	int getcourse();
private:
	char* specialityName;
	int scourse;
	void init(const char* sname, int course);
	int specialsize=0;
	int specialcapacity=0;
	friend class Students;
};

