#pragma once
#include "../Enums/Sizes.h"

class GameState
{
public:
	void AddDefeatedEnemy(Sizes size);
	int GetAmountOfDefeatedEnemiesBySize(Sizes size) const;
	int GetTotalEnemiesDefeatedAmount() const;
private:
	int TotalEnemiesDefeated = 0;
	int SmallEnemiesDefeated = 0;
	int MediumEnemiesDefeated = 0;
	int BigEnemiesDefeated = 0;
};

