#pragma once
#include "geometry/Angle.hpp"

class Vector2D{
public:
    Vector2D(double x, double y);

    double getMagnitudeSquared() const;
    double getMagnitude() const;
    Angle  getAngle() const;

    void   setPolar(double magnitude, Angle angle);

    double x;
    double y;
};
