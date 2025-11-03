#include "Garage.h"
#include <iostream>
#include <cassert>
#pragma warning(disable:4996)
Garage::Garage(std::size_t size)
{
    m_size = 0;
    m_capacity = size;
    vehicles = new Vehicle * [m_capacity];
}

Garage::Garage()
{
    m_capacity = 0;
    vehicles = nullptr;
}

Garage::Garage(const Garage& other)
{
    copy(other);
}

Garage& Garage::operator=(const Garage& other)
{
    if (this != &other) {
        clear();
        copy(other);
    }
    return *this;
}
Garage::~Garage()
{
    clear();
}

void Garage::insert(Vehicle& v)
{
    vehicles[m_size] = &v;
    m_size+=1;
}

void Garage::erase(const char* registration)
{
    for (std::size_t i = 0; i < m_size; ++i) {
        if (strcmp(vehicles[i]->registration(), registration) == 0) {
            vehicles[i]->setDesc(vehicles[m_size]->description());
            vehicles[i]->setReg(vehicles[m_size]->registration());
            vehicles[i]->setPlace(vehicles[m_size]->space());
            m_size -= 1;
        }
    }
}

const Vehicle& Garage::at(std::size_t pos) const
{
   if (pos > m_size) {
       throw std::out_of_range("Out of range");
   }
   return *vehicles[pos];
}

const Vehicle& Garage::operator[](std::size_t pos) const
{
    return *vehicles[pos];
    assert(pos>=0&&pos<=m_size);
}

bool Garage::empty() const
{
    if (m_size== 0&&vehicles[m_size]->description()==nullptr) {
        return true;
    }
    return false;
}

std::size_t Garage::size() const
{
    return m_size;
}

const Vehicle* Garage::find(const char* registration) const
{
    for (std::size_t i = 0; i < m_size; ++i) {
        if (strcmp(vehicles[i]->registration(), registration) == 0) {
            return vehicles[i];
        }
    }
    return nullptr;
}


void Garage::copy(const Garage& other)
{
    vehicles = new Vehicle * [other.m_capacity];
    vehicles = other.vehicles;
    m_capacity = other.m_capacity;
    m_size = other.m_size;
    
}

void Garage::clear()
{
    delete[] vehicles;
    vehicles = NULL;
}
