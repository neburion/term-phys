#include "Rendering/Camera.hpp"
#include "Core/Object.hpp"
#include "Geometry/Point.hpp"
#include <vector>
#include <ncurses.h>

Camera::Camera(Scene &scene, Point position):
        inViewObjectsIndices(std::vector<int>()),
        scene(scene),
        position(position.x, position.y){
    getmaxyx(stdscr, sizeY, sizeX);
}

int Camera::getObjectsNumber(){
    return inViewObjectsNumber;
}

Object &Camera::getObjectByIndex(int index){
    return scene.getObjectByIndex(index);
}

void Camera::update(){
    getmaxyx(stdscr, sizeY, sizeX);

    int sceneObjectsNumber = scene.getObejectsNumber();
    for(int i = 0; i < sceneObjectsNumber; i++){
        Object &currentObject = scene.getObjectByIndex(i);

        if(currentObject.position.getPoint().x <= sizeX
        && currentObject.position.getPoint().y <= sizeY
        && currentObject.position.getPoint().x >= 0
        && currentObject.position.getPoint().y >= 0){
            inViewObjectsNumber = scene.getObejectsNumber();
            inViewObjectsIndices.push_back(i);
        }
    }
}
