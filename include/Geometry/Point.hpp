#pragma once
#include <cmath>

class Point{
public:
    Point(double x, double y): x(x), y(y){}

    void setZero(){
        x = 0;
        y = 0;
    }

    double x;
    double y;
};
