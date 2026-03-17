#pragma once
#include "core/Object.hpp"
#include "rendering/Camera.hpp"

enum class Color{
    WHITE,
    GRAY,
    BLUE,
    GREEN,
    YELLOW,
    ORANGE,
    RED,
    PINK
};

class Renderer{
public:
    Renderer();

    void drawPoint(double x,double  y, Color color);
    void drawLine(double x,double  y, Color color);
    void drawObject(Object &toDraw);
    void drawCamera(Camera &inViewScene);
};
