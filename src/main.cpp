#include "Core/Scene.hpp"
#include "Core/Object.hpp"
#include "Core/Clock.hpp"
#include "Core/Constants.hpp"
#include "Geometry/Vector.hpp"
#include "Physics/Physics.hpp"
#include "Geometry/Point.hpp"
#include "Geometry/Angle.hpp"
#include "Rendering/Renderer.hpp"
#include "Rendering/Camera.hpp"
#include <ncurses.h>
#include <vector>
#include <memory>

std::vector<Vector> makeTestTrianlge(){
    std::vector<Vector> points;
    points.push_back(Vector(Point(-10, 10)));
    points.push_back(Vector(Point( 10, 10)));
    points.push_back(Vector(Point(  0,-10)));
    return points;
}

Scene testScene(){
    Scene testScene = Scene();

    
    Shape triangle  = Shape(makeTestTrianlge());
    Object  o1      = Object("triangle", std::make_unique<Shape>(triangle),
                             1, 1, 1, 1, Point(35,15), Angle(1));
    testScene.addObject(std::make_unique<Object>(std::move(o1)));

    return testScene;
}

int main(){
    Scene    scene    = testScene();
    Clock    clock    = Clock();
    Physics  physics  = Physics(scene);
    Renderer renderer = Renderer();
    Camera   camera   = Camera(scene, Point(0,0));

    char quitKey   = 'q';
    char rotateKey = 'r';
    char upKey     = 'w';
    char downKey   = 's';
    char leftKey   = 'a';
    char rightKey  = 'd';

    int tmpCounter  = 0;

    while(1){
        clock.update();

        int  controlled = 0;
        char keyPress   = getch();

        if(keyPress == quitKey)
            break;
        else if(keyPress == upKey)
            scene.getObjectByIndex(controlled).netForce.setPolar(100, Angle(PI));
        else if(keyPress == downKey)
            scene.getObjectByIndex(controlled).netForce.setPolar(100, Angle(0));
        else if(keyPress == leftKey)
            scene.getObjectByIndex(controlled).netForce.setPolar(100, Angle(3*PI/2));
        else if(keyPress == rightKey)
            scene.getObjectByIndex(controlled).netForce.setPolar(100, Angle(PI/2));
        else if(keyPress == rotateKey)
            scene.getObjectByIndex(controlled).netTorque.setRadians(10);

        while(clock.isTick()){
            physics.update();
            tmpCounter++;
        }

        if(clock.isFrame()){
            camera.update();
            renderer.drawCamera(camera);
        }
    }

    return 0;
}
