#include "Commands.h"
#include <iostream>


Commands::Commands()
{
	sessions.push_back(Session());
	currentID = 0;
}



void Commands::run()
{
	std::string command;
	std::string filename;

	do {
		cout << "Please, enter your command: ";
		cin >> command;
		if (command == "load") {
			cout << "Enter your file!";
            cin >> filename;
			Session new_session = Session();
			sessions.push_back(new_session); //adds session to list of sessions
			currentID = sessions.size() - 1;  //sets current session ID
		new_session.load(filename);  // adds image to the new session
		std::cout << "Session " << new_session.getId() << " started successfully!\n";
		}
		else if (command == "close") {
			sessions.at(currentID).close();
		}
		else if (command == "save") {
			sessions.at(currentID).save();
		}
		else if (command == "save as") {
			cout << "Enter the name of the new file: ";
			cin >> filename;
			sessions.at(currentID).saveAs(filename.c_str(), filename);
		}
		else if (command == "grayscale") {
			sessions.at(currentID).grayscale();
		}
		else if (command == "monochrome") {
			sessions.at(currentID).monochrome();
		}
		else if (command == "negative") {
			sessions.at(currentID).negative();
		}
		else if (command == "rotate") {
			std::string direction;
			cin >> direction;
			sessions.at(currentID).rotate(direction.c_str());
		}
		else if (command == "undo") {
			sessions.at(currentID).undo();
		}
		else if (command == "info") {
			sessions.at(currentID).sessionInfo();
		}
		else if (command == "switch") {
			int ID;
			cout << "Enter Id: ";
			cin >> ID;
			switchSessions(ID);
		}
		else if(command!="exit") {
         cout << "Command is not excisting!\n";
		}
	} while (command != "exit");
	
}

Session& Commands::switchSessions(int sessionID)
{
	return sessions.at(sessionID);
	// TODO: insert return statement here
}

void Commands::addSession(Session session)
{
	sessions.push_back(session);
	++currentID;
}

	

		
	
