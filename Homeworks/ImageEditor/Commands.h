/*
* This class is the system. It is used to call the functions and use the program. 
* It contains file to save on them and the ability to create new file. 
* Also contains a command which is added by the user. 
* Every command is separated function and run is combining them.
* Considering that every session is separated this class combines them 
*/
#pragma once
#include <fstream>
#include <cstring>
#include <string>
#include "Session.h"
using namespace std;
class Commands
{
public:
	Commands();///creates empty sessions
	//every command is separated function

	//main function to realise the commands
	void run();
private:
	/// returns session with provided sessionID
	Session& switchSessions(int sessionID);
	/// adds a new session
	void addSession(Session session);

	std::vector<Session> sessions;
	int currentID;
};

