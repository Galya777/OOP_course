#pragma once
#include"Vector.h"
#include"Student.h"
const int MAX_TYPE = 13;
const int MAX_GRADES = 15;
const int MAX_INPUT_LEN = 100;
const int MAX_SPEC_LEN = 100;
class Decipline
{
public:
	Decipline(const char* decipline, const char* type,int course);
	Decipline();
	Decipline& operator=(const Decipline&other);
	~Decipline();
	Decipline(Student& newStudent);
	void addStudent(int facultity);
	void addGrades(double grade);
	void setDeciplineName(const char* name);
	void setType(const char* type);
	bool isDeciplineMultypleCourse(Decipline &decipline, Student &student);
	void printStudents();
private:
	Student student;
	char* m_desciname;
	char type[MAX_TYPE];
	double grades[MAX_GRADES];
	int m_course;
	int gradesize = 0;

	void init(const char* decipline, const char* type, int course);
	void copy(const Decipline& other);
	void del();

	Vector<Student*>students;
	friend class Student;
	
};

