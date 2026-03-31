#include "Physics/Physics.hpp"
#include "Core/Scene.hpp"
#include "Core/Object.hpp"
#include "Core/Clock.hpp"
#include "Geometry/Vector.hpp"
#include <cmath>

Physics::Physics(Scene &scene):scene(scene){}

void Physics::update(){
    for(int i = 0; i < scene.getObejectsNumber(); i++){
        Object& currentObject = scene.getObjectByIndex(i);

        applyVelocity(currentObject);
        applyAngularVelocity(currentObject);
        applyNetForce(currentObject);
        applyNetTorque(currentObject);
    }
}

void Physics::applyVelocity(Object& object){
    object.position += object.velocity * Clock::deltaTime;
}

void Physics::applyAngularVelocity(Object& object){
    object.orientation += object.angularVelocity * Clock::deltaTime;
}

void Physics::applyNetForce(Object& object){
    double mass              = object.mass;
    Vector currentVelocity   = object.velocity;
    Vector force             = object.netForce;

    Vector acceleration      = force / mass;
    Vector newVelocity       = currentVelocity + acceleration * Clock::deltaTime;
    object.velocity          = newVelocity;
    object.netForce.setZero();
}

void Physics::applyNetTorque(Object& object){
    double momentOfInertia        = object.momentOfInertia;
    Angle  currentAngularVelocity = object.angularVelocity;
    Angle  torque                 = object.netTorque;

    Angle  angularAcceleration    = torque / momentOfInertia;
    Angle  newAngularVelocity     = currentAngularVelocity+
                                     angularAcceleration * Clock::deltaTime;
    object.angularVelocity        = newAngularVelocity;
    object.netTorque.setRadians(0);
}

// Separating Axis Theorem
// check this video:
// https://youtu.be/dn0hUgsok9M?si=e_K7xvxChn6aHQL4
bool Physics::areColliding(Object& a, Object& b){
    // for both shapes take every normal
    // for each normal and get the lowest and highest point on the normal
    // project these points for both shapes on the normal
    // check if they overlap
    // if they don't overlap in at least one normal they are not colliding

    return false;
}
