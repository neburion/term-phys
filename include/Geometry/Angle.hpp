#pragma once
#include "Core/Constants.hpp"
#include "Core/Console.hpp"
#include <cmath>

class Angle{
private:
    double radians;
public:
    Angle(double radians) : radians(radians) {normalize();}

    void normalize(){
        radians = fmod(radians, 2*PI);
        if(radians < 0) radians += 2*PI;
    }

    double getRadians() const { return radians; }
    double getDegrees() const { return radians * (180 / PI); }
    Angle  getFlipped() const { return Angle(radians + PI); }

    void setRadians(double radians) { this->radians = radians; }
    void setDegrees(double degrees) { this->radians = degrees * (PI / 180); }
    void setFlipped()               { radians += PI; }

    auto operator<=>(const Angle& other) const = default;
    Angle& operator+=(const Angle& other){
        radians += other.getRadians();
        return *this;
    }
    Angle& operator-=(const Angle& other){
        radians -= other.getRadians();
        return *this;
    }
    Angle& operator*=(double scalar){
        radians *= scalar;
        return *this;
    }
    Angle& operator/=(double scalar){
        if(scalar == 0){
            Console::log("Division by zero");
            return *this;
        }
        radians /= scalar;
        return *this;
    }
};

inline Angle operator+(Angle  left,   const Angle& right) {return left  += right;}
inline Angle operator-(Angle  left,   const Angle& right) {return left  -= right;}
inline Angle operator*(Angle  angle,  double       scalar){return angle *= scalar;}
inline Angle operator*(double scalar, Angle        angle) {return angle *= scalar;}
inline Angle operator/(Angle  angle,  double       scalar){return angle /= scalar;}
