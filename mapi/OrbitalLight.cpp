#include "OrbitalLight.h"
#include "System.h"

OrbitalLight::OrbitalLight(
    glm::vec4 position = glm::vec4({0.0f, 0.0f, 0.0f, 1.0f}),
    glm::vec4 rotation = glm::vec4({0.0f, 0.0f, 0.0f, 0.0f}),
    glm::vec4 scale = glm::vec4({1.0f, 1.0f, 1.0f, 1.0f}),
    lightType type = lightType::DIRECTIONAL,
    glm::vec4 direction = glm::vec4({0.0f, 0.0f, 0.0f, 1.0f}),
    glm::vec4 color = glm::vec4({1.0f, 1.0f, 1.0f, 1.0f}),
    float linearAttenuation = 0.5f,
    bool enabled = true,
    glm::vec4 center = glm::vec4({0.0f, 0.0f, 0.0f, 1.0f}),
    float radius = 1.0f,
    float speed = 0.5f)
    : Light(position, rotation, scale, type, direction, color, linearAttenuation, enabled)
{
    this->center = center;
    this->radius = radius;
    this->speed = speed;
}

void OrbitalLight::step(double deltaTime)
{
    if (System::getInputManager()->isPressed(GLFW_KEY_P))
    {
        enabled = !enabled;
    }

    // this->position -= direction;
    // this->rotation.y += speed * deltaTime;

    // TODO: Ver como hacer la rotacion entorno a un punto.
}
