#pragma once
#pragma warning(disable:4996)
struct Point {
	double x;
	double y;

	double abs(double a) {
		if (a > 0) return a;
		else return -a;
	}

	bool neighbours(Point other) {
		return (abs(x - other.x) == 1)&& (abs(y - other.y) == 1);
	}
};
enum Weapon {
Sword,
Wand,
Staff, 
Axe
};

class Player
{
public:
	//Constructors and big 4
	Player(int health, const char* name, Point possition, Weapon weapon, int attack_damage);
	Player();
	Player(const Player& other);
	Player& operator=(const Player& other);
	~Player();

	//getters 
	int getHealth() const;
	char* getName() const;
	Point getPosition() const;
	Weapon getWeapon() const;
	int getAttack_damage() const;

   //and setters
	void setHealth(int health);
	void setPosition(Point position);
	void setWeapon(Weapon weapon);
	void setAttackDamage(int attack_damage);

	//add arguments later 
	void move(Point newPossition);
	virtual void handle_attack(Point opponentPossition, int opponentAttackDamage)=0;
	virtual int get_atack_power()const =0;
	virtual void print() = 0;

	virtual void attack(Player* opponent)=0;
protected:
	void init(int health, const char* name,Point possition, Weapon weapon, int attack_damage);
	void copy(const Player& other);
	void del();

void printCommon();

	int health;
	char* name;
	Point position;
	Weapon weapon;
	int attack_damage;
};

