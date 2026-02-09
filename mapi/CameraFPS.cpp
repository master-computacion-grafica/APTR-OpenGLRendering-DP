#include "CameraFPS.h"
#include "System.h"

CameraFPS::CameraFPS(projectionType_e type, glm::vec3 position, glm::vec3 lookAt, glm::vec3 up, float speed) : Camera(type, position, lookAt, up)
{
    this->speed = speed;

    rotSpeed = 45;
    
    direction = glm::vec4(glm::normalize(lookAt - position), 0.0f);
    yaw = glm::degrees(std::atan2(direction.z, direction.x));
    pitch = glm::degrees(glm::asin(direction.y));
    
    mouseLastPosition = glm::vec2(0,0);
}

void CameraFPS::step(double deltaTime)
{
    InputManager* inputManager = System::getInputManager();
    
    float horizontalInput = 0;
    float verticalInput = 0;
    
    glm::vec2 currentMousePosition = glm::vec2(inputManager->getCursorPosX(), inputManager->getCursorPosY());
    glm::vec2 mouseDelta = currentMousePosition - mouseLastPosition;
    
    mouseLastPosition = currentMousePosition;

    if (inputManager->isPressed(GLFW_KEY_W))
    {
        verticalInput++;
    }
    if (inputManager->isPressed(GLFW_KEY_S))
    {
        verticalInput--;
    }
    if (inputManager->isPressed(GLFW_KEY_A))
    {
        horizontalInput++;
    }
    if (inputManager->isPressed(GLFW_KEY_D))
    {
        horizontalInput--;
    }
    
    yaw += mouseDelta.x * 0.1f;
    pitch -= mouseDelta.y * 0.1f;

    pitch = std::min(pitch, 89.0f);
    pitch = std::max(pitch, -89.0f);

    glm::vec3 newDirection;
    newDirection.x = glm::cos(glm::radians(yaw)) * glm::cos(glm::radians(pitch));
    newDirection.y = glm::sin(glm::radians(pitch));
    newDirection.z = glm::sin(glm::radians(yaw)) * glm::cos(glm::radians(pitch));
    
    if (newDirection != glm::vec3(0.0))
        direction = glm::vec4(glm::normalize(newDirection), 0.0f);
    
    glm::vec3 cameraRight = glm::normalize(glm::cross(up, glm::vec3(direction)));
    
    glm::vec3 movementDirection = verticalInput * glm::vec3(direction) + horizontalInput * cameraRight;
    
    movementDirection.y = 0.0f;

    if (movementDirection != glm::vec3(0.0))
    {
        this->position += glm::vec4(glm::normalize(movementDirection) * (speed * static_cast<float>(deltaTime)), 0);
    }
    setLookAt(glm::vec3(position + direction));
}