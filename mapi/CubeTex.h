#pragma once
#include "Object3D.h"

class CubeTex : public Object3D
{
private:
    float angularVelocity = 60.0f;
public:
    // CONSTRUCTOR //
    CubeTex();
    
    void step(double deltaTime) override;
};
