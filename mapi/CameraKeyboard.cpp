#include "CameraKeyboard.h"
#include "System.h"

CameraKeyboard::CameraKeyboard(projectionType_e type, glm::vec3 position, glm::vec3 lookAt, glm::vec3 up, float speed) : Camera(type, position, lookAt, up)
{
    this->speed = speed;
}

void CameraKeyboard::step(double deltaTime)
{
    InputManager* inputManager = System::getInputManager();

    if (inputManager->mouseState.buttonState[GLFW_MOUSE_BUTTON_RIGHT])
    {
        direction = glm::vec4(0, 0, 0, 0);

        if (inputManager->isPressed(GLFW_KEY_W))
        {
            direction.z += 1;
        }
        if (inputManager->isPressed(GLFW_KEY_S))
        {
            direction.z -= 1;
        }
        if (inputManager->isPressed(GLFW_KEY_A))
        {
            direction.x -= 1;
        }
        if (inputManager->isPressed(GLFW_KEY_D))
        {
            direction.x += 1;
        }
        if (inputManager->isPressed(GLFW_KEY_Q))
        {
            direction.y -= 1;
        }
        if (inputManager->isPressed(GLFW_KEY_E))
        {
            direction.y += 1;
        }

        direction = glm::normalize(direction);
        direction = direction * (speed * static_cast<float>(deltaTime));

        position += direction;
        lookAt += glm::vec3(direction);
    }
}
