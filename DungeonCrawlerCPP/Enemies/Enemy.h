#pragma once
#include <string>
#include "../Enums/Sizes.h"
#include "../Battler.h"

class Enemy : public Battler
{
    private:
        Tiers size = None;

	public:
        Enemy(std::string name, int health, std::tuple<int, int> damageRange, int speed);
        Tiers GetSize() const;
        void SetSize(Tiers enemySize);
        std::string GetTierString();
        bool operator==(const Battler& other) const override {
              return dynamic_cast<const Enemy*>(&other) != nullptr;
        }
};


