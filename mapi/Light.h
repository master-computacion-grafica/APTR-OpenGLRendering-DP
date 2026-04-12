#pragma once
#include "Entity.h"

enum LightType
{
    DIRECTIONAL,
    POINT,
    SPOT
};

class Light: public Entity
{
protected:
    LightType type;
    glm::vec4 color, direction;
    float linearAttenuation;
    bool isEnabled;
public:
    
    Light(glm::vec4 position, glm::vec4 rotation, glm::vec4 scale, LightType type, glm::vec4 color, glm::vec4 direction, float linearAttenuation, bool isEnabled = true)
    {
        this->position = position;
        this->rotation = rotation;
        this->scale = scale;
        this->type = type;
        this->color = color;
        this->direction = direction;
        this->linearAttenuation = linearAttenuation;
        this->isEnabled = isEnabled;
    }
    
    LightType getLightType() const;
    
    void setLightType(LightType type);
    
    glm::vec4 getDirection() const;
    
    void setDirection(glm::vec4 direction);
    
    glm::vec4 getColor() const;
    
    void setColor(glm::vec4 color);
    
    float getLinearAttenuation() const;
    
    void setLinearAttenuation(float linearAttenuation);
    
    bool getIsEnabled();
    
    void setIsEnabled(bool isEnabled);
    
    virtual void step(double deltaTime) override {}
    
    ~Light() override = default;
};
