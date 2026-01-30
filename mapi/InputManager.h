#pragma once
#include "common.h"

typedef struct  {
    double xPos;
    double yPos;
    std::map<int, bool> buttonState;
}mouseStats_t;

class InputManager
{
public:

    // ATRIBUTES //
    
    static inline std::map<int, bool> keyState;
    static inline mouseStats_t mouseState;
    
    // METHODS //
    
    virtual void init() = 0;
    
    virtual bool isPressed(char key) = 0;
    
    virtual void setInputManagerCursorPos(double x, double y) = 0;
    
    // DESTRUCTOR //
    virtual ~InputManager() = default;
};
