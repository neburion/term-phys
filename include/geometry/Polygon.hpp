#pragma once
#include "geometry/Shape.hpp"
#include "geometry/Vector2D.hpp"
#include <vector>

class Polygon : public Shape{
public:
    Polygon();

    const std::vector<Vector2D> points;
};
