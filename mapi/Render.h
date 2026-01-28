#pragma once
#include "Object.h"

class Render
{
protected:
    // ATRIBUTES //
    
    int width, height;
    
public:

    // METHODS //
    
    virtual void init() = 0;
    
    virtual void setupObject(Object* obj) = 0;
    
    virtual void removeObject(Object* obj) = 0;
    
    virtual void drawObjects(std::vector<Object*>* objs) = 0;
    
    virtual bool isClosed() = 0;
    
    // GETTERS && SETTERS
    
    virtual void setWidth(int w) { width = w; }
    virtual void setHeight(int h) { height = h; }
    virtual int getWidth() { return width; }
    virtual int getHeight() { return height; }
    
    // DESTRUCTOR //
    virtual ~Render() = default;
};
