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
    Character player = Character(playerName); 
    ConsolePrinter::SeparatedSpace(1);
    ConsolePrinter::Print(playerName + ", you're here to prove your strenght. But you can choose how far you'll go.");
    ConsolePrinter::Print("How many enemies you're facing now? You must face at least " + 
        std::to_string(enemiesManager.MinEnemyCount) + " and " + std::to_string(enemiesManager.MaxEnemyCount) + " at maximum");
        
    int enemiesCount = InputValidator::GetValidIntInputWithinRange(enemiesManager.MinEnemyCount, enemiesManager.MaxEnemyCount);
    enemiesManager.LoadEnemies(enemyNames, enemiesCount);
    

    ConsolePrinter::JumpLines();
    ConsolePrinter::Print("So..." + player.GetPlayerName());
    ConsolePrinter::Print("Get ready to face " + std::to_string(enemiesCount) + " enemies");
    ConsolePrinter::JumpLines();
    ConsolePrinter::Print("Name : " + player.GetPlayerName());
    ConsolePrinter::Print("HP : " + std::to_string(player.GetHealth()));
    ConsolePrinter::JumpLines();
    
    int enemyIndex = 0;
    Enemy enemy = enemiesManager.GetEnemies()[enemyIndex];
    ConsolePrinter::Print("Enemy number " + std::to_string(enemyIndex + 1) + " is...");
    ConsolePrinter::JumpLines();
    ConsolePrinter::Print("Name : " + enemy.GetName());
    ConsolePrinter::Print("HP : " + std::to_string(enemy.GetHealth()));
    ConsolePrinter::Print("Size : " + enemiesManager.GetSizeString(enemy));
    ConsolePrinter::JumpLines();
    ConsolePrinter::Print("Press any key to fight");
    _getch();
   
    ConsolePrinter::SeparatedSpace(1);
    ConsolePrinter::Print("You attack, caused " + std::to_string(player.GetPlayerDamage()) + " dmg on " + enemy.GetName());
    enemy.TakeDamage(player.GetPlayerDamage());
    ConsolePrinter::JumpLines();
   
    ConsolePrinter::Print("Name : " + enemy.GetName());
    ConsolePrinter::Print("HP : " + std::to_string(enemy.GetHealth()));
    ConsolePrinter::Print("Size : " + enemiesManager.GetSizeString(enemy));

    
    //Write rest of battle dynamic
}



