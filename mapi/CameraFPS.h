#pragma once
#include "Camera.h"

class CameraFPS : public Camera
{
public:
    CameraFPS(projectionType_e type, glm::vec3 position, glm::vec3 lookAt, glm::vec3 up, float speed);


    // GETTERS && SETTERS //

    float getSpeed() { return this->speed; }
    glm::vec4 getDirection() { return this->direction; }
    
    void setSpeed(float newSpeed) { this->speed = newSpeed; }
    
    
    // METHODS && FUNCTIONS //
    
    void step(double timeStep) override;
    
};
