#pragma once
#include "Vehicle.h"
#include<iostream>
class Garage
{
public:
	Garage(std::size_t size);
	Garage();
	Garage(const Garage& other);
	Garage& operator=(const Garage& other);
	
	void insert(Vehicle& v);
	void erase(const char* registration);
	const Vehicle& at(std::size_t pos) const;
	const Vehicle& operator[](std::size_t pos) const;
	bool empty() const;
	std::size_t size() const;
	const Vehicle* find(const char* registration) const;

	~Garage();
private:
	std::size_t m_capacity;
	std::size_t m_size;
	 Vehicle* *vehicles;
	void copy(const Garage& other);
	void clear();
};

