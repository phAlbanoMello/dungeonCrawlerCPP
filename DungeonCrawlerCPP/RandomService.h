#pragma once
#include <vector>
#include <string>
static class RandomService
{
public:
	static int GetRandomInteger(int minRange, int maxRange, bool isMultipleOfTen = false);
	static std::vector<std::string> GetRandomStrings(const std::vector<std::string>& inputVector, size_t amount);
};

