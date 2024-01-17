#pragma once
#include <string>
#include <tuple>

class Battler
{
private:
	std::string Name = "";
	int Health = 1;
	int MaxDamage = 1;
	int MinDamage = 1;
	int Speed = 1;
public:
	Battler();
	Battler(std::string name, int health, std::tuple<int,int> damageRange, int speed);

	std::string& GetName();
	void TakeDamage(int damage);
	int GetHealth() const;
	int GetSpeed() const;
	int GetMaxDamage() const;
	int GetMinDamage() const;
	
	virtual bool operator==(const Battler& other) const {
		return true; 
	}
};

