#include "BattleManager.h"
#include "Services/ConsolePrinter.h"
#include "RandomService.h"

Battler& BattleManager::DetermineFirstAttacker(Battler& battlerA, Battler& battlerB) {

	int speedDifference = battlerA.GetSpeed() - battlerB.GetSpeed();
	int randomFactor = rand() % 100;
	int adjustedRandomFactor = randomFactor + speedDifference;

	if (adjustedRandomFactor > 50) {
		return battlerA;
	}
	else {
		return battlerB;
	}
}

void BattleManager::PrintPlayerData(Character& player)
{
	ConsolePrinter::Print("Name : " + player.GetName());
	PrintHealthBar(player.GetHealth());
	ConsolePrinter::Print("Speed : " + std::to_string(player.GetSpeed()));
}

Battler& BattleManager::Battle(Battler& battlerA, Battler& battlerB) {

	while (battlerA.GetHealth() > 0 && battlerB.GetHealth() > 0) {
		Battler& first = DetermineFirstAttacker(battlerA, battlerB);
		Battler& second = battlerA == first ? battlerB : battlerA;

		DealDamage(first, second);
		if (second.GetHealth() == 0)
		{
			PrintDeathFeedback(second);
			break;
		}
		DealDamage(second, first);
	}

	return battlerA.GetHealth() == 0 ? battlerB : battlerA;
}

void BattleManager::DealDamage(Battler& first, Battler& second)
{
	int firstDamage = RandomService::GetRandomInteger(first.GetMinDamage(), first.GetMaxDamage());
	second.TakeDamage(firstDamage);
	PrintDamageFeedback(first, second, firstDamage);
}

void BattleManager::PrintDeathFeedback(Battler& defeatedBattler)
{
	ConsolePrinter::PrintBorder();
	ConsolePrinter::Print(defeatedBattler.GetName() + " was defeated!");
	ConsolePrinter::PrintBorder();
}

void BattleManager::PrintDamageFeedback(Battler& damageDealer, Battler& damageTaker, int resultDamage)
{
	ConsolePrinter::Print(damageDealer.GetName() + " (HP : " + std::to_string(damageDealer.GetHealth()) + ")" + " attacked " + damageTaker.GetName() + " dealing " + std::to_string(resultDamage) + " damage.");
	ConsolePrinter::PrintBorder();
}

void BattleManager::PrintHealthBar(int hp) {
	std::string hpBar = "";

	for (size_t i = 0; i < hp; i++)
	{
		hpBar += "|";
	}

	ConsolePrinter::Print("HP : " + hpBar);
}

void BattleManager::PrintEnemyData(Enemy& enemy) {
	ConsolePrinter::Print("Name : " + enemy.GetName());
	PrintHealthBar(enemy.GetHealth());
	ConsolePrinter::Print("Size : " + enemy.GetTierString());
	ConsolePrinter::Print("Speed :" + std::to_string(enemy.GetSpeed()));
}