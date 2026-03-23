#pragma once
#include "geometry/Point.hpp"
#include "rendering/Color.hpp"
#include <vector>

enum class DrawMode {
    CONNECTED,
    POINTS
};

class Shape{
public:
    virtual ~Shape() = default;

    virtual std::vector<Point> getVerticies()       = 0;
    virtual int                getVerticiesNumber() = 0;
    virtual DrawMode           getDrawMode(){
        return DrawMode::CONNECTED;
    }

    Color color;
};
