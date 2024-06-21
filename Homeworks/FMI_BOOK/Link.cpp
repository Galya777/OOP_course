#include "Link.h"
#include <iostream>

Link::Link(const char* l, const char* d)
{
	init(l, d);
}

Link::Link()
{
	init("", "");
}

Link Link::operator=(const Link& other)
{
	if (this != &other)
	{

		clear();

		coopy(other);
	}

	return *this;
}

Link::~Link()
{
	clear();
}

void Link::setLink(const char* li)
{
	link = new char[strlen(li) + 1];
	strcpy(link, li);
}

void Link::setDis(const char* dis)
{
	description = new char[strlen(dis) + 1];
	strcpy(description, dis);
}

void Link::makeLink(const char* hypertext,const char* descr, const char* filename)
{
	std::ofstream out;
	Link address;
	address.setLink(hypertext);
	address.setDis(descr);
	address.setContent(link);
	out.open(filename, std::ios::app);
	writeInFile(out, address);
	address.setContent(description);
	out.open(filename,std::ios::app);
	writeInFile(out, address);
	
}

void Link::init(const char*l, const char* d)
{
	link = new char[strlen(l)+1];
	description = new char[strlen(d) + 1];
	strcpy(link, l);
	strcpy(description,d);
}

void Link::coopy(const Link& other)
{
	link = new char[strlen(other.link) + 1];
	description = new char[strlen(other.description) + 1];
	strcpy(link, other.link);
	strcpy(description, other.description);
}

void Link::clear()
{
	delete[] link;
	delete[] description;
}
