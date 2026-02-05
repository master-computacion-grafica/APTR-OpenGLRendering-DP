#include "CameraKeyboard.h"
#include "System.h"

CameraKeyboard::CameraKeyboard(projectionType_e type, glm::vec3 position, glm::vec3 lookAt, glm::vec3 up, float speed) : Camera(type, position, lookAt, up)
{
    this->speed = speed;
}

void CameraKeyboard::step(float deltaTime)
{
    direction = glm::vec3(0, 0, 0);
    
    InputManager* inputManager = System::getInputManager();
    if (inputManager->isPressed('D'))
    {
        direction.x += 1.0f;
    }
    if (inputManager->isPressed('A'))
    {
        direction.x += -1.0f;
    }
    if (inputManager->isPressed('W'))
    {
        direction.z += 1.0f;
    }
    if (inputManager->isPressed('S'))
    {
        direction.z += -1.0f;
    }
    if (inputManager->isPressed('Q'))
    {
        direction.y += 1.0f;
    }
    if (inputManager->isPressed('E'))
    {
        direction.y += -1.0f;
    }

    direction = glm::normalize(direction);

    position += direction * speed * deltaTime;
}
