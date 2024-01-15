#include "Enemy.h"
#include <string>
#include <algorithm>

Enemy::Enemy(std::string name, int h, int d, Sizes s)
	: Name(name), health(h), damage(d), size(s) {
}

int Enemy::GetHealth()
{
	return health;
}
int Enemy::GetDamage()
{
	return damage;
}
Sizes Enemy::GetSize()
{
	return size;
}
std::string Enemy::GetName()
{
	return Name;
}

void Enemy::TakeDamage(int damage)
{
	health = (health - damage < 0) ? 0 : health - damage;
}


