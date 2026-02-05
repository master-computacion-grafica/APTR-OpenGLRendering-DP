#pragma once

#include "common.h"
#include "Camera.h"

class CameraKeyboard : public Camera
{
private:

    // ATTRIBUTES //

    float speed;
    glm::vec3 direction;


public:

    // CONSTRUCTOR//

    CameraKeyboard(projectionType_e type, glm::vec3 position, glm::vec3 lookAt, glm::vec3 up, float speed);


    // GETTERS && SETTERS //

    float getSpeed() { return this->speed; }
    glm::vec3 getDirection() { return this->direction; }
    
    void setSpeed(float newSpeed) { this->speed = newSpeed; }
    
    
    // METHODS && FUNCTIONS //

    void step(float deltaTime) override;
};
