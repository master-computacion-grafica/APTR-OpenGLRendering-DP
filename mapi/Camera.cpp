#include "Camera.h"

Camera::Camera(projectionType_e type, glm::vec3 position, glm::vec3 lookAt, glm::vec3 up)
{
    this->type = type;
    this->position = glm::vec4(position, 1.0f);
    this->rotation = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
    this->scale = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
    this->lookAt = lookAt;
    this->up = up;

    this->fovY = glm::radians(45.0);
    this->aspectRatio = 4.0f / 3.0f;
    this->near = 0.01f;
    this->far = 1000.0f;

    computeProjectionMatrix();
}

void Camera::computeProjectionMatrix()
{
    projection = glm::perspective(fovY, aspectRatio, near, far);
}

void Camera::computeViewMatrix()
{
    view = glm::lookAt(glm::vec3(position), glm::vec3(lookAt), glm::vec3(up));
}


// #include "Camera.h"
// #include "GLFWKeyManager.h"
//
// Camera::Camera(glm::vec4 pos, glm::vec4 lookAt, double fovy, double aspectRatio ):
//     fovy(fovy), aspectRatio(aspectRatio), lookAt(lookAt),pos(pos)
// {
//     //calcular matriz proyecci�n
//     cameraProjection = glm::perspective(glm::radians(fovy),aspectRatio, 0.01, 1000.0);
//     //calcular matriz vista
//     cameraView = glm::lookAt(glm::vec3(pos), glm::vec3(lookAt), glm::vec3(0, 1, 0));
//
// }
//
// void Camera::step(float timeStep) {
//
//     //actualizar movimientos
//     float vel = 1.0f; //unidadesGl segundo
//     float velRot = 40.0f;
//     if (GLFWKeyManager::keyboardState[GLFW_KEY_D])
//     {
//         this->pos.x += vel * timeStep;
//         lookAt.x += vel * timeStep;
//     }
//     if (GLFWKeyManager::keyboardState[GLFW_KEY_A])
//     {
//         this->pos.x -= vel * timeStep;
//         lookAt.x -= vel * timeStep;
//     }
//     if (GLFWKeyManager::keyboardState[GLFW_KEY_W])
//     {
//         this->pos.z += vel * timeStep;
//         lookAt.z += vel * timeStep;
//     }
//     if (GLFWKeyManager::keyboardState[GLFW_KEY_S])
//     {
//         this->pos.z -= vel * timeStep;
//         lookAt.z -= vel * timeStep;
//
//     }
//     //calcular matriz vista
//
//     cameraView = glm::lookAt(glm::vec3(pos), glm::vec3(lookAt), glm::vec3(0, 1, 0));
//
// }
