#pragma once
#include "Player.h"
class Mage: public Player
{
public:
	Mage(int health, const char* name, Point possition, Weapon weapon, int attack_damage, const char* magical_ability, float qoficient);
	Mage();
	Mage(const Mage& other);
	Mage& operator=(const Mage& other);
	~Mage();

	void setMagicalAbiility(const char* magical_ability);
	void setQoficient(float qoficient);

	char* getMagical_ability() const;
	float getQoficient() const;

	virtual void handle_attack(Point opponentPossition, int opponentAttackDamage);
	virtual int get_atack_power()const;
	virtual void print();
	virtual void attack(Player* opponent);
	
protected:
	void copyMag(const Mage& other);
	void delMag();

	char* magical_ability;
	float qoficient;

};

