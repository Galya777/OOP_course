#include "Mage.h"
#include <cstring>
#include <iostream>
Mage::Mage(int health, const char* name, Point possition, Weapon weapon, int attack_damage, const char* magical_ability, float qoficient)
{
	init(health, name, possition, weapon, attack_damage);
	setMagicalAbiility(magical_ability);
	setQoficient(qoficient);
}

Mage::Mage()
{
	init(0, "", { 0, 0 }, Weapon::Sword, 1);
	setMagicalAbiility("");
	setQoficient(0);
}

Mage::Mage(const Mage& other)
{
	copyMag(other);
}

Mage& Mage::operator=(const Mage& other)
{
	if (this != &other) {
		delMag();
		copyMag(other);
	}
	// TODO: insert return statement here
	return *this;
}

Mage::~Mage()
{
	delMag();
}

void Mage::setMagicalAbiility(const char* magical_ability)
{
	this->magical_ability = new char[strlen(magical_ability) + 1];
	strcpy(this->magical_ability, magical_ability);
}

void Mage::setQoficient(float qoficient)
{
	if (qoficient >= 0 && qoficient <= 1)
		this->qoficient = qoficient;
	else throw("Invalid value!");
}

char* Mage::getMagical_ability() const
{
	return magical_ability;
}

float Mage::getQoficient() const
{
	return qoficient;
}

void Mage::handle_attack(Point opponentPossition, int opponentAttackDamage)
{
	if (position.neighbours(opponentPossition)) {
		health -= opponentAttackDamage;
	}
	else {
		std::cout << "Only neighbours can attack each other!";
	}
}

int Mage::get_atack_power() const
{
	return attack_damage+qoficient;
}

void Mage::print()
{
	printCommon();
	std::cout << "Magical ability: ";
	for (size_t i = 0; i < strlen(magical_ability); i++)
	{
		std::cout << magical_ability[i];
	}
	std::cout << "\nQoficient: " << qoficient;
}

void Mage::attack(Player* opponent)
{
	opponent->setHealth(opponent->getHealth() - opponent->getHealth()*qoficient);
	opponent->handle_attack(position, get_atack_power());
}

void Mage::copyMag(const Mage& other)
{
	copy(other);
	setMagicalAbiility(other.magical_ability);
	setQoficient(other.qoficient);
}

void Mage::delMag()
{
	delete[] magical_ability;
}
