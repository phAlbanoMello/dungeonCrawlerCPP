#include "CursorService.h"
#include <windows.h>
#include <string>
#include <iostream>

void CursorService::SaveCursorPosition(std::string id) {
    CONSOLE_SCREEN_BUFFER_INFO consoleData;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleData);
    int row = consoleData.dwCursorPosition.Y;
    int col = consoleData.dwCursorPosition.X;

    CursorService::CursorPos cursorPos = CursorPos();
    cursorPos.col = col;
    cursorPos.row = row;

    CursorService::CursorPositions.insert(std::make_pair(id, cursorPos));
}

CursorService::CursorPos CursorService::RetrieveCursorPosition(const std::string& id) {
    auto cursorPos = CursorService::CursorPositions.find(id);

    if (cursorPos != CursorService::CursorPositions.end()) {

        return cursorPos->second;
    }
    else {
        std::cerr << "CursorPos with id " << id << " not found." << std::endl;
        return CursorService::CursorPos{ 0, 0 };
    }
}

void CursorService::MoveCursorToPosition(const CursorPos& savedPos) {
    COORD newPos = { savedPos.col, savedPos.row };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), newPos);
}