#pragma once
#include <Sizes.h>
#include <vector>
#include <string>
#include "Enemy.h"

class EnemiesManager
{
public:
	/// These would fit better in a utility class
	int GetRandomInteger(int minRange, int maxRange, bool isMultipleOfTen = false);
	std::vector<std::string> GetRandomStrings(const std::vector<std::string>& inputVector, size_t amount);
	//----------------------------------------------------------------------------
	void LoadEnemies(std::vector<std::string>& enemyNames, int enemiesCount);
	Sizes DetermineEnemyTier(int health, int damage);
	std::string GetEnemyNamesFilePath();
	std::vector<Enemy> GetEnemies();
	std::string GetSizeString(Enemy& enemy);
	//Leaving it here for simplicity. Maybe I'll implement JSON serialization later.
	
	const int MaxEnemyCount = 5;
	const int MinEnemyCount = 2;
	const int EnemyMinHealth = 10;
	const int EnemyMaxHealth = 60;
	const int EnemyMinDamage = 2;
	const int EnemyMaxDamage = 10;
	
private:
	const std::string ENEMY_NAMES_FILE = "D:/Projetos/dungeonCrawlerCPP/DungeonCrawlerCPP/Enemies/EnemyNames.txt";
	std::vector<Enemy> Enemies;
};


