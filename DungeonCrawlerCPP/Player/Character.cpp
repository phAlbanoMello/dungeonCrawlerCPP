#include "Character.h"

Character::Character(std::string name, int health, std::tuple<int,int> damageRange, int speed) : Battler
{
	Name = name;
	Health = health;
	MinDamage = std::get<0>(damageRange);
	MaxDamage = std::get<1>(damageRange);
	Speed = speed;
}
