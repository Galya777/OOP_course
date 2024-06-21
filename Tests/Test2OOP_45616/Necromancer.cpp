#include "Necromancer.h"
#include <iostream>

Necromancer::Necromancer(int health, const char* name, Point possition, Weapon weapon, int attack_damage, const char* magical_ability, float qoficient)
{
	init(health, name, possition, weapon, attack_damage);
	setMagicalAbiility(magical_ability);
	setQoficient(qoficient);
	killed = new Player * [capacity];
	size = 0;
}

Necromancer::Necromancer()
{
	init(0, "", { 0, 0 }, Weapon::Sword, 1);
	setMagicalAbiility("");
	setQoficient(0);
	killed = new Player * [capacity];
	size = 0;
}

Necromancer::Necromancer(const Necromancer& other)
{
	copyN(other);
     
}

Necromancer& Necromancer::operator=(const Necromancer& other)
{
	if (this != &other) {
		delMag();
		copyN(other);
	}
	// TODO: insert return statement here
	return *this;
}

Necromancer::~Necromancer()
{
	for (size_t i = 0; i < size; i++)
	{
        delete[] *killed;
	}
	delete[] killed;
}

void Necromancer::handle_attack(Point opponentPossition, int opponentAttackDamage)
{
	if (position.neighbours(opponentPossition)) {
		health -= opponentAttackDamage;
	}
	else {
		std::cout << "Only neighbours can attack each other!";
	}
}

int Necromancer::get_atack_power() const
{
	return attack_damage + qoficient;
}

void Necromancer::print()
{
	printCommon();
	std::cout << "Magical ability: ";
	for (size_t i = 0; i < strlen(magical_ability); i++)
	{
		std::cout << magical_ability[i];
	}
	std::cout << "\nQoficient: " << qoficient<<"\n";
	std::cout << "Killed: ";
	for (size_t i = 0; i < size; i++)
	{
		killed[i]->print();
		std::cout << "\n";
	}
}

void Necromancer::attack(Player* opponent)
{
	srand(time(0));
	int random = rand();
	if (random >= size) {
		opponent->setHealth(opponent->getHealth() - opponent->getHealth() * qoficient);
		opponent->handle_attack(position, get_atack_power());
		
	}
	else {
		opponent->setHealth(opponent->getHealth() - opponent->getHealth() * qoficient);
		opponent->handle_attack(position, killed[random]->get_atack_power());
	}
	if (opponent->getHealth() == 0) {
			killed[size] = opponent;
			size++;
			if (size >= capacity) capacity *= 2;
		}
}

void Necromancer::copyN(const Necromancer& other)
{
	copyMag(other);
	killed = new Player * [other.capacity];
	size = other.size;
	for (size_t i = 0; i < other.size; i++)
	{
		*killed[i] = *other.killed[i];
	}capacity = other.capacity;

}
