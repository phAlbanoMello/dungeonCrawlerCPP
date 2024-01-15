#pragma once

#include <vector>
#include <string>
#include "Enemy.h"
#include "../Enums/Sizes.h"

class EnemiesManager
{
public:
	EnemiesManager();

	/// These would fit better in a utility class
	int GetRandomInteger(int minRange, int maxRange, bool isMultipleOfTen = false);
	std::vector<std::string> GetRandomStrings(const std::vector<std::string>& inputVector, size_t amount);
	//----------------------------------------------------------------------------
	
	void LoadEnemies(std::vector<std::string>& enemyNames, int enemiesCount);
	Sizes DetermineEnemyTier(int health, int damage);
	std::string GetEnemyNamesFilePath();
	const std::vector<Enemy>& GetEnemies() const;
	std::string GetSizeString(Enemy& enemy);
	//Leaving it here for simplicity. Maybe I'll implement JSON serialization later.
	
	const int MaxEnemyCount = 10;
	const int MinEnemyCount = 2;
	const int EnemyMinHealth = 10;
	const int EnemyMaxHealth = 50;
	const int EnemyMinDamage = 5;
	const int EnemyMaxDamage = 25;

private:
	const std::string ENEMY_NAMES_FILE = "E:/Repos/DungeonCrawlerCPP/dungeonCrawlerCPP/DungeonCrawlerCPP/Enemies/EnemyNames.txt";
	std::vector<Enemy> Enemies;
};


