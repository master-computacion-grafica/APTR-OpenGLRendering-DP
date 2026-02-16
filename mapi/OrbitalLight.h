#pragma once

#include "Light.h"


class OrbitalLight : public Light
{
private:

    // ATTRIBUTES //
    
    glm::vec4 center;

    float radius;

    float speed;


public:

    // CONSTRUCTOR //

    OrbitalLight(glm::vec4 position, glm::vec4 rotation, glm::vec4 scale, lightType type, glm::vec4 direction, glm::vec4 color, float linearAttenuation, bool enabled, glm::vec4 center, float radius, float speed);


    // GETTERS && SETTERS //

    glm::vec4 getCenter() { return center; }
    void setCenter( glm::vec4& center) { this->center = center; }

    float getRadius() { return radius; }
    void setRadius(float radius) { this->radius = radius; }

    float getSpeed() const { return speed; }
    void setSpeed(float speed) { this->speed = speed; }


    // METHODS && FUNCTIONS //

    virtual void step(double deltaTime) override;
};
