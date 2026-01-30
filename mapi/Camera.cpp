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