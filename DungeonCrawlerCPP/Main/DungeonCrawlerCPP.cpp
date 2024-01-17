#include <iostream>
#include <limits>
#include <random>
#include <vector>
#include <string>
#include <conio.h>

#include "../Services/ConsolePrinter.h"
#include "../Services/InputValidator.h"
#include "../Services/FileReader.cpp"
#include "../Services/GameState.h"
#include "../Services/CursorService.h"
#include "../Player/Character.h"
#include "../Enemies/Enemy.h"
#include "../Enemies/EnemiesManager.h"

#include "DungeonCrawlerCPP.h"
#include "../Battler.h"
#include "../RandomService.h"
#include "../BattleManager.h"


int main()
{
	Play();
}

void Play()
{
	EnemiesManager enemiesManager = EnemiesManager();
	GameState gameState = GameState();
	CursorService cursorService = CursorService();
	BattleManager battleManager = BattleManager();

	std::string enemyNamesFilePath = enemiesManager.GetEnemyNamesFilePath();
	std::vector<std::string> enemyNames = ReadNamesFromFile(enemyNamesFilePath);

	ConsolePrinter::Print("Enter your name, tarnished");

	std::string playerName = InputValidator::GetValidStringInput();

	Character player = Character(playerName, 100, { 10, 50 }, 50);

	ConsolePrinter::PrintBorder();
	ConsolePrinter::Print(playerName + ", you're here to prove your strenght. But you can choose how far you'll go.");
	ConsolePrinter::Print("How many enemies you're facing now? You must face at least " +
		std::to_string(enemiesManager.MinEnemyCount) + " and " + std::to_string(enemiesManager.MaxEnemyCount) + " at maximum");

	int enemiesCount = InputValidator::GetValidIntInputWithinRange(enemiesManager.MinEnemyCount, enemiesManager.MaxEnemyCount);
	enemiesManager.LoadEnemies(enemyNames, enemiesCount);

	ConsolePrinter::JumpLines();
	ConsolePrinter::Print("So..." + player.GetName());
	ConsolePrinter::Print("Get ready to face " + std::to_string(enemiesCount) + " enemies");
	ConsolePrinter::PrintBorder(2);
	size_t enemyIndex = 0;

	std::vector<Enemy> enemies = enemiesManager.GetEnemies();

	while (gameState.GetTotalEnemiesDefeatedAmount() < enemiesCount && enemyIndex < enemies.size()) {
		Enemy enemy = enemiesManager.GetEnemies()[enemyIndex];
		battleManager.PrintPlayerData(player);
		ConsolePrinter::PrintBorder();
		ConsolePrinter::Print("Enemy number " + std::to_string(enemyIndex + 1) + " is...");
		ConsolePrinter::PrintBorder();
		battleManager.PrintEnemyData(enemy);
		ConsolePrinter::PrintBorder();
		ConsolePrinter::Print("Press any key to fight");
		_getch();

		ConsolePrinter::PrintBorder();
		Battler& winner = battleManager.Battle(player, enemy);
		ConsolePrinter::PrintBorder();

		if (winner == player)
		{
			gameState.AddDefeatedEnemy(enemy.GetSize());
			ConsolePrinter::Print("Congratulations Tarnished, you won this battle!");
			ConsolePrinter::Print("Total defeated enemies : " + std::to_string(gameState.GetTotalEnemiesDefeatedAmount()));
			ConsolePrinter::PrintBorder();
		}
		else
		{
			ConsolePrinter::Print("You died");
			break;
		}

		if (gameState.GetTotalEnemiesDefeatedAmount() == enemiesCount)
		{
			//TODO: 
			// - Get player input so it can choose to either start again or quit

			ConsolePrinter::Print("You've defeated all enemies!!");
			ConsolePrinter::PrintBorder(3);

			gameState.PrintEndGameStatistics(enemiesManager);

			break;
		}
		ConsolePrinter::Print("Get ready for the next enemy!");
		ConsolePrinter::PrintBorder();
		++enemyIndex;
	}
}




