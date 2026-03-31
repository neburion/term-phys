#include "Core/Object.hpp"
#include "Geometry/Angle.hpp"
#include "Geometry/Vector.hpp"

Object::Object(
    const std::string      name,
    std::unique_ptr<Shape> shape,
    double                 mass,
    double                 momentOfInertia,
    double                 restitution,
    double                 friction,
    Vector                 position,
    Angle                  orientation) :
        name           (name),
        shape          (std::move(shape)),

        mass           (mass),
        momentOfInertia(momentOfInertia),
        restitution    (restitution),
        friction       (friction),

        position       (position),
        orientation    (orientation),
        velocity       (Vector(Point(0,0))),
        angularVelocity(Angle(0)),
        netForce       (Vector(Point(0,0))),
        netTorque      (Angle(0))
{}
