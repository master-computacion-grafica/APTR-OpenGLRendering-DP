#pragma once
#include "Render.h"

class GL4Render : public Render
{
public:
     // ATTRIBUTES //
     GLFWwindow* window;
     
     // CONSTRUCTOR //
     
     GL4Render(int width, int height);
     
     // METHODS //
     
     void init() override;
     
     void setupObject(Object* obj) override;
     
     void removeObject(Object* obj) override;
     
     void drawObjects(std::vector<Object*>* objs) override;
};
