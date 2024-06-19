// 
// �� "��. ������� ��������"
// �������� �� ���������� � �����������
// ���� �������-����������� ������������ 2020/21
// ��������� �� ���-���������
// 
// ���: ���� ������
// ��: 45616
// �����������: �����������
// ����: 2
// ��������������� �����: 1 
// ���, � ����� �� ������� �� �����������: 15,05,2021�. 
// ������� ��� �� �����������: <9:00>
// ��� ���������� ����������: <�������� ���� �� Visual C++, GCC ��� Clang>
//

// (������ �� �������� ���� �������� ���� ���� �� ���������)
// ����� ��-���� � ���������� �� Visual C++.
// ��� ���������� ���� ����������, ������ �� �� ��������.
// ��� ���� strlen, strcmp � �.�. �� ���������� ���� deprecated,
// ����� ��� �����������:
//
// * �� ���������� ����������� ������ �� ���� �������
//   (strlen_s, strcmp_s � �.�.). � ���� ������ ������ ��
//   �������� �������� ��-���� #define ���������.
//
// * �� ���������� _CRT_SECURE_NO_WARNINGS ����� ��
//   �������� ����������� header ������� �� ������������
//   ����������.
//
#define _CRT_SECURE_NO_WARNINGS 

#include <cassert>
#include <cstring>
#include <iostream>
#include <string>
#include <fstream>
int main()
{
	std::string name;
	if (std::cin) {
		std::cin >> name;
	}	else {
		name = "config.txt";
	}
	return 0;
}
class Message {
	enum Type {
		INFO,
		WARNING,
		ERROR,
		CRITICAL_ERROR
	};
public:
	Message(const std::string description, const Type& type);
	Message();
	void out(std::string fileName);
protected:
	std::string description;
	Type type;
};

Message::Message(const std::string description, const Type& type)
{
	this->description = description;
	this->type = type;
}

Message::Message()
{
	description = " ";
	type = INFO;
}

void Message::out(std::string fileName)
{
	std::ofstream file(fileName);
	if (file.is_open()) {
		file << this->type << " " << this->description;
	}else {
		std::cout<< "Could not open this file!";
		return;
	}
}

class Logger:public Message {
public:
	Logger();
	void outLogger(std::string fileName) {
		std::ifstream file(fileName);
		std::cin >> description;
		int t;
		std::cin >> t; 
		switch (t) {
		case 0: ++info;
			break;
		case 1: ++warning;
			break;
		case 2: ++error;
			break;
		case 3: ++criticalerror;
			break;
		}
		if (file.is_open()) {
			file.seekg(std::ios::ate);
			file >> t >> description;
		}else {
			std::cout << "Could not open this file!";
			return;
		}
		std::cout << "Info: " << info << " Warning: " << warning << " Error: " << error << " Critical: " << criticalerror;
	}
	static int error;
	static int criticalerror;
	static int warning;
	static int info;
};

class Configuration {
public:
	Configuration(std::string n);
	Configuration();
	void read();
private:
	std::string file;
	Logger log;
};

Configuration::Configuration(std::string n)
{
	this->file = n;
}

Configuration::Configuration()
{
	file = "";
}

void Configuration::read()
{
	std::cin >> file;
	std::fstream(file);
	if (!file.is_open()) {
		std::cout << "Error!";
		return;
	}
}

Logger::Logger()
{
	description = " ";
	
}
