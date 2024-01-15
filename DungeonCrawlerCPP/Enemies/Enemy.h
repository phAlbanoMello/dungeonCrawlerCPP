#pragma once
#include <string>
#include "Sizes.h"

class Enemy
{

private:
    std::string Name = "";
    int health = 0;
    int damage = 0;
    Sizes size = Small;

public:
    
    Enemy(std::string name, int h, int d, Sizes s);

    int GetHealth();
    int GetDamage();
    Sizes GetSize();
    std::string GetName();
    void TakeDamage(int damage);
};


