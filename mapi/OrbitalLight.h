#pragma once
#include <glm/vec4.hpp>

#include "Light.h"

class OrbitalLight : public Light
{
    glm::vec4 center;
    float radius;
    float angularVelocity;
    double angle;
public:
    OrbitalLight(const glm::vec4& position, const glm::vec4& rotation, const glm::vec4& scale, LightType type,
        const glm::vec4& color, const glm::vec4& direction, float linearAttenuation, bool isEnabled,
        const glm::vec4& center, float radius, float angularVelocity)
        : Light(position, rotation, scale, type, color, direction, linearAttenuation, isEnabled)
    {
        this->center = center;
        this->radius = radius;
        this->angularVelocity = angularVelocity;
        angle = 0;
    }

    void step(double deltaTime) override;
};
