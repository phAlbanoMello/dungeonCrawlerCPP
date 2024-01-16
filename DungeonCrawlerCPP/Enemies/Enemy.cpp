#include "Enemy.h"

Enemy::Enemy(std::string name, int health, std::tuple<int,int> damageRange, int speed)
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
