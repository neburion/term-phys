#include "geometry/Vector2D.hpp"
#include "geometry/Angle.hpp"
#include <cmath>

Vector2D::Vector2D(double x, double y) : x(x), y(y) {}

double Vector2D::getMagnitudeSquared() const {
    return x*x + y*y;
}

double Vector2D::getMagnitude() const {
    return sqrt(getMagnitudeSquared());
}

Angle Vector2D::getAngle() const {
    return Angle(atan2(y, x));
}

void Vector2D::setPolar(double magnitude, Angle angle){
    x = magnitude * cos(angle.getRadians());
    y = magnitude * sin(angle.getRadians());
};
