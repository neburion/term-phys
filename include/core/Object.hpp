#pragma once
#include "geometry/Angle.hpp"
#include "geometry/Vector2D.hpp"
#include "geometry/Shape.hpp"
#include <algorithm>
#include <memory>
#include <string>

class Object{
    friend class World;
public:
    std::string            name;
    std::unique_ptr<Shape> shape;
private:
    double                 mass;
    double                 restitution; // bounciness
    double                 friction;

    Vector2D               position;
    Angle                  orientation;
    Vector2D               velocity;
    double                 angularVel;

    Vector2D               netForce;
    double                 netTorque;
};
