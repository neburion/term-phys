#include "Geometry/Vector.hpp"
#include "Geometry/Angle.hpp"
#include "Geometry/Point.hpp"
#include "Core/Console.hpp"
#include <cmath>

Vector::Vector():
    point(0,0)
{}
Vector::Vector(Point point):
    point(point)
{}

Point& Vector::getPoint(){
    return point;
}
double Vector::getMagnitude() const{
    return sqrt(point.x*point.x + point.y*point.y);
}
Angle Vector::getAngle() const{
    return atan2(point.y, point.x);
}
Vector Vector::getRotated(const Angle& rotation) const{
    Vector rotated = *this;
    rotated.setRotate(rotation);
    return rotated;
}

void Vector::setZero(){
    point.setZero();
}
void Vector::setPoint(Point point){
    this->point = point;
}
void Vector::setPolar(double magnitude, const Angle& angle){
    double radians = angle.getRadians();
    point.x = magnitude * cos(radians);
    point.y = magnitude * sin(radians);
}
void Vector::setRotate(const Angle& rotation){
    double radians = rotation.getRadians();
    double cosR    = cos(radians);
    double sinR    = sin(radians);

    double originalX = point.x;
    point.x = originalX * cosR - point.y * sinR;
    point.y = originalX * sinR + point.y * cosR;
}

Vector& Vector::operator*=(double scalar){
    point.x*= scalar;
    point.y*= scalar;
    return *this;
}
Vector& Vector::operator/=(double scalar){
    if(scalar != 0){
        point.x/= scalar;
        point.y/= scalar;
    }
    else Console::log("Division bpoint.y zero");
    return *this;
}
Vector& Vector::operator+=(const Vector& origin){
    point.x+= origin.point.x;
    point.y+= origin.point.y;
    return *this;
}

Vector& Vector::operator-(){
    point.x*= -1;
    point.y*= -1;
    return *this;
}

Vector operator*(Vector vector, double scalar){
    return vector*= scalar;
}
Vector operator/(Vector vector, double scalar){
    return vector/= scalar;
}
Vector operator+(Vector origin, const Vector& offset){
    return origin+= offset;
}
