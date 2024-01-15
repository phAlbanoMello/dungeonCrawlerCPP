#define CONSOLE_PRINTER_H
#include "ConsolePrinter.h"

void ConsolePrinter::Print(const std::string message) {
    std::cout << message << std::endl;
}

void ConsolePrinter::PrintError(const std::string message) {
    std::cerr << "Error: " << message << std::endl;
}

void ConsolePrinter::PrintWarning(const std::string message) {
    std::cout << "Warning: " << message << std::endl;
}
void ConsolePrinter::JumpLines(int linesToJump) {
    int lineCount = linesToJump <= 0 ? 1 : linesToJump;
    for (size_t i = 0; i < lineCount; i++)
    {
        std::cout << std::endl;
    }
}

void ConsolePrinter::PrintBorder(int size) {
    for (size_t i = 0; i < size; i++)
    {
        std::cout << "---------------------------------------------------" << std::endl;
    }
}