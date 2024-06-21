#include "Picture.h"
#include <iostream>

Picture::Picture(const char* p)
{
	strcpy(path,p);
}

Picture::Picture()
{
	strcpy(path,"");
}

void Picture::setPicture(const char* pic)
{
	strcpy(path,pic);
}

void Picture::makePicture(const char* picturePath, const char* filename)
{
	std::ofstream out;
	
	Picture picture;
	picture.setPicture(picturePath);
	picture.setContent(path);
	out.open(filename,std::ios::app);
	writeInFile(out, picture);
	
}
