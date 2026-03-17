#pragma once
#include "core/Object.hpp"
#include "core/Scene.hpp"
#include "geometry/Vector2D.hpp"
#include <vector>

class Camera{
public:
    Camera(Scene scene);

    int    getObjectsNumber();
    Object &getObjectByIndex(int index);
    Object &getObjectByName();

    void   updateView();
private:
    std::vector<int> inViewObjectsIndices;
    Vector2D         position;
    double           zoom;
};
