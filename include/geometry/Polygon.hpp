#pragma once
#include "geometry/Shape.hpp"
#include "geometry/Point.hpp"
#include <vector>

class Polygon : public Shape{
public:
    Polygon(std::vector<Point> points);

    std::vector<Point> getVerticies()       override;
    int                getVerticiesNumber() override;

    const std::vector<Point> points;
};
