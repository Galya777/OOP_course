#include "Posts.h"
#include <iostream>

Posts::Posts(const char* con)
{
	content = new char[strlen(con) + 1];
	strcpy(content,con);
	this->id = THIS_ID;
	THIS_ID++;
}

Posts::Posts()
{
	const char* DEFAULT_STR = "";
	content = new char[strlen(DEFAULT_STR) + 1];
	strcpy(content,DEFAULT_STR);
}

Posts Posts::operator=(const Posts& other)
{
	if (this != &other)
	{

		remove();

		coppy(other);
	}

	return *this;
}

Posts::~Posts()
{
	remove();
}



char* Posts::getContent()
{
	return content;
}

void Posts::setContent(const char* newContent)
{
	content = new char[strlen(newContent)+1];
	strcpy(content, newContent);
}

void Posts::writeInFile(std::ofstream& out, Posts& post)
{
	out <<post.id<<" "<< post.content;
}
void Posts::makeText(const char*txt,const char* filename)
{
	std::ofstream out;
	
	Posts text;
	text.setContent(txt);
	out.open(filename,std::ios::app);
	writeInFile(out, text);
	
	
}
int Posts::getid()
{
	return id;
}
void Posts::readFromFile(std::ifstream& in, Posts& post)
{
		int length_content = strlen(content);
		in.read(post.content,length_content);
}


void Posts::coppy(const Posts& other)
{
	content = new char[strlen(other.content) + 1];
	strcpy(content, other.content);
}

void Posts::remove()
{
	delete[] content;
}
