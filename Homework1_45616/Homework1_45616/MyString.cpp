#include "MyString.h"
#include <cassert>
#pragma warning(disable:4996)
MyString::MyString(const char* str)
{
	init(str);
	
}

MyString::MyString()
{
	init("");
	m_strsize = 0;
}

MyString::MyString(const MyString& other)
{
	copy(other);
}

MyString& MyString::operator=(const MyString& other)
{
	if (this != &other) {
		clear();
		copy(other);
	}
	return *this;
}

MyString::~MyString()
{
	clear();
}

char& MyString::at(std::size_t pos)
{
	if (pos > m_strsize)
		throw std::out_of_range("Out of range");

	return m_mystring[pos];
}

const char& MyString::at(std::size_t pos) const
{

	if (pos > m_strsize)
		throw std::out_of_range("Out of range");

	return m_mystring[pos];
}

char& MyString::operator[](std::size_t pos)
{
	return m_mystring[pos];
	assert(pos >= 0 && pos <=m_strsize );
}

const char& MyString::operator[](std::size_t pos) const
{
	return m_mystring[pos];
}

char& MyString::front()
{
	return m_mystring[0];
	assert(m_mystring != nullptr);
}

const char& MyString::front() const
{
	return m_mystring[0];
	assert(m_mystring != nullptr);
}

char& MyString::back()
{
	return m_mystring[m_strsize - 1];

}

const char& MyString::back() const
{
	return m_mystring[m_strsize - 1];
	assert(m_mystring != nullptr);
}

bool MyString::empty() const
{
	if (m_strsize == 0)
		return true;


	return false;
}

std::size_t MyString::size() const
{
	return std::size_t(m_strsize);
}

void MyString::push_back(char c)
{
	m_mystring[m_strsize] = c;
	++m_strsize;
}

void MyString::pop_back()
{
	m_mystring[m_strsize-1] = '\0';
	--m_strsize;
	assert(m_mystring != nullptr);
}

MyString& MyString::operator+=(char c)
{
	push_back(c);
	return *this;
	
}

MyString& MyString::operator+=(const MyString& rhs)
{
	char* strrhs = new char[strlen(m_mystring) + strlen(rhs.m_mystring)+1];
	strrhs = strcat(m_mystring, rhs.m_mystring);
	return *this;
}

MyString MyString::operator+(char c) const
{
	MyString newstring;
	newstring.m_mystring = new char[strlen(m_mystring) + 2];
	strcpy(newstring.m_mystring, m_mystring);
	newstring.push_back(c);
	return newstring;
}

MyString MyString::operator+(const MyString& rhs) const
{
	MyString newstring;
	newstring.m_mystring = new char[strlen(m_mystring) + strlen(rhs.m_mystring)+1];
	strcpy(newstring.m_mystring, strcat(m_mystring, rhs.m_mystring));
	return newstring;
}

const char* MyString::c_str() const
{
	return m_mystring;
}

bool MyString::operator==(const MyString& rhs) const
{
	if (strcmp(m_mystring, rhs.m_mystring) == 0)
		return true;

	return false;
}

bool MyString::operator<(const MyString& rhs) const
{
	if (m_strsize != rhs.m_strsize) {
		return false;
	}	else {
		int i = 0;
		while (m_mystring[i] == rhs.m_mystring[i]) {
			i++;
		} 
		if (m_mystring[0] < rhs.m_mystring[0]) {
			return true;
		}
	}
	return false;
}

void MyString::init(const char* str)
{
	m_mystring = new char[strlen(str) + 1]; 
	strcpy(m_mystring, str);
	m_strsize = strlen(str);
}

void MyString::copy(const MyString& other)
{
	m_mystring = new char[other.m_strsize+1];
	strcpy(m_mystring, other.m_mystring);
	m_strsize = other.m_strsize;
}

void MyString::clear()
{
	delete[] m_mystring;
}
