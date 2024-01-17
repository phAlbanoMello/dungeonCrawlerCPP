#pragma once
#include "../Enums/Sizes.h"
#include "../Enemies/EnemiesManager.h"

class GameState
{
public:
	void AddDefeatedEnemy(Tiers size);
	int GetAmountOfDefeatedEnemiesBySize(Tiers size) const;
	int GetTotalEnemiesDefeatedAmount() const;
	void PrintEndGameStatistics(EnemiesManager& enemiesManager) const;
private:
	int TotalEnemiesDefeated = 0;
	int SmallEnemiesDefeated = 0;
	int MediumEnemiesDefeated = 0;
	int BigEnemiesDefeated = 0;
};

