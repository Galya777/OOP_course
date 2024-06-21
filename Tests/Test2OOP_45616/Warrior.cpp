#include "Warrior.h"
#include <iostream>

Warrior::Warrior(int health, const char* name, Point possition, Weapon weapon, int attack_damage, int shield)
{
	init(health, name, possition, weapon, attack_damage);
	setShield(shield);
}

Warrior::Warrior()
{
	init(0, "", { 0, 0 }, Weapon::Sword, 1);
	this->shield = 0;
}

void Warrior::setShield(int shield)
{
	this->shield = shield;
}

int Warrior::getShield() const
{
	return shield;
}

void Warrior::handle_attack(Point opponentPossition, int opponentAttackDamage)
{
	if (position.neighbours(opponentPossition)) {
		if (shield > 0) {
			shield -= opponentAttackDamage;
		}
		else {
			health -= opponentAttackDamage;
		}
	}
	else {
		std::cout << "Only neighbours can attack each other!";
	}
}

int Warrior::get_atack_power() const
{
	return attack_damage;
}

void Warrior::print()
{
	printCommon();
	std::cout << "Shield: "<<shield;
}

void Warrior::attack(Player* opponent)
{
	opponent->handle_attack(position, get_atack_power());
}
