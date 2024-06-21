#pragma once
#include "Player.h"
#include "Mage.h"
class Necromancer : public Mage
{
public:
	 Necromancer(int health, const char* name, Point possition, Weapon weapon, int attack_damage, const char* magical_ability, float qoficient);
	 Necromancer();
	 Necromancer(const Necromancer& other);
	 Necromancer& operator=(const Necromancer& other);
	~Necromancer();

	virtual void handle_attack(Point opponentPossition, int opponentAttackDamage);
	virtual int get_atack_power()const;
	virtual void print();
	virtual void attack(Player* opponent);
private:
	void copyN(const Necromancer&other);

	Player** killed;
	int size;
	int capacity=1;
};

