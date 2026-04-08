#pragma once
#include "Geometry/Angle.hpp"
#include "Geometry/Vector.hpp"
#include "Core/Shape.hpp"
#include <memory>
#include <string>

class Object{
public:
    Object(const std::string      name,
           std::unique_ptr<Shape> shape,
           double                 mass,
           double                 momentOfInertia,
           double                 restitution,
           double                 friction,
           Vector                 position,
           Angle                  orientation);

    Point getVertexByIndex(uint index);

    const std::string      name;
    std::unique_ptr<Shape> shape;

    const double           mass;            //kg
    const double           momentOfInertia; //??
    const double           restitution;     //?? (bounciness)
    const double           friction;        //??

    Vector                 position;        //m,pixel
    Angle                  orientation;     //angle

    Vector                 velocity;        //m,pixel/s
    Angle                  angularVelocity; //angle/s??
    Vector                 netForce;        //N
    Angle                  netTorque;       //??
};
