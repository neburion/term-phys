#pragma once

#include <chrono>
class Clock{
public:
    Clock();
    
    bool isTick();
    
    static constexpr double ticksPerSecond = 20;
    static constexpr double deltaTime      = 1/ticksPerSecond;
private:
    std::chrono::steady_clock::time_point previusTime;
    double                                elapsedSeconds;
};
