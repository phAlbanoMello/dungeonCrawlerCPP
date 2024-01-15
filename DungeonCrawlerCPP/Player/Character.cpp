#include "Character.h"

Character::Character(std::string name) : _name(name){}

std::string Character::GetPlayerName()
{
	return _name;
}

int Character::GetHealth()
{
	return _health;
}

int Character::GetPlayerDamage()
{
	return _damage;
}
