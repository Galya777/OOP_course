#include "Player.h"
#include <cstring>
#include <iostream>

void Player::init(int health, const char* name, Point possition, Weapon weapon, int attack_damage)
{
	setHealth(health);
	//set the name
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	setPosition(possition);
	setWeapon(weapon);
	setAttackDamage(attack_damage);
}

void Player::copy(const Player& other)
{
	init(other.health, other.name, other.position, other.weapon, other.attack_damage);
}

void Player::del()
{
	delete[] name;
}

void Player::setHealth(int health)
{
	this->health = health;
}

void Player::setPosition(Point position)
{
	this->position.x = position.x;
	this->position.y = position.y;
}

void Player::setWeapon(Weapon weapon)
{
	this->weapon = weapon;
}

void Player::setAttackDamage(int attack_damage)
{
	if (attack_damage > 0)
		this->attack_damage = attack_damage;
	else
		throw("Invalid attack damage!");
}

void Player::move(Point newPossition)
{
	setPosition(newPossition);
}

void Player::printCommon()
{
	std::cout << "Name: ";
	for (size_t i = 0; i < strlen(name); i++)
	{
		std::cout << name[i];
	}
	std::cout << "\n";
	std::cout << "Health: " << health<<"\n";
	std::cout << "Position: " << position.x<<" "<<position.y << "\n";
	std::cout << "Weapon: " << weapon << "\n";
	std::cout << "Attack damage: " << attack_damage << "\n";
}

Player::Player(int health, const char* name, Point possition, Weapon weapon, int attack_damage)
{
	init(health, name, possition, weapon, attack_damage);
}

Player::Player()
{
	init(0, "", { 0, 0 }, Weapon::Sword, 1);
}

Player::Player(const Player& other)
{
	copy(other);
}

Player& Player::operator=(const Player& other)
{
	if (this != &other) {
		del();
		copy(other);
	}
	// TODO: insert return statement here
	return *this;
}

Player::~Player()
{
	del();
}

int Player::getHealth() const
{
	return health;
}

char* Player::getName() const
{
	return name;
}

Point Player::getPosition() const
{
	return position;
}

Weapon Player::getWeapon() const
{
	return weapon;
}

int Player::getAttack_damage() const
{
	return attack_damage;
}
