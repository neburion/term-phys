#pragma once
#include "geometry/Shape.hpp"
#include "geometry/Point.hpp"

class Circle : public Shape{
public:
    Circle(double radius);

    std::vector<Point>    getVerticies()       override;
    int                   getVerticiesNumber() override;
    DrawMode              getDrawMode()        override{
        return DrawMode::POINTS;
    }

    const double radius;
};
