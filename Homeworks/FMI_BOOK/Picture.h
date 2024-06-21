#pragma once
#include "Posts.h"
const int MAX_PATH = 100;
class Picture:public Posts
{
public:
	Picture(const char* p);
	Picture();
	void setPicture(const char* pic);
	void makePicture(const char* picturePath, const char* filename);

private:
	char path[MAX_PATH];
};

