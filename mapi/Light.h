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
    LightType type;
    glm::vec4 color, direction;
    float linearAttenuation;
    bool isEnabled;
public:
    
    Light(LightType type, glm::vec4 color, float linearAttenuation, bool isEnabled = true)
    {
        this->type = type;
        this->color = color;
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
    
    void step(double deltaTime) override {}
    
    ~Light() override = default;
};
