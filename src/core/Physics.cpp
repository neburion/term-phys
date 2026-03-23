#include "core/Physics.hpp"
#include "core/Object.hpp"
#include "core/Scene.hpp"
#include "core/Clock.hpp"
#include "geometry/Vector2D.hpp"
#include <cmath>

Physics::Physics(Scene &scene):
    scene(scene)
{}

void Physics::update(){
    for(int i = 0; i < scene.getObejectsNumber(); i++){
        applyForce(scene.getObjectByIndex(i));
        scene.getObjectByIndex(i).position += 
            scene.getObjectByIndex(i).velocity * Clock::deltaTime;
    }
}

void Physics::applyForce(Object &object){
    Vector2D force           = object.netForce;

    double   xForce          = force.magnitude * cos(force.angle.getRadians());
    double   yForce          = force.magnitude * sin(force.angle.getRadians());

    double   xAcceleration   = xForce / object.mass;
    double   yAcceleration   = yForce / object.mass;
    Vector2D acceleration    = Vector2D(Point(0,0), Point(xAcceleration,yAcceleration));

    Vector2D currentVelocity = object.velocity;
    Vector2D newVelocity     = currentVelocity + (acceleration * Clock::deltaTime);
    
    object.velocity = newVelocity;
}
