#include "EnemiesManager.h"
#include <random>

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

int EnemiesManager::GetRandomInteger(int minRange, int maxRange, bool isMultipleOfTen) {
    if (minRange >= maxRange) {
        minRange = maxRange - 1;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(minRange, maxRange);

    int randomNumber = distribution(gen);

    if (isMultipleOfTen) {
        return (randomNumber / 10) * 10;
    }
    else {
        return randomNumber;
    }

    return randomNumber;
}

void EnemiesManager::LoadEnemies(std::vector<std::string>& enemyNames, int enemiesCount)
{
    std::vector<std::string> selectedEnemies = GetRandomStrings(enemyNames, enemiesCount);

    for (const auto& name : selectedEnemies) {
        int health = GetRandomInteger(EnemyMinHealth, EnemyMaxHealth, true);
        int damage = GetRandomInteger(EnemyMinDamage, EnemyMaxDamage);
        int speed = GetRandomInteger(1, 100);
        Sizes size = DetermineEnemyTier(health, damage);

        CountEnemyBySize(size);

        Enemy enemy = Enemy(name, health, damage, speed);
        enemy.SetSize(size);
        Enemies.push_back(enemy);
    }
}

void EnemiesManager::CountEnemyBySize(Sizes size)
{
    switch (size)
    {
    case None:
        break;
    case Big:
        AddBigEnemyCount();
        break;
    case Medium:
        AddMediumEnemyCount();
        break;
    case Small:
        AddSmallEnemyCount();
        break;
    default:
        break;
    }
}

Sizes EnemiesManager::DetermineEnemyTier(int health, int damage) {
    int combinedValue = (health + damage) / 2;

    const double smallTierPercentile = 25.0;
    const double mediumTierPercentile = 75.0;

    double smallTierThreshold = combinedValue * (smallTierPercentile / 100.0);
    double mediumTierThreshold = combinedValue * (mediumTierPercentile / 100.0);

    if (combinedValue <= smallTierThreshold) {
        return Small;
    }
    else if (combinedValue <= mediumTierThreshold) {
        return Medium;
    }
    else {
        return Big;
    }
}

std::vector<std::string> EnemiesManager::GetRandomStrings(const std::vector<std::string>& stringCollection, size_t amount) {
    if (stringCollection.empty() || amount == 0) {
        return {};
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> distribution(0, stringCollection.size() - 1);

    std::vector<std::string> result;

    for (size_t i = 0; i < amount; ++i) {
        size_t randomIndex = distribution(gen);
        result.push_back(stringCollection[randomIndex]);
    }

    return result;
}

std::string EnemiesManager::GetSizeString(Enemy& enemy){
    switch (enemy.GetSize()) {
    case None:
        return "Unknown";
    case Big:
        return "Big";
    case Medium:
        return "Medium";
    case Small:
        return "Small";
    default:
        return "Unknown";
    }
}

void EnemiesManager::AddSmallEnemyCount()
{
    TotalSmallEnemies++;
}

void EnemiesManager::AddMediumEnemyCount()
{
    TotalMediumEnemies++;
}

void EnemiesManager::AddBigEnemyCount()
{
    TotalBigEnemies++;
}

int EnemiesManager::GetTotalEnemiesOfSize(Sizes size) const
{
    switch (size)
    {
    case None:
        break;
    case Big:
        return TotalBigEnemies;
    case Medium:
        return TotalMediumEnemies;
    case Small:
        return TotalSmallEnemies;
    default:
        break;
    }
}
