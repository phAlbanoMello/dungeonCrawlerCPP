#include "Enemy.h"

Enemy::Enemy(std::string name, int health, std::tuple<int,int> damageRange, int speed) : Battler(name, health, damageRange, speed)
{
}

Tiers Enemy::GetSize() const
{
	return size;
}

void Enemy::SetSize(Tiers enemySize)
{
	size = enemySize;
}

std::string Enemy::GetTierString() {
    switch (size) {
    case None:
        return "Unknown";
    case Dangerous:
        return "Dangerous";
    case Balanced:
        return "Balanced";
    case Weak:
        return "Weak";
    default:
        return "Unknown";
    }
}