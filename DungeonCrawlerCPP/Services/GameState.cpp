#include "GameState.h"
#include "../Enemies/EnemiesManager.h"
#include "ConsolePrinter.h"

void GameState::AddDefeatedEnemy(Tiers size)
{
	switch (size)
	{
	case Dangerous:
		BigEnemiesDefeated++;
		break;
	case Balanced:
		MediumEnemiesDefeated++;
		break;
	case Weak:
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
int GameState::GetAmountOfDefeatedEnemiesBySize(Tiers size) const
{
	switch (size)
	{
	case Dangerous:
		return BigEnemiesDefeated;
		break;
	case Balanced:
		return MediumEnemiesDefeated;
		break;
	case Weak:
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

void GameState::PrintEndGameStatistics(EnemiesManager& enemiesManager) const
{
	std::string totalEnemiesDefeated = std::to_string(GameState::GetTotalEnemiesDefeatedAmount());

	std::string dangerousEnemiesDefeated = std::to_string(GameState::GetAmountOfDefeatedEnemiesBySize(Dangerous));
	std::string balancedEnemiesDefeated = std::to_string(GameState::GetAmountOfDefeatedEnemiesBySize(Balanced));
	std::string weakEnemiesDefeated = std::to_string(GameState::GetAmountOfDefeatedEnemiesBySize(Weak));

	std::string totalBigEnemies = std::to_string(enemiesManager.GetTotalEnemiesOfTier(Dangerous));
	std::string totalMediumEnemies = std::to_string(enemiesManager.GetTotalEnemiesOfTier(Balanced));
	std::string totalSmallEnemies = std::to_string(enemiesManager.GetTotalEnemiesOfTier(Weak));

	ConsolePrinter::Print("Total Enemies defeated : " + totalEnemiesDefeated);
	ConsolePrinter::Print("Dangerous : " + dangerousEnemiesDefeated + "/" + totalBigEnemies);
	ConsolePrinter::Print("Balanced : " + balancedEnemiesDefeated + "/" + totalMediumEnemies);
	ConsolePrinter::Print("Weak : " + weakEnemiesDefeated + "/" + totalSmallEnemies);
}