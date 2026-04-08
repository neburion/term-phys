#pragma once
#include <cmath>

class Angle{
private:
    double radians;
public:
    Angle(double radians);

    void normalize();

    double getRadians() const;
    double getDegrees() const;
    Angle  getFlipped() const;

    void setRadians(double radians);
    void setDegrees(double degrees);
    void setFlipped();

    auto operator<=>(const Angle& other) const = default;
    Angle& operator+=(const Angle& other);
    Angle& operator-=(const Angle& other);
    Angle& operator*=(double scalar);
    Angle& operator/=(double scalar);
};

Angle operator+(Angle  left,   const Angle& right);
Angle operator-(Angle  left,   const Angle& right);
Angle operator*(Angle  angle,  double       scalar);
Angle operator*(double scalar, Angle        angle);
Angle operator/(Angle  angle,  double       scalar);
