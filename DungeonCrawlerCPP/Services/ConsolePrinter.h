#pragma once

#include <iostream>
#include <string>

class ConsolePrinter {
public:
   
    static void Print(const std::string message);
    static void PrintError(const std::string message);
    static void PrintWarning(const std::string message);
    static void JumpLines(int linesToJump = 1);
    static void SeparatedSpace(int size);
};
