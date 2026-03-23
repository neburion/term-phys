#pragma once
#include "geometry/Angle.hpp"

class Vector2D;

class Point{
public:
    Point(double x, double y);

    Point offset(Vector2D offset);

    double x;
    double y;
};

Point operator+(Point point, double d);
Point operator+=(Point point, double d);
Point operator+(Point point, Vector2D vector);
Point operator+=(Point point, Vector2D vector);
Point operator+(Point point, Angle angle);
