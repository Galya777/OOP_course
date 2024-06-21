#pragma once
#pragma warning(disable:4996)
#include<cstring>
#include <fstream>
static int THIS_ID = 0;
class Posts
{
public:
	Posts(const char* con);
	Posts();
	Posts operator=(const Posts& other);
	~Posts();
	char* getContent();
	void setContent(const char* newContent);
	void readFromFile(std::ifstream& in, Posts& post);
	void writeInFile(std::ofstream&out,Posts&post);
	void makeText(const char* text,const char* filename);
	int getid();
protected:
	void coppy(const Posts& other);
	void remove();
	char* content;
	int id;
};

