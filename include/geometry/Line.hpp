#pragma once
#include "geometry/Shape.hpp"
#include "geometry/Vector2D.hpp"

class Line : public Shape{
public:
    Line();

    const Vector2D a;
    const Vector2D b;
};
