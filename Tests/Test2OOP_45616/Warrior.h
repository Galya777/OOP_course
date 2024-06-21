#pragma once
#include "Player.h"
class Warrior: public Player
{
public:
	Warrior(int health, const char* name, Point possition, Weapon weapon, int attack_damage, int shield);
	Warrior();

	void setShield(int shield);
	int getShield() const;

	virtual void handle_attack(Point opponentPossition, int opponentAttackDamage);
	virtual int get_atack_power()const;
	virtual void print();
	virtual void attack(Player* opponent);
private:
	int shield;

};

