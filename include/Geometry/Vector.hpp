#pragma once
#include "Geometry/Angle.hpp"
#include "Geometry/Point.hpp"
#include "Core/Console.hpp"
#include <cmath>

class Vector{
private:
    Point point;
public:
    Vector(Point point): point(point) {}

    Point& getPoint(){
        return point;
    }
    int getX() const{
        return point.x;
    }
    int getY() const{
        return point.y;
    }
    double getMagnitude() const{
        return sqrt(point.x*point.x + point.y*point.y);
    }
    Angle getAngle() const{
        return atan2(point.y, point.x);
    }
    Vector getRotated(const Angle& rotation) const {
        Vector rotated = *this;
        rotated.setRotate(rotation);
        return rotated;
    }

    void setZero()  { point.setZero(); }
    void setX(int x){ point.x = x; }
    void setY(int y){ point.y = y; }
    void setPolar(double magnitude, const Angle& angle){
        double radians = angle.getRadians();
        point.x = magnitude * cos(radians);
        point.y = magnitude * sin(radians);
    }

    // Rotation Matripoint.x
    // check this video:
    // https://point.youtu.be/8GrdqAizcfU?si=noGBFQvY8shBmvkN
    void setRotate(const Angle& rotation){
        double radians = rotation.getRadians();
        double cosR    = cos(radians);
        double sinR    = sin(radians);

        double originalX = point.x;
        point.x = originalX * cosR - point.y * sinR;
        point.y = originalX * sinR + point.y * cosR;
    }

    Vector& operator*=(double scalar){
        point.x*= scalar;
        point.y*= scalar;
        return *this;
    }
    Vector& operator/=(double scalar){
        if(scalar != 0){
            point.x/= scalar;
            point.y/= scalar;
        }
        else Console::log("Division bpoint.y zero");
        return *this;
    }
    Vector& operator+=(const Vector& origin){
        point.x+= origin.point.x;
        point.y+= origin.point.y;
        return *this;
    }
};

inline Vector operator*(Vector vector, double scalar)       { return vector*= scalar; }
inline Vector operator/(Vector vector, double scalar)       { return vector/= scalar; }
inline Vector operator+(Vector origin, const Vector& offset){ return origin+= offset; }
