#pragma once
#include "geometry/Angle.hpp"
#include "geometry/Vector2D.hpp"
#include "geometry/Shape.hpp"
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
           Point                  position,
           Angle                  orientation);

    const std::string      name;
    std::unique_ptr<Shape> shape;

    const double           mass;
    const double           momentOfInertia;
    const double           restitution; // bounciness
    const double           friction;

    Point                  position;
    Angle                  orientation;

    Vector2D               velocity;
    Angle                  angularVelocity;
    Vector2D               netForce;
    Angle                  netTorque;
};
