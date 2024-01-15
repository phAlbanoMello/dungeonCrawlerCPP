#pragma once
#include <string>

static class InputValidator
{
public:
	static std::string GetValidStringInput();
	static int GetValidIntInputWithinRange(int minRange, int maxRange);

private:

};


