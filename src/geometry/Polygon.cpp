#include "geometry/Polygon.hpp"

Polygon::Polygon(std::vector<Point> points): points(points){}

std::vector<Point> Polygon::getVerticies(){
    return points;
}

int Polygon::getVerticiesNumber(){
    return getVerticies().size();
}
