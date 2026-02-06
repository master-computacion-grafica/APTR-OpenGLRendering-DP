#pragma once
#include "Camera.h"

class CameraKeyboard : public Camera
{
public:
    
    // CONSTRUCTOR //
    
    CameraKeyboard(projectionType_e type, glm::vec3 position, glm::vec3 lookAt, glm::vec3 up) : Camera(type, position, lookAt, up){}
    
    // OVERRIDES //
    
    void step(double deltaTime) override;
    
    ~CameraKeyboard() override;
};
