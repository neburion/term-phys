#pragma once
#include "geometry/Shape.hpp"
#include "geometry/Point.hpp"

class Line : public Shape{
public:
    Line(Point start, Point end);

    std::vector<Point> getVerticies()       override;
    int                getVerticiesNumber() override;

    const Point a;
    const Point b;
};
