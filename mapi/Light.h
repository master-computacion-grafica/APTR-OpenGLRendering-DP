#pragma once

#include "Entity.h"


enum lightType
{
    DIRECTIONAL, POINT, SPOT 
};

class Light : public Entity
{
private:

    // ATTRIBUTES //

    lightType type;

    glm::vec4 color;

    glm::vec4 direction;

    float linearAttenuation;

    bool enabled;


public:

    // CONSTRUCTOR //

    Light();


    // GETTERS && SETTERS //

    lightType getType() const { return this->type; }
    void setType(lightType type) { this->type = type; }
    
    const glm::vec4& getColor() const { return this->color; }
    void setColor(const glm::vec4& color) { this->color = color; }

    const glm::vec4 getDirection() { return this->direction; }
    void setDirection(const glm::vec4 direction) { this->direction = direction; }

    float getLinearAttenuation() const { return this->linearAttenuation; }
    void setLinearAttenuation(float linearAttenuation) { this->linearAttenuation = linearAttenuation; }

    bool getEnabled() { return this->enabled; }
    void setEnabled() { this->enabled = enabled; }


    // METHODS && FUNCTIONS //

    virtual void step(double timeStep) override {}
};
