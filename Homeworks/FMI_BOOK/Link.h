#pragma once
#include "Posts.h"
class Link :public Posts
{
public:
	Link(const char* l, const char* d);
	Link();
	Link operator=(const Link& other);
	~Link();
	void setLink(const char* li);
	void setDis(const char* dis);
	void makeLink(const char* hypertext, const char* descr, const char* filename);
	private:
		void init(const char* l, const char* d);
		void coopy(const Link& other);
		void clear();
		char* link;
		char* description;
};

