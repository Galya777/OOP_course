//������� ����������� ����� �� ������� �������

//������������� ��� �������� ���� �������� �� �������� �� ���������
//���������� �� ���

#include<fstream>
#include<iostream>

const int MAXN = 1024;

int main() {

	//� ���� ����� �� ������ �������� ��������� ����
	char buffer[MAXN] = { 0 };

	//���� �� ����
	//��������� ��� � ,�� ������� � ��������� ">>" ��� ����� ��
	//��� ��� ��� �������� � ���� ���� �� ��������� ����������� ����
	//������ ������ ������,����������� � ����������� ���� �� ����� ���������
	std::cout << "first way word by word : \n";

	std::ifstream ifs("self_print.cpp");

	//��� �� ������ �� ������� �����, ������������ ���������� 
	if (!ifs.is_open()) {

		std::cout << "failed openning!";
		return -1;
	}

	//�� ���� �� ����� �����
	while (!ifs.eof()) {

		//������� ����������� ����
		ifs >> buffer;

		//��� ������ � ����� � �������� ����� , ������� ����������� ����
		if (ifs)
			std::cout << buffer;

		//���������� ������
		memset(buffer, 0, MAXN);
	}

	//����� ��� �� ��� , ���� ����������� � ����������� �� ����� ������� ��������� �
	//� ����������� ���������� , �� ����� �� ����� � ������ ������ ?
	std::cout << "\n second way line by line : \n";

	//std::ifstream ifs2("self_print.cpp");
	//we can re-use the ifs object and 
	//to read form the beginning again
	ifs.clear(); //re-setting flag as EOF
	ifs.seekg(0, std::ios::beg);


	while (!ifs.eof()) {

		//����� � getline , ��������� ���������� �� cin.getline
		ifs.getline(buffer, MAXN);

		if(ifs)
			std::cout << buffer;

		memset(buffer, 0, MAXN);
	}

	ifs.clear();
	ifs.seekg(0, std::ios::beg);

	//����� ������ �� ������ , ���� ������ �� �� �������� ���� ��� ���� � ���� �� ���������� ��
	std::cout << "\n third way char by char : \n";

	char c;
	while (!ifs.eof()) {

		//� ��������� get ������� ���� ������ �� ������
		ifs.get(c);

		if (ifs)
			std::cout << c;
	}

	ifs.close();
	return 0;
}