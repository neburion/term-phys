#include "geometry/Vector2D.hpp"
#include "geometry/Angle.hpp"
#include <cmath>

Vector2D::Vector2D(double magnitude, Angle angle):
    magnitude(magnitude),
    angle(angle)
{}

Vector2D::Vector2D(Point p1, Point p2):
    magnitude(sqrt((p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y))),
    angle(atan2((p2.y - p1.y), (p2.x - p1.x)))
{}

Vector2D operator+(Vector2D vectorA, Vector2D vectorB){
    double ax = vectorA.magnitude * cos(vectorA.angle.getRadians());
    double ay = vectorA.magnitude * sin(vectorA.angle.getRadians());
    double bx = vectorB.magnitude * cos(vectorB.angle.getRadians());
    double by = vectorB.magnitude * sin(vectorB.angle.getRadians());
    return Vector2D(Point(0,0), Point(ax+bx, ay+by));
}

Vector2D operator*(Vector2D vector, double d){
    double x = vector.magnitude * cos(vector.angle.getRadians());
    double y = vector.magnitude * sin(vector.angle.getRadians());
    return Vector2D(Point(0,0), Point(x*d, y*d));
}

Vector2D operator+(Vector2D vector, Angle angle){
    return Vector2D(vector.magnitude,
                    Angle(vector.angle.getRadians()+angle.getRadians()));
}
