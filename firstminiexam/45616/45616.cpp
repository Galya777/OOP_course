
// 
// СУ "Св. Климент Охридски"
// Факултет по математика и информатика
// Курс Обектно-ориентирано програмиране 2020/21
// Контролно 1
// 
// Име: Галя Георгиева Додова
// ФН: 45616
// Специалност: Информатика
// Курс: 1
// Административна група: 1
// Ден, в който се явявате на контролното: 17.04.2021г.
// Начален час на контролното: <8:00>
// Кой компилатор използвате:< Visual C++>
//

// (Можете да изтриете този коментар след като го прочетете)
// Редът по-долу е специфичен за Visual C++.
// Ако използвате друг компилатор, можете да го изтриете.
// Тъй като strlen, strcmp и т.н. са дефинирани като deprecated,
// имате две възможности:
//
// * да използвате безопасните версии на тези функции
//   (strlen_s, strcmp_s и т.н.). В този случай можете да
//   изтриете дадената по-долу #define директива.
//
// * да дефинирате _CRT_SECURE_NO_WARNINGS преди да
//   включите съответните header файлове от стандартната
//   библиотека.
//
#define _CRT_SECURE_NO_WARNINGS 

#include <cassert>
#include <cstring>
#include <iostream>
#include <string>
#include <cctype>
const int MAX = 100;

class Registration {
	
public:
	Registration(const char* str) {
		strcpy(registration, str);
		if (strlen(str) != strlen(registration)&&!isValidNumber(str)) {
			std::exception;
		}
	}
	Registration& operator=(const char* str) {
		if (strcmp(registration, str) == 0&&isValidNumber(str))
			return *this;
		else  {
			std::exception;
		}
	}
	bool operator==(const char* str) const {
		if (strcmp(registration, str) == 0)
			return true;

		return false;
	}
	const char* toString() const {
		return registration;
	}
private:
	char registration[9];
	bool isValidNumber(const char* str) {
		int symbols = 0;
		int numbers = 0;
		for (int i = 0; i < 9; ++i) {
			if (isalpha(str[i]) == true) {
				symbols++;
			}else if(isdigit(str[i])==true){
				numbers++;
			}
		}
		if (numbers == 4 && symbols == 4) {
			return true;
		}
		return false;
	}
	
};

class Vehicle {
public:
	Registration *regnum;
	std::string description;
	Vehicle(const char* regnum1, const char* description1) {
		regnum->operator=(regnum1);
		description = description1;
	}
};

class VehicleList {
public:
	VehicleList(std::size_t capacity) {
		m_capacity = capacity;
		m_vehicleslist = new Vehicle * [m_capacity];
	} VehicleList() {
		m_capacity=0;
		m_size = 0;
		m_vehicleslist = nullptr;
	} VehicleList(Vehicle& vehicle) {
		*m_vehicleslist[m_size] = vehicle;
		m_size++;
	} VehicleList coppy(const VehicleList& other) {
		m_capacity = other.m_capacity;
		m_vehicleslist = new Vehicle * [m_capacity];
		m_size = other.m_size;
		m_vehicleslist = other.m_vehicleslist;
	} VehicleList& operator=( VehicleList& other) {
		VehicleList coppy(other);
		return *this;
	}
	~VehicleList() {
		delete[] m_vehicleslist;
	}
	void insert(const char* regnum, const char* description) {
		m_vehicleslist[m_size]->description=description;
		m_vehicleslist[m_size]->regnum->operator=(regnum);
		m_size++;
		if (m_size > m_capacity||isRepeatingTheNumber(regnum)==true) {
			std::exception;
		}
	}
	const Vehicle& at(std::size_t index) const {
		return *m_vehicleslist[index];
		if (index<0 || index>m_capacity) {
			std::out_of_range;
		}
	}
	const Vehicle& operator[](std::size_t index) const {
		assert(index<0 || index>m_capacity);
		return *m_vehicleslist[index];
	}
	bool empty() const {
		if (m_size == 0&&m_vehicleslist==nullptr) {
			return true;
		}
		return false;
	}
	std::size_t capacity() const {
		return m_capacity;
	}
	std::size_t size() const {
		return m_size;
	}
	const Vehicle* find(const char* regnum) const {
		for (int i = 0; i < m_size; ++i) {
			if (m_vehicleslist[i]->regnum->toString() == regnum) {
				return m_vehicleslist[i];
			}	else {
				return nullptr;
			}
		}
	}
private:
	std::size_t m_capacity;
	std::size_t m_size;
	Vehicle** m_vehicleslist;
	bool isRepeatingTheNumber(const char* registr){
		for (int i = 0; i < m_size; ++i) {
			if (m_vehicleslist[i]->regnum->toString() == registr) {
				return true;
			}
		}
		return false;
	}
}; int main()
{
	int N;
	std::cout << "Enter number: ";
	std::cin >> N;
	VehicleList list = N;
	char* regnumber=new char[MAX];
	char* description=new char[MAX];
	for (int i = 0; i < N; ++i) {
		std::cout << "Enter the registration number: ";
		std::cin.ignore('\n');
		std::cin.getline(regnumber, MAX);
		std::cout << "Enter the description: ";
		std::cin.getline(description, MAX);
		list.insert(regnumber, description);
	}
	std::cout << "Enter the registratio number: ";
	std::cin.getline(regnumber, MAX);
	std::cout << list.find(regnumber);
	if (list.find(regnumber) == nullptr) {
		std::cout << "There is no such a car!";
	}

	return 0;
}