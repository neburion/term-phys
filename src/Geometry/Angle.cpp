#include "Geometry/Angle.hpp"
#include "Core/Constants.hpp"
#include "Core/Console.hpp"
#include <cmath>

Angle::Angle(double radians) : radians(radians) {normalize();}

void Angle::normalize(){
    radians = fmod(radians, 2*PI);
    if(radians < 0) radians += 2*PI;
}

double Angle::getRadians() const{
    return radians;
}
double Angle::getDegrees() const{
    return radians * (180 / PI);
}
Angle  Angle::getFlipped() const{
    return Angle(radians + PI);
}

void Angle::setRadians(double radians){
    this->radians = radians;
}
void Angle::setDegrees(double degrees){
    this->radians = degrees * (PI / 180);
}
void Angle::setFlipped(){
    radians += PI;
}

Angle& Angle::operator+=(const Angle& other){
    radians += other.getRadians();
    return *this;
}
Angle& Angle::operator-=(const Angle& other){
    radians -= other.getRadians();
    return *this;
}
Angle& Angle::operator*=(double scalar){
    radians *= scalar;
    return *this;
}
Angle& Angle::operator/=(double scalar){
    if(scalar == 0){
        Console::log("Division by zero");
        return *this;
    }

    radians /= scalar;

    return *this;
}

Angle operator+(Angle left, const Angle& right){
    return left  += right;
}
Angle operator-(Angle left, const Angle& right){
    return left  -= right;
}
Angle operator*(Angle angle, double scalar){
    return angle *= scalar;
}
Angle operator*(double scalar, Angle angle){
    return angle *= scalar;
}
Angle operator/(Angle angle, double scalar){
    return angle /= scalar;
}
