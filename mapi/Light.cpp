#include "Light.h"
#include "System.h"

void Light::step(double timeStep)
{
    if (System::getInputManager()->wasPressedThisFrame(GLFW_KEY_P))
    {
        enabled = !enabled;
    }
}
