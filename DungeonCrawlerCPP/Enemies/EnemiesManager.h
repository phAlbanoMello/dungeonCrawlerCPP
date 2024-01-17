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
	
	//----------------------------------------------------------------------------
	
	Tiers DetermineEnemyTier(int health, int damage);
	std::string GetEnemyNamesFilePath();
	void LoadEnemies(std::vector<std::string>& enemyNames, int enemiesCount);
	void CountEnemyByTier(Tiers size);
	void AddWeakEnemyCount();
	void AddBalancedEnemyCount();
	void AddDangerousEnemyCount();
	int GetTotalEnemiesOfTier(Tiers size) const;
	const std::vector<Enemy>& GetEnemies() const;

	//Leaving it here for simplicity. Maybe I'll implement JSON serialization later.
	const int MaxEnemyCount = 10;
	const int MinEnemyCount = 2;
	const int EnemyMinHealth = 10;
	const int EnemyMaxHealth = 100;
	const int EnemyMinDamage = 5;
	const int EnemyMaxDamage = 25;
	
private:
	const std::string ENEMY_NAMES_FILE = "Enemies/EnemyNames.txt";
	std::vector<Enemy> Enemies;

	int TotalWeakEnemies = 0;
	int TotalBalancedEnemies = 0;
	int TotalDangerousEnemies = 0;
};


