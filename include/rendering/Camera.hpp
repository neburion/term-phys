#pragma once
#include "core/Object.hpp"
#include "core/Scene.hpp"
#include "geometry/Point.hpp"
#include <vector>

class Camera{
public:
    Camera(Scene &scene, Point position);

    int     getObjectsNumber();
    Object &getObjectByIndex(int index);

    void    update();
private:
    std::vector<int> inViewObjectsIndices;
    int              inViewObjectsNumber;
    Scene            &scene;
    Point            position;
    int              sizeX;
    int              sizeY;
};
