#pragma once
#pragma warning(disable:4996)
#include "Vector.h"
#include<fstream>
const int MAX_STATUS = 10;
const int MAX_STGRADES = 20;
const int MAX_SPECIALITY = 100;
class Decipline;
class Student
{
public:
	Student( int facultityNum, int course, int group, const char* speciality, const char* name, char* status);
	Student();
	Student(const Student& other);
	Student& operator=(const Student& other);
	~Student();
	Student(const int size, const char* name);
	void setStatus(const char* status);
	void setName(const char* name);
	void setSpeciality(const char* speciality);
	void setFacultity(int faculitty);
	void setCourse(int course);
	void setGroup(int group);
	void addDecipline(const char* name);
	double calculateAverage();
	void addGrades(double grade);
	bool isGraduated();
	void printGrades();
	void serialize(std::ofstream&of);
	const char* getName() const;
	const char* geStatus() const;
	const char* getSpeciality() const;
	int getFacultity() const;
	int getCourse() const;
	int getGroup() const;
	
private:
	void init(int facultityNum,int course,int group,const char* speciality, const char* name, const char*status);
	void copy(const Student &other);
    void del();

	double studentGrades[MAX_STGRADES];
	int Studentgradesize = 0;
	char* m_name;
	int m_facultityNum;
	int m_course;
	int m_group;
	char m_speciality[MAX_SPECIALITY];
	char m_status[MAX_STATUS];
	Vector<Decipline*> deciplines;
	friend class Decipline;
};

