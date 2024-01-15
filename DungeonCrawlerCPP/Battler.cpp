#include "Battler.h"
#include <string>

Battler::Battler()
{
}

Battler::Battler(std::string name, int health, int damage, int speed) : Name(name), Health(health), Damage(damage), Speed(speed){}

std::string Battler::GetName()
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

int Battler::GetDamage() const
{
	return Damage;
}

int Battler::GetSpeed() const
{
	return Speed;
}
