#pragma once
#include <string>

class Console{
public:
    static void        log(const std::string &msg);

    static std::string &getLineByDescendingIndex(uint index);
    std::string        &getLineByAscendingIndex(uint offset);

    static const int MAX_LINES = 5;
private:
    static std::string lines[MAX_LINES];
    static int         currentLine;
};
