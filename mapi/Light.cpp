#include "Light.h"

LightType Light::getLightType() const
{
    return type;
}

void Light::setLightType(LightType type)
{
    this->type = type;
}

glm::vec4 Light::getDirection() const
{
    return direction;
}

void Light::setDirection(glm::vec4 direction)
{
    this->direction = direction;
}

glm::vec4 Light::getColor() const
{
    return color;
}

void Light::setColor(glm::vec4 color)
{
    this->color = color;
}

float Light::getLinearAttenuation() const
{
    return linearAttenuation;
}

void Light::setLinearAttenuation(float linearAttenuation)
{
    this->linearAttenuation = linearAttenuation;
}

bool Light::getIsEnabled()
{
    return isEnabled;
}

void Light::setIsEnabled(bool isEnabled)
{
    this->isEnabled = isEnabled;
}
