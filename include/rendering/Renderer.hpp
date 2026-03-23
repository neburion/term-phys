#pragma once
#include "core/Object.hpp"
#include "rendering/Camera.hpp"
#include "rendering/Color.hpp"

class Renderer{
public:
    Renderer();
    ~Renderer();

    void  drawPoint(double x,double y);
    void  drawLine(Point pointA, Point pointB);
    void  drawObject(Object &toDraw);
    void  drawCamera(Camera &inViewScene);

    Color getColor();

    void  setColor(Color newColor);
};
