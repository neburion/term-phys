#pragma once
#include "geometry/Shape.hpp"

class Circle : public Shape{
public:
    Circle();

    DrawMode getDrawMode() override {return DrawMode::POINTS;}

    const double radius;
};
