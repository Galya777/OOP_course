#include "Challange.h"
#include<cstring>

Challange::Challange(const char* challange, const char* status, float raiting)
{
	setchallange(challange);
	setstatus(status);
	m_raiting = raiting;
	
}

Challange::Challange()
{
	setchallange("");
	setstatus("");
	m_raiting = 0.0;
}

void Challange::setchallange(const char* challange)
{
	size_t length = strlen(challange);
	if (length != MAX_CHALLANGE) {
		strcpy_s(m_challange, "");
	} for (size_t i = 0; i < length; i++) {
		strcpy_s(m_challange, "");
	}
	strcpy_s(m_challange, challange);
}

 const char* Challange::getchallange() const
{
	return m_challange;
}

bool Challange::ischallange()
{
	if (m_challange[0] != '#') {
		return false;
	}
	return true;
}


void Challange::setstatus(const char* status)
{
	size_t length = strlen(status);
	if (length != MAX_ST) {
		strcpy_s(m_status, "");
	} for (size_t i = 0; i < length; i++) {
		strcpy_s(m_status, "");
	}
	strcpy_s(m_status, status);
}

int Challange::getid() 
{
	return ident;
}

void Challange::setRating(float raiting)
{
	m_raiting = raiting;
}

void Challange::increaseId()
{
	ident++;
}

float Challange::getrating()
{
	return m_raiting;
}
