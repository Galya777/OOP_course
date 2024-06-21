#pragma once
#include<iostream>
#include<cstring>
#include<fstream>
#include "Student.h"
#include "Decipline.h"
#include "Speciality.h"
const int MAX_COMMAND = 20;
const int MAX_FILE = 100;
const int MAX_CONTENT = 100;
const int MAX_ADDINPUT_LEN = 100;
const int MAX_ADDSPEC_LEN = 100;
class Commands
{
	public:
		Commands();
		void run();
};

