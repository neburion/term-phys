#include "core/Clock.hpp"
#include <chrono>

Clock::Clock():
    previusTime(std::chrono::steady_clock::now()),
    elapsedSeconds(0)
{}

bool Clock::isTick(){
    auto currentTime = std::chrono::steady_clock::now();
    elapsedSeconds   = std::chrono::duration<double>(currentTime - previusTime).count();

    if(elapsedSeconds > (1.0/ticksPerSecond)){
        previusTime = currentTime;
        return true;
    }
        
    else
        return false;
}
