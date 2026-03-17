#pragma once
#include "geometry/Vector2D.hpp"
#include <vector>

enum class DrawMode { CONNECTED, POINTS };

class Shape{
public:
    virtual std::vector<Vector2D> getVerticies() = 0;
    virtual DrawMode getDrawMode(){return DrawMode::CONNECTED;}
};
