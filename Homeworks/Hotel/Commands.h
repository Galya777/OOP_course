#pragma once
#include <fstream>
#include <cstring>
#include "HotelMaker.h"
#include "Interface.h"
const int MAX_CONTENT = 100;
const int MAX_FILE = 100;
class Commands
{
public:

	/// constructor for pixel
  /// default value: creates a black pixel
	Commands(const char* com);
	Commands();
	void open();
	void close();
	void save();
	void saveAs();

	void run();
private:
	std::string command;
	std::ofstream oldFile;
	std::ifstream newFile;
	char file[MAX_FILE];
};

