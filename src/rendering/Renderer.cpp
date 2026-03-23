#include "rendering/Renderer.hpp"
#include "geometry/Shape.hpp"
#include "core/Object.hpp"
#include <ncurses.h>
#include <vector>
#include <cmath>

Renderer::Renderer(){
    initscr();
    noecho();
    cbreak();
    curs_set(0);
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

// the name of the algorithm here
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
    std::vector<Point> verticies       = toDraw.shape->getVerticies();
    int                verticiesNumber = toDraw.shape->getVerticiesNumber();
    Vector2D           offset          = Vector2D(Point(0,0),toDraw.position);
    double             orientation     = toDraw.orientation.getRadians();

    if(toDraw.shape->getDrawMode() == DrawMode::CONNECTED){
        if(verticiesNumber < 2)
            mvwprintw(stdscr, verticies[0].y, verticies[0].x, "Error");

        else if(verticiesNumber == 2)
            drawLine((verticies[0]+orientation)+offset,
                     (verticies[1]+orientation)+offset);

        else{
            for(int i = 0; i < verticiesNumber-1; i++)
                drawLine((verticies[i]+orientation)+offset,
                         (verticies[i+1]+orientation)+offset);
            drawLine((verticies[0]+orientation)+offset,
                     (verticies[verticiesNumber-1]+orientation)+offset);
        }
    }

    else if(toDraw.shape->getDrawMode() == DrawMode::POINTS){
        for(int i = 0; i < verticiesNumber; i++)
            drawPoint(((verticies[i]+orientation)+offset).x,
                      ((verticies[i]+orientation)+offset).y);
    }
}

void Renderer::drawCamera(Camera &inViewScene){
    inViewScene.updateView();
    clear();
    for(int i = 0; i < inViewScene.getObjectsNumber(); i++)
        drawObject(inViewScene.getObjectByIndex(i));
    refresh();
}
