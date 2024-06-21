#pragma once
#include "Player.h"
class PlayerCollection
{
public:
	PlayerCollection();
	PlayerCollection(PlayerCollection& other);
	PlayerCollection& operator=(PlayerCollection& other);
	~PlayerCollection();


	void addPlayer(Player* player);
	const Player* getPlayer(int index);
	int playersCount() const;
	void removePlayer(const char* name);
private:
	void copy(PlayerCollection& other);
	void del();

	bool nameUnique(const char* name);

	Player** players;
	int size;
	int capacity=1;
};

