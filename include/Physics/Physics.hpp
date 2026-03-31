#pragma once
#include "Core/Scene.hpp"
#include "Core/Object.hpp"
#include "Geometry/Vector.hpp"

struct Collision{
    Vector pointOfContactWorldSpace;
    Vector pointOfContactA;
    Vector pointOfContactB;
    Object &colliderA;
    Object &colliderB;
};

class Physics{
public:
    Physics(Scene &scene);
    
    void update();

    void applyVelocity(Object &object);
    void applyAngularVelocity(Object &object);

    void applyNetForce(Object &object);
    void applyNetTorque(Object &object);

    bool areColliding(Object& a, Object& b);
    void resolveCollision(Object& a, Object& b);
private:
    Scene &scene;
};
