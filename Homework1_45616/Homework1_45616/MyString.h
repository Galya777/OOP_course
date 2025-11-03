#pragma once
#include <cstring>
#include <stdexcept>
class MyString
{
public:
	MyString(const char* str);
	MyString();
	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
	
	char& at(std::size_t pos);
	const char& at(std::size_t pos) const;
	char& operator[](std::size_t pos);
	const char& operator[](std::size_t pos) const;
	char& front();
	const char& front() const;
	char& back();
	const char& back() const;
	bool empty() const;
	std::size_t size() const;
	void push_back(char c);
	void pop_back();
    MyString& operator+=(char c);
	MyString& operator+=(const MyString& rhs);
	MyString operator+(char c) const;
	MyString operator+(const MyString& rhs) const;
	const char* c_str() const;
	bool operator==(const MyString& rhs) const;
	bool operator<(const MyString& rhs) const;
	~MyString();
private:
	void init(const char* str);
	void copy(const MyString& other);
	void clear();

    char* m_mystring;
	std::size_t m_strsize;
};

