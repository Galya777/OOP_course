#pragma once
#include<string>
#include<iostream>
#pragma warning(disable:4996)
const int MAX_CHALLANGE = 32;
const int MAX_ST = 15;
const int MAX_LIMIT =655;
class Challange
{
public:
	Challange(const char* challange,const char* status,float raiting);
	Challange();
	int sizechall=0;
	void setchallange(const char* challange);
	const char* getchallange() const;
	bool ischallange();
	void setstatus(const char* status);
	int getid();
	void setRating(float raiting);
	void increaseId();
	float getrating();
private:
	
	int ident=0;
	char m_challange[MAX_CHALLANGE];
	char m_status[MAX_ST];
    float m_raiting;
};
