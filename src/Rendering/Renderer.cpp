#include "Rendering/Renderer.hpp"
#include "Core/Console.hpp"
#include "Core/Shape.hpp"
#include "Core/Object.hpp"
#include <memory>
#include <ncurses.h>
#include <cmath>

Renderer::Renderer(){
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    nodelay(stdscr, TRUE);
    clear();
}

Renderer::~Renderer(){
    endwin();
}

void Renderer::drawPoint(double x,double y){
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_WHITE);
    attron(COLOR_PAIR(1));
    mvwprintw(stdscr, y, x, " ");
    attroff(COLOR_PAIR(1));
}

// Bresenham's Line Algorithm
// check this video for more details:
// https://youtu.be/CceepU1vIKo?si=3TKTzkQF_QIRLytP
void Renderer::drawLine(Point pointA, Point pointB){
    double dx = pointB.x - pointA.x;
    double dy = pointB.y - pointA.y;
    double step;

    if(std::abs(dy) > std::abs(dx)){
        step = std::abs(dy);
    } else{
        step = std::abs(dx);
    }

    double stepX = dx / step;
    double stepY = dy / step;

    for(int i = 0; i <= step; i++){
        int x = pointA.x + round(i * stepX);
        int y = pointA.y + round(i * stepY);

        drawPoint(y, x);
    }
}

void Renderer::drawObject(Object &toDraw){
    int verticesNumber = toDraw.shape->getVerticesNumber();

    if(verticesNumber < 2){
        Console::log("Object with less then two vertices is trying to get rendered.");
    }

    else{
        for(int i = 0; i < verticesNumber; i++){
            drawLine(
                toDraw.getVertexByIndex(i),
                toDraw.getVertexByIndex((i+1) % verticesNumber)
            );
        }
    }
}

void Renderer::drawCamera(Camera &inViewScene){
    inViewScene.update();

    clear();
    for(int i = 0; i < inViewScene.getObjectsNumber(); i++){
        drawObject(inViewScene.getObjectByIndex(i));
    }
    refresh();
}
