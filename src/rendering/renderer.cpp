#include "rendering/Renderer.hpp"

Renderer::Renderer(){}

void Renderer::drawCamera(Camera &inViewScene){
    for(int i = 0; i < inViewScene.getObjectsNumber(); i++)
        drawObject(inViewScene.getObjectByIndex(i));
}
