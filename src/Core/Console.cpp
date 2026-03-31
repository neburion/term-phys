#include "Core/Console.hpp"
#include <sys/types.h>

std::string Console::lines[MAX_LINES];
int Console::currentLine = 0;

void Console::log(const std::string &msg) {
    lines[currentLine] = msg;
    currentLine = (currentLine + 1) % MAX_LINES;
}

std::string &Console::getLineByDescendingIndex(uint index){
    if(index >= MAX_LINES){
        log("Out of bounds index called the console.");
        return lines[currentLine];
    }

    return lines[index];
}

std::string &Console::getLineByAscendingIndex(uint offset){
    return getLineByDescendingIndex(currentLine - offset);
}
