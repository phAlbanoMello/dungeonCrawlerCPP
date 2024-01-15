#include "InputValidator.h"
#include <iostream>

int InputValidator::GetValidIntInputWithinRange(int minRange, int maxRange) {
    int playerInput;

    while (true) {
        if (std::cin >> playerInput) {
            if (playerInput >= minRange && playerInput <= maxRange) {
                break;
            }
            else {
                std::cout << "Invalid input. Please enter a number within the specified range." << std::endl;
            }
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid integer." << std::endl;
        }
    }

    return playerInput;
}

std::string InputValidator::GetValidStringInput()
{
    std::string result;
    std::getline(std::cin, result);
    return result;
    //TODO:Test inputs that mught result in errors
}
