#pragma once
#include "common.h"

typedef struct  {
    double xPos;
    double yPos;
    std::map<int, bool> buttonState;
}mouseState_t;

class InputManager
{
public:

    // ATRIBUTES //
    
    static inline std::map<int, bool> keyState;
    static inline mouseState_t mouseState;
    
    // METHODS //
    
    virtual void init() = 0;
    
    virtual bool isPressed(int key) = 0;
    
    virtual bool isMousePressed(int mouseButton) = 0;
    
    virtual void setInputManagerCursorPos(double x, double y) = 0;
    
    virtual double getCursorPosX() = 0;
    
    virtual double getCursorPosY() = 0;
    
    virtual void updateEvents() = 0;
    
    // DESTRUCTOR //
    virtual ~InputManager() = default;
};
