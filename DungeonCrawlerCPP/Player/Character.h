#pragma once
#include <string>
#include "../Battler.h"

class Character : public Battler
{
public:
	Character(std::string name, int health, std::tuple<int,int> damage, int speed);

    bool operator==(const Battler& other) const override {
        return dynamic_cast<const Character*>(&other) != nullptr;
    }
};

