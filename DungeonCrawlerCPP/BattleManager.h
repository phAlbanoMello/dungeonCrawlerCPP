#pragma once
#include "Battler.h"
#include "Player/Character.h"
#include "Services/GameState.h"
#include "Enemies/EnemiesManager.h"

class BattleManager
{
public:
	void PrintDamageFeedback(Battler& first, Battler& second, int resultDamage);

	void PrintDeathFeedback(Battler& second);

	void PrintHealthBar(int hp);

	Battler& Battle(Battler& battlerA, Battler& battlerB);

	void DealDamage(Battler& first, Battler& second);

	void PrintPlayerData(Character& player);

	void PrintEnemyData(Enemy& enemy);

	Battler& DetermineFirstAttacker(Battler& battlerA, Battler& battlerB);
};

