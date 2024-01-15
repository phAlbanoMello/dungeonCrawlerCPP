#pragma once
#include <string>

class Battler
{
private:
	std::string Name = "";
	int Health = 1;
	int Damage = 1;
	int Speed = 1;
public:
	Battler();
	Battler(std::string name, int health, int damage, int speed);

	std::string GetName();
	void TakeDamage(int damage);
	int GetHealth() const;
	int GetDamage() const;
	int GetSpeed() const;
	
	virtual bool operator==(const Battler& other) const {
		return true; 
	}
};

