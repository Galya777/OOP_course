#include "Student.h"
#include "Decipline.h"
#include <cstring>
#include <iostream>

Student::Student( int facultityNum, int course, int group, const char* speciality, const char* name, char* status)
{
	init( facultityNum, course,group,speciality, name, status );
}

Student::Student()
{
	init(0,0,0,"","","");
}

Student::Student(const Student& other)
{
	copy(other);
}

Student& Student::operator=(const Student& other)
{
	if (this != &other) {
		del();
		copy(other);
	}
	return *this;
}

Student::~Student()
{
	del();
}

Student::Student(const int size, const char* name)
{
	m_name = new char[strlen(name) + 1];
	strcpy(m_name, name);

}

void Student::setStatus(const char* status)
{
	size_t length = strlen(status);
	if (length != MAX_STATUS) {
		strcpy(m_status, "");
	} for (size_t i = 0; i < length; i++) {
		if (!((status[i] >= 'A' && status[i] <= 'Z') ||
			(status[i] >= 'a' && status[i] <= 'z'))) {
			strcpy(m_status, "");
		}
	}
	strcpy(m_status, status);
}

void Student::setName(const char* name)
{
	delete[] m_name;
	m_name = new char[strlen(name)+1];
	strcpy(m_name, name);
}

void Student::setSpeciality(const char* speciality)
{
	strcpy(m_speciality, speciality);
}

void Student::setFacultity(int facultity)
{
	m_facultityNum = facultity;
}

void Student::setCourse(int course)
{
	m_course = course;
}

void Student::setGroup(int group)
{
	m_group = group;
}

double Student::calculateAverage()
{
	double sum = 0;
	for (int i=0; i < Studentgradesize; i++) {
		sum += studentGrades[i];
	}
	return sum / Studentgradesize;
}

void Student::addGrades(double grade)
{
	if (Studentgradesize < MAX_STGRADES) {
		studentGrades[Studentgradesize] = grade;
		Studentgradesize++;
	}
}

bool Student::isGraduated()
{
	for (int i = 0; i < Studentgradesize; i++) {
		if (studentGrades[i] < 3) {
			return false;
		}
	}
	return true;
}

void Student::printGrades()
{
	for (int i = 0; i < MAX_GRADES; i++) {
		std::cout << studentGrades[i]<<std::endl;
	}
}

void Student::serialize(std::ofstream& of)
{
	of.write((const char*)m_facultityNum,sizeof(m_facultityNum));
	of.write((const char*)m_course, sizeof(m_course));
	of.write((const char*)m_group, sizeof(m_group));
}


const char* Student::getName() const
{
	return m_name;
}

const char* Student::geStatus() const
{
	return m_status;
}

const char* Student::getSpeciality() const
{
	return m_speciality;
}

int Student::getFacultity() const
{
	return m_facultityNum;
}

int Student::getCourse() const
{
	return m_course;
}

int Student::getGroup() const
{
	return m_group;
}



void Student::del()
{
	delete[] m_name;
}

void Student::init( int facultityNum, int course, int group, const char* speciality, const char* name, const char* status)
{
	m_name = new char[strlen(name) + 1];
	setStatus(status);
	strcpy(m_name, name);
	strcpy(m_speciality, speciality);
	m_facultityNum = facultityNum;
	m_course = course;
	m_group = group;

}

void Student::copy(const Student& other)
{
	m_name = new char[strlen(other.m_name) + 1];
	strcpy(m_name, other.m_name);
	strcpy(m_speciality, other.m_speciality);
	strcpy(m_status, other.m_status);
	m_course = other.m_course;
	m_group = other.m_group;
	m_facultityNum = other.m_facultityNum;
		
}
void Student::addDecipline(const char* name)
{
		deciplines.push_back(new Decipline());
	
}
