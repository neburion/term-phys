#pragma once
#include "geometry/Angle.hpp"
#include "geometry/Point.hpp"

class Vector2D{
public:
    Vector2D(double magnitude, Angle angle);
    Vector2D(Point p1, Point p2);
    
    double magnitude;
    Angle  angle;
};

Vector2D operator+(Vector2D vectorA, Vector2D vectorB);
Vector2D operator*(Vector2D vector, double d);
Vector2D operator+(Vector2D vector, Angle angle);
