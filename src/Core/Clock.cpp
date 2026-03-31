#include "Core/Clock.hpp"
#include <chrono>

Clock::Clock():
    currentTime(std::chrono::steady_clock::now()),
    lastTick(std::chrono::steady_clock::now()),
    lastFrame(std::chrono::steady_clock::now())
{}

void Clock::update(){
    currentTime = std::chrono::steady_clock::now();
}

bool Clock::isTick(){
    std::chrono::duration<double> elapsedTime = currentTime - lastTick;

    if(elapsedTime.count() >= deltaTime){
        lastTick = currentTime;
        return true;
    }

    return false;
}

bool Clock::isFrame(){
    std::chrono::duration<double> elapsedTime = currentTime - lastFrame;

    if(elapsedTime.count() >= deltaFrame){
        lastFrame = currentTime;
        return true;
    }

    return false;
}
