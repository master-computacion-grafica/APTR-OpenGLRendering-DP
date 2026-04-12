#include "OrbitalLight.h"
#include "System.h"

void OrbitalLight::step(double deltaTime)
{
    InputManager* inputManager = System::getInputManager();
    if (inputManager->wasPressedThisFrame(GLFW_KEY_L))
    {
        isEnabled = !isEnabled;
    }
    
    angle += angularVelocity * deltaTime;
    if (angle > 360)
        angle -= 360;
    
    float x = center.x + radius * sin(angle);
    float z = center.z + radius * cos(angle);
    
    position.x = x;
    position.z = z;
}
