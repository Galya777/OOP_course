#pragma once
class Vector
{
public:
	Vector();
	Vector(const Vector& other);
	Vector& operator=(const Vector& other);
	~Vector();
public:
	int size();
	int capacity();
	int& at(int index);
	void push_back(int element);
	void erase(int index);
	void reserve(int capacity);
private:
	void copy(const Vector& other);
	void clear();
private:
	int m_size;
	int m_capacity;
	int* m_arr;
};

