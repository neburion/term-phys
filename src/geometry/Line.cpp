#include "geometry/Line.hpp"
#include "geometry/Point.hpp"
#include <vector>

Line::Line(Point start, Point end):
    a(start.x, start.y),
    b(end.x,   end.y)
{}

std::vector<Point> Line::getVerticies(){
    std::vector<Point> verticies;

    verticies.push_back(a);
    verticies.push_back(b);

    return verticies;
}

int Line::getVerticiesNumber(){
    return 2;
}
