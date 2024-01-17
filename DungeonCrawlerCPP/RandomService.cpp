#include "RandomService.h"
#include <random>

int RandomService::GetRandomInteger(int minRange, int maxRange, bool isMultipleOfTen) {
    if (minRange >= maxRange) {
        minRange = maxRange - 1;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(minRange, maxRange);

    int randomNumber = distribution(gen);

    if (isMultipleOfTen) {
        return (randomNumber / 10) * 10;
    }
    else {
        return randomNumber;
    }

    return randomNumber;
}

std::vector<std::string> RandomService::GetRandomStrings(const std::vector<std::string>& stringCollection, size_t amount) {
    if (stringCollection.empty() || amount == 0) {
        return {};
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> distribution(0, stringCollection.size() - 1);

    std::vector<std::string> result;

    for (size_t i = 0; i < amount; ++i) {
        size_t randomIndex = distribution(gen);
        result.push_back(stringCollection[randomIndex]);
    }

    return result;
}
