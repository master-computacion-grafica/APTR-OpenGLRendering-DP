#pragma once

#include "Entity.h"


enum lightType
{
    DIRECTIONAL, POINT, SPOT 
};

class Light : public Entity
{
protected:

    // ATTRIBUTES //

    lightType type;

    glm::vec4 color;

    glm::vec4 direction;

    float linearAttenuation;

    bool enabled;


public:

    // CONSTRUCTOR //

    Light(glm::vec4 position, glm::vec4 rotation, glm::vec4 scale, lightType type, glm::vec4 color, glm::vec4 direction, float lienarAttenuation, bool enabled)
    {
        this->position = position;
        this->rotation = rotation;
        this->scale = scale;

        this->type = type;
        this->direction = direction;
        this->color = color;
        this->linearAttenuation = lienarAttenuation;
        this->enabled = enabled;
    }


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

    virtual void step(double timeStep) override;
};
