#pragma once
class Car
{
public:
	Car(const char* brand,const char* colour, int reginumber);
	Car();
	Car(const Car& other);
	Car& operator=(const Car& other);
	~Car();
	char* getbrand();
	char* getcolour();
	int getnumber();
	void setbrand(const char* brand);
	void setnumber(int number);
	bool isvalid();
	void print();
private:
	char* m_brand;
	int m_reginumber;
	char* m_colour;
	void init(const char* brand, const char* colour, int reginumber);
	void copy(const Car& other);
	void del();
};

