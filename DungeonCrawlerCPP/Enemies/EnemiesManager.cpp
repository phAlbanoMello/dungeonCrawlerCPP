#include "EnemiesManager.h"
#include "../RandomService.h"

std::string EnemiesManager::GetEnemyNamesFilePath() {
    return ENEMY_NAMES_FILE;
}

const std::vector<Enemy>& EnemiesManager::GetEnemies() const
{
    return Enemies;
}

EnemiesManager::EnemiesManager()
{
}

void EnemiesManager::LoadEnemies(std::vector<std::string>& enemyNames, int enemiesCount)
{
    std::vector<std::string> selectedEnemies = RandomService::GetRandomStrings(enemyNames, enemiesCount);

    for (const auto& name : selectedEnemies) {
        int health = RandomService::GetRandomInteger(EnemyMinHealth, EnemyMaxHealth, true);
        int speed = RandomService::GetRandomInteger(1, 51);
        Tiers size = DetermineEnemyTier(health, speed);

        CountEnemyByTier(size);
        
        Enemy enemy = Enemy(name, health, { EnemyMinDamage, EnemyMaxDamage }, speed);
        enemy.SetSize(size);
        Enemies.push_back(enemy);
    }
}

void EnemiesManager::CountEnemyByTier(Tiers size)
{
    switch (size)
    {
    case None:
        break;
    case Dangerous:
        AddDangerousEnemyCount();
        break;
    case Balanced:
        AddBalancedEnemyCount();
        break;
    case Weak:
        AddWeakEnemyCount();
        break;
    default:
        break;
    }
}

Tiers EnemiesManager::DetermineEnemyTier(int health, int speed) {
    int combinedValue = (health + speed) / 2;

    if (combinedValue < (EnemyMinHealth + EnemyMaxHealth) / 3)
    {
        return Weak;
    }
    else if (combinedValue > (EnemyMinHealth + EnemyMaxHealth) * 2 / 3)
    {
        return Dangerous;
    }
    else
    {
        return Balanced;
    }
}

void EnemiesManager::AddWeakEnemyCount()
{
    TotalWeakEnemies++;
}

void EnemiesManager::AddBalancedEnemyCount()
{
    TotalBalancedEnemies++;
}

void EnemiesManager::AddDangerousEnemyCount()
{
    TotalDangerousEnemies++;
}

int EnemiesManager::GetTotalEnemiesOfTier(Tiers size) const
{
    switch (size)
    {
    case None:
        break;
    case Dangerous:
        return TotalDangerousEnemies;
    case Balanced:
        return TotalBalancedEnemies;
    case Weak:
        return TotalWeakEnemies;
    default:
        break;
    }
}
