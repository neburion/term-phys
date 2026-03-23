#pragma once
#include "core/Scene.hpp"
#include "core/Object.hpp"
#include "geometry/Vector2D.hpp"
#include <vector>

struct Collision{
    Vector2D pointOfContactWorldSpace;
    Vector2D pointOfContactA;
    Vector2D pointOfContactB;
    Object   &colliderA;
    Object   &colliderB;
};

class Physics{
public:
    Physics(Scene &scene);
    
    void                   update();
    void                   applyForce(Object &object);
    void                   applyTorque(Object &object);
    std::vector<Collision> detectCollisions();
    void                   resolveCollision();
private:
    Scene &scene;
};
