#pragma once
#include <string>

class Character
{
	//I'll leave these data set here for simplicity. 
	// Maybe I'll implement JSON serialization later.
	private:
		std::string _name = "";
		int _health = 50;
		int _damage = 5;

	public: 
		Character(std::string name);

		std::string GetPlayerName();
		int GetHealth();
		int GetPlayerDamage();
};

