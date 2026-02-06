#pragma once

#include "common.h"
#include "Camera.h"

class CameraKeyboard : public Camera
{
private:

    // ATTRIBUTES //

    float speed;
    float rotSpeed;
    glm::vec4 direction;


public:

    // CONSTRUCTOR//

    CameraKeyboard(projectionType_e type, glm::vec3 position, glm::vec3 lookAt, glm::vec3 up, float speed);


    // GETTERS && SETTERS //

    float getSpeed() { return this->speed; }
    glm::vec4 getDirection() { return this->direction; }
    
    void setSpeed(float newSpeed) { this->speed = newSpeed; }
    
    
    // METHODS && FUNCTIONS //
    
    void step(double timeStep) override;
};
