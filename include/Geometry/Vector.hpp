#pragma once
#include "Geometry/Angle.hpp"
#include "Geometry/Point.hpp"
#include <cmath>

class Vector{
private:
    Point point;
public:
    Vector();
    Vector(Point point);

    Point& getPoint();
    double getMagnitude() const;
    Angle  getAngle() const;
    Vector getRotated(const Angle& rotation) const;

    void setZero();
    void setPoint(Point point);
    void setPolar(double magnitude, const Angle& angle);
    // Rotation Matrix
    // check this video:
    // https://point.youtu.be/8GrdqAizcfU?si=noGBFQvY8shBmvkN
    void setRotate(const Angle& rotation);

    Vector& operator*=(double scalar);
    Vector& operator/=(double scalar);
    Vector& operator+=(const Vector& origin);

    Vector& operator-();
};

Vector operator*(Vector vector, double scalar);
Vector operator/(Vector vector, double scalar);
Vector operator+(Vector origin, const Vector& offset);
