#pragma once

void PrintDamageFeedback(Battler& first, Battler& second);

void PrintDeathFeedback(Battler& second);

void PrintHealthBar(int hp);

Battler& Battle(Battler& battlerA, Battler& battlerB);

void PrintPlayerStats(Character& player);

void PrintEndGameStatistics(GameState& gameState, EnemiesManager& enemiesManager);
