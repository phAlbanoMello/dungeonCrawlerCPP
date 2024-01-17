#include "Battler.h"
#include <string>

Battler::Battler()
{
}

Battler::Battler(std::string name, int health, std::tuple<int, int> damageRange, int speed)
{
	Name = name;
	Health = health;
	MinDamage = std::get<0>(damageRange);
	MaxDamage = std::get<1>(damageRange);
	Speed = speed;
}

std::string& Battler::GetName()
{
	return Name;
}

void Battler::TakeDamage(int damage)
{
	Health = (Health - damage < 0) ? 0 : Health - damage;
}

int Battler::GetHealth() const
{
	return Health;
}

int Battler::GetMaxDamage() const
{
	return MaxDamage;
}
int Battler::GetMinDamage() const
{
	return MinDamage;
}

int Battler::GetSpeed() const
{
	return Speed;
}
