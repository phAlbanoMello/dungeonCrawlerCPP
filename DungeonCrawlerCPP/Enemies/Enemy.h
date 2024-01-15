#pragma once
#include <string>
#include "../Enums/Sizes.h"
#include "../Battler.h"

class Enemy : public Battler
{
    private:
        Sizes size = None;

	public:
        Enemy(std::string name, int health, int damage, int speed);
        Sizes GetSize() const;
        void SetSize(Sizes enemySize);
        bool operator==(const Battler& other) const override {
              return dynamic_cast<const Enemy*>(&other) != nullptr;
        }
};


