#pragma once
#include <map>
#include <string>

class CursorService {
public:
    struct CursorPos {
        int row;
        int col;
    };

    void SaveCursorPosition(std::string id);
    void MoveCursorToPosition(const CursorPos& savedPos);
    CursorPos RetrieveCursorPosition(const std::string& id);
private:
    std::map<std::string, CursorPos> CursorPositions;
};

