#pragma once
#include "Render.h"

typedef struct {

     //id de array de buffers
     unsigned int arrayBufferId;
     //id de vertex array buffer
     unsigned int vertexArrayId;
     //id de vertex index buffer
     unsigned int vertexIdxArrayId;
}bo_t; //datos de buffer objects

class GL4Render : public Render
{
public:
     // ATTRIBUTES //
     GLFWwindow* window;
     std::map<int, bo_t> bufferObjectList;
     
     // CONSTRUCTOR //
     
     GL4Render(int width, int height);
     
     // METHODS //
     
     void init() override;
     
     void setupObject(Object* obj) override;
     
     void removeObject(Object* obj) override;
     
     void drawObjects(std::vector<Object*>* objs) override;
     bool isClosed() override;
     void setWidth(int w) override;
     void setHeight(int h) override;
     int getWidth() override;
     int getHeight() override;
     ~GL4Render() override;
};
