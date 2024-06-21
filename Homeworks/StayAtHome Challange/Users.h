#pragma once
#pragma warning(disable:4996)
const int MAX_CAPACITY = 100;
static int THIS_ID = 0;
class Users
{
public:
	Users(const char* name, int age,const char* email );
	Users();
	Users(const Users& other);
	Users& operator=(const Users& other);
	~Users();
	bool isvalidAge();
	void setemail(const char* email);
	void setName(const char* name);
	void setAge(int age);
	const char* getName() const;
	const char* getEmail() const;
 char* adding(char*) const;
	int getAge() const;
	int getId() const;
private:

	void init(const char* name, int age, const char* email);
	void copy(const Users& other);
	void del();
	int id;
	char* m_name;
	int m_age;
	char m_email[MAX_CAPACITY];

};

