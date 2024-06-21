#include "PlayerCollection.h"
#include <cstring>


PlayerCollection::PlayerCollection()
{
   players = new Player * [capacity];
    size = 0;
}

PlayerCollection::PlayerCollection(PlayerCollection& other)
{
	copy(other);
}

PlayerCollection& PlayerCollection::operator=(PlayerCollection& other)
{
	if (this != &other) {
		del();
		copy(other);
	}
	// TODO: insert return statement here
	return *this;
}

PlayerCollection::~PlayerCollection()
{
	del();
}

void PlayerCollection::addPlayer(Player* player)
{
	if (nameUnique(player->getName())) {
		players[size] = player;
		size++;
		if (size >= capacity) capacity *= 2;
	}
	else {
		throw("Repeating names");
	}
}

const Player* PlayerCollection::getPlayer(int index)
{
	if (index >= size) throw("Invalid index");
	else return players[index];
}

int PlayerCollection::playersCount() const
{
    return size;
}

void PlayerCollection::copy(PlayerCollection& other)
{
	players = new Player * [other.capacity];
	size = other.size;
	capacity = other.capacity;
	for (size_t i = 0; i < other.size; i++)
	{
		players[i] = other.players[i];
	}
	
}

void PlayerCollection::del()
{
	for (size_t i = 0; i < size; i++)
	{
		delete[] * players;
	}
	delete[] players;
}

bool PlayerCollection::nameUnique(const char* name)
{
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(players[i]->getName(), name) == 0) {
			return false;
		}
	}
	return true;
}
