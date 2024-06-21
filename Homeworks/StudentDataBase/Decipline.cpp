#include "Decipline.h"
#include "Student.h"
#include<cstring>
#include <iostream>
Decipline::Decipline(const char* decipline, const char* type1, int course)
{
	init(decipline, type1, course);
}
Decipline::Decipline()
{
	init("", "",0);
}

Decipline& Decipline::operator=(const Decipline& other)
{
	if (this != &other)
	{
		
		del();

		copy(other);
	}

	return *this;
}

Decipline::~Decipline()
{
	del();
}

Decipline::Decipline(Student& newStudent)
{
	student.setFacultity(newStudent.getFacultity());
	student.setSpeciality(newStudent.getSpeciality());
	student.setGroup(newStudent.getGroup());
	student.setName(newStudent.getName());
	student.setCourse(newStudent.getCourse());
	student.setStatus(newStudent.geStatus());
}

void Decipline::addStudent(int facultity)
{
	student.setFacultity(facultity);
	char* name;
	name = new char[sizeof(name)];
	char speciality[MAX_SPEC_LEN];
	int group;
	std::cin >> speciality >> group;
	std::cin.get(name, sizeof(name)+1);
	student.setSpeciality(speciality);
	student.setGroup(group);
	student.setName(name);
	student.setCourse(1);//The student is now first course.
	student.setStatus("enrolled");
	students.push_back(new Student(student));
}

void Decipline::addGrades(double grade)
{
	if (gradesize < MAX_GRADES) {
		grades[gradesize] = grade;
		gradesize++;
	}
}

void Decipline::setDeciplineName(const char* name)
{
	delete[] m_desciname;
	m_desciname = new char[strlen(name) + 1];
	strcpy(m_desciname, name);
}

void Decipline::setType(const char* type1)
{
	size_t length = strlen(type1);
	if (length != MAX_TYPE) {
		strcpy(type, "");
	}
	strcpy(type, type1);
}

bool Decipline::isDeciplineMultypleCourse(Decipline &decipline, Student &student)
{
	if (strcmp(decipline.type, "chosen") == 0) {
		for (int i = 0; i < student.deciplines.size(); i++) {
			if (student.deciplines[i] != &decipline) {
				m_course++;
				return true;
			}
		}
		
	}
	return false;
}

void Decipline::printStudents()
{
	for (int i = 0; i < students.size(); i++) {
		std::cout << students[i]<<std::endl;
	}
}

void Decipline::init(const char* decipline, const char* type,int course)
{
	m_desciname = new char[strlen(decipline) + 1];
	setType(type);
	strcpy(m_desciname, decipline);
	m_course = course;
}

void Decipline::copy(const Decipline& other)
{
	m_desciname = new char[strlen(other.m_desciname)+1];
	strcpy(m_desciname, other.m_desciname);
	strcpy(type, other.type);
	m_course = other.m_course;
}

void Decipline::del()
{
	delete[] m_desciname;
}



