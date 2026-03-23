#include "geometry/Point.hpp"
#include "geometry/Vector2D.hpp"
#include <cmath>

Point::Point(double x, double y): x(x), y(y){}

Point operator+(Point point, double d){
    return Point(point.x + d, point.x + d);
}

Point operator+=(Point point, double d){
    return point + d;
}

Point operator+(Point point, Vector2D vector){
    return Point(point.x + vector.magnitude * cos(vector.angle.getRadians()),
                 point.y + vector.magnitude * sin(vector.angle.getRadians()));
}

Point operator+=(Point point, Vector2D vector){
    return point + vector;
}

Point operator+(Point point, Angle angle){
    double cosAngle = cos(angle.getRadians());
    double sinAngle = sin(angle.getRadians());

    return Point(point.x * cosAngle + point.y * sinAngle,
                 point.x * sinAngle + point.y * cosAngle);
}
