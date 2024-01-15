#include "GameState.h"

void GameState::AddDefeatedEnemy(Sizes size)
{
	switch (size)
	{
	case Big:
		BigEnemiesDefeated++;
		break;
	case Medium:
		MediumEnemiesDefeated++;
		break;
	case Small:
		SmallEnemiesDefeated++;
		break;
	default:
		break;
	}

	TotalEnemiesDefeated = BigEnemiesDefeated + MediumEnemiesDefeated + SmallEnemiesDefeated;
}

/// <summary>
/// Returns the amount of defeated enemies by size
/// </summary>
/// <param name="size">Will return the total amount of defeated enemies if 'None' is passed</param>
/// <returns></returns>
int GameState::GetAmountOfDefeatedEnemiesBySize(Sizes size) const
{
	switch (size)
	{
	case Big:
		return BigEnemiesDefeated;
		break;
	case Medium:
		return MediumEnemiesDefeated;
		break;
	case Small:
		return SmallEnemiesDefeated;
		break;
	default:
		return TotalEnemiesDefeated;
		break;
	}
}

int GameState::GetTotalEnemiesDefeatedAmount() const
{
	return TotalEnemiesDefeated;
}
