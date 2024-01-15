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


int main()
{
	//Initialize enemies list
	EnemiesManager enemiesManager = EnemiesManager();
	GameState gameState = GameState();
	CursorService cursorService = CursorService();

	std::string enemyNamesFilePath = enemiesManager.GetEnemyNamesFilePath();
	std::vector<std::string> enemyNames = ReadNamesFromFile(enemyNamesFilePath);

	ConsolePrinter::Print("Enter your name, tarnished");

	std::string playerName = InputValidator::GetValidStringInput();

	Character player = Character(playerName, 100, 20, 50);
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
		PrintPlayerStats(player);
		ConsolePrinter::PrintBorder();
		ConsolePrinter::Print("Enemy number " + std::to_string(enemyIndex + 1) + " is...");
		ConsolePrinter::PrintBorder();
		ConsolePrinter::Print("Name : " + enemy.GetName());
		PrintHealthBar(enemy.GetHealth());
		ConsolePrinter::Print("Size : " + enemiesManager.GetSizeString(enemy));
		ConsolePrinter::PrintBorder();
		ConsolePrinter::Print("Press any key to fight");
		_getch();

		ConsolePrinter::PrintBorder();
		Battler& winner = Battle(player, enemy);
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
			ConsolePrinter::Print("Try Again? (Y/N)");
			break;
		}

		if (gameState.GetTotalEnemiesDefeatedAmount() == enemiesCount)
		{
			//TODO: - Count amount of each enemy size on the list
			// - Randomize damage
			// - Reafactor Size picking to take speed
			// - Highlight enemy speciality on enemy status
			// - Get player input so it can choose to either start again or quit
			// - All enemies are coming big????

			ConsolePrinter::Print("You've defeated all enemies!!");
			ConsolePrinter::PrintBorder(3);
			ConsolePrinter::Print("Total Enemies defeated : " + std::to_string(gameState.GetTotalEnemiesDefeatedAmount()));
			ConsolePrinter::Print("Big : " + std::to_string(gameState.GetAmountOfDefeatedEnemiesBySize(Big)));
			ConsolePrinter::Print("Medium : " + std::to_string(gameState.GetAmountOfDefeatedEnemiesBySize(Medium)));
			ConsolePrinter::Print("Small : " + std::to_string(gameState.GetAmountOfDefeatedEnemiesBySize(Small)));
			break;
		}
		ConsolePrinter::Print("Get ready for the next enemy!");
		ConsolePrinter::PrintBorder();
		++enemyIndex;
	}
}

void PrintPlayerStats(Character& player)
{
	ConsolePrinter::Print("Name : " + player.GetName());
	PrintHealthBar(player.GetHealth());
	ConsolePrinter::Print("Speed : " + std::to_string(player.GetSpeed()));
}



Battler& Battle(Battler& battlerA, Battler& battlerB) {
	//Speed check

	Battler& first = (battlerA.GetSpeed() > battlerB.GetSpeed()) ? battlerA : battlerB;
	Battler& second = (battlerA.GetSpeed() > battlerB.GetSpeed()) ? battlerB : battlerA;

	while (battlerA.GetHealth() > 0 && battlerB.GetHealth() > 0) {
		second.TakeDamage(first.GetDamage());
		PrintDamageFeedback(first, second);
		if (second.GetHealth() == 0)
		{
			PrintDeathFeedback(second);
			break;
		}
		first.TakeDamage(second.GetDamage());
		PrintDamageFeedback(second, first);
	}

	if (first.GetHealth() == 0)
	{
		return second;
	}
	else {
		return first;
	}
}

void PrintDeathFeedback(Battler& defeatedBattler)
{
	ConsolePrinter::PrintBorder();
	ConsolePrinter::Print(defeatedBattler.GetName() + " was defeated!");
	ConsolePrinter::PrintBorder();
}

void PrintDamageFeedback(Battler& damageDealer, Battler& damageTaker)
{
	ConsolePrinter::Print(damageDealer.GetName() + " attacked " + damageTaker.GetName() + " dealing " + std::to_string(damageDealer.GetDamage()) + " damage.");
	ConsolePrinter::Print(std::to_string(damageDealer.GetHealth()) + " " + std::to_string(damageTaker.GetHealth()));
	ConsolePrinter::PrintBorder();
}

void PrintHealthBar(int hp) {
	std::string hpBar = "";
	
	for (size_t i = 0; i < hp; i++)
	{
		hpBar += "|";
	}

	ConsolePrinter::Print("HP : " + hpBar);
}