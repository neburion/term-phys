#include "core/Object.hpp"
#include "core/Clock.hpp"
#include "core/Constants.hpp"
#include "geometry/Circle.hpp"
#include "geometry/Polygon.hpp"
#include "rendering/Renderer.hpp"
#include "geometry/Point.hpp"
#include "geometry/Line.hpp"
#include <memory>
#include <ncurses.h>

int main(){
    Scene    scene    = Scene();
    Clock    clock    = Clock();
    Renderer renderer = Renderer();
    Camera   camera   = Camera(scene, Point(0,0));

    Line     line     = Line(Point(1,1),Point(10,10));
    Object   o1       = Object("line",
                               std::make_unique<Line>(line),
                               0, 0, 0, 0,
                               Point(0,0),
                               Angle(0));

    Circle   circle   = Circle(10);
    Object   o2       = Object("circle",
                               std::make_unique<Circle>(circle),
                               0, 0, 0, 0,
                               Point(25,15),
                               Angle(0));

    std::vector<Point> points;
    points.push_back(Point(-10, 10));
    points.push_back(Point( 10, 10));
    points.push_back(Point(  0,-10));
    Polygon polygon = Polygon(points);
    Object  o3      = Object("triangle",
                             std::make_unique<Polygon>(polygon),
                             0, 0, 0, 0,
                             Point(25,15),
                             Angle(0));

    scene.addObject(std::make_unique<Object>(std::move(o1)));
    scene.addObject(std::make_unique<Object>(std::move(o2)));
    scene.addObject(std::make_unique<Object>(std::move(o3)));

    while(1){
        if(clock.isTick()){
            //physics.update();
            camera.update();
            renderer.drawCamera(camera);
        }
    }
    return 0;
}
