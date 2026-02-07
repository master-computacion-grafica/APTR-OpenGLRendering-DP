#pragma once
#include "InputManager.h"

class GLFWInputManager : public InputManager
{
public:
    
    static inline GLFWwindow* window;//referencia a ventana de eventos
    
    void init() override;
    void initGLFWInputManager(GLFWwindow* window);
    
    static void windowKeyboardEvent(GLFWwindow* window, int key, int scancode, int action, int
        mods);
    static void mousePosEvent(GLFWwindow* window, double xpos, double ypos);
    static void mouseButtonEvent(GLFWwindow* window, int button, int action, int mods);
    void updateEvents() override;
    void setInputManagerCursorPos(double x, double y) override;
    bool isPressed(int key) override;
    bool isMousePressed(int mouseButton) override;
    double getCursorPosX() override;
    double getCursorPosY() override;
};
