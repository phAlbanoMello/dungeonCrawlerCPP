#include "Enemy.h"

Enemy::Enemy(std::string name, int health, int damage, int speed) : Battler(name, health, damage, speed)
{
	size = None;
}

Sizes Enemy::GetSize() const
{
	return size;
}

void Enemy::SetSize(Sizes enemySize)
{
	size = enemySize;
}
