#include "Speciality.h"
#include <iostream>

Speciality::Speciality(const char* sname, int course)
{
	init(sname,course);
}

Speciality::Speciality()
{
	init("", 0);
}

Speciality::~Speciality()
{
	delete[] specialityName;
}

void Speciality::addStudent(const char* name)
{
	if (specialsize == specialcapacity)
	{
		Student** old = Specialstudent;
		specialcapacity = specialsize * 2 + 1;
		Specialstudent = new Student * [specialcapacity];
		for (size_t i = 0; i < specialsize; i++)
		{
			Specialstudent[i] = old[i];
		}
	}
	Specialstudent[specialsize] = new Student(specialsize, name);
	specialsize++;
}



void Speciality::printStudentsInTHISspeciality()
{
	for (int i = 0; i < specialsize; i++) {
		std::cout << Specialstudent[i] << std::endl;
	}
}
void Speciality::setSpeciality(const char* speciality)
{
	specialityName = new char[strlen(speciality)+1];
	strcpy(specialityName, speciality);
}
void Speciality::setCourse(int course)
{
	scourse = course;
}
int Speciality::getcourse()
{
	return scourse;
}
void Speciality::init(const char* sname, int course)
{
	specialityName = new char[strlen(sname) + 1];
	strcpy(specialityName, sname);
	scourse = course;
}
