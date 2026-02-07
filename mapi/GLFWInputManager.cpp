#include "GLFWInputManager.h"

#include <GLFW/glfw3.h>

#include "GL4Render.h"
#include "System.h"

void GLFWInputManager::init()
{
    window = ((GL4Render*)System::getRender())->window;
    glfwSetKeyCallback(window, windowKeyboardEvent);//init de funcion de teclado
    glfwSetMouseButtonCallback(window, mouseButtonEvent);//init de funcion boton raton
    glfwSetCursorPosCallback(window, mousePosEvent);//init posicion de raton
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    setInputManagerCursorPos(0, 0);
}

void GLFWInputManager::windowKeyboardEvent(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    switch (action) {
    case GLFW_PRESS:
        {
            keyState[key] = true;
        }break;
    case GLFW_RELEASE:
        {
            keyState[key] = false;
        }break;
    }
}

void GLFWInputManager::mousePosEvent(GLFWwindow* window, double xpos, double ypos)
{
    mouseState.xPos = xpos;
    mouseState.yPos = ypos;
}

void GLFWInputManager::mouseButtonEvent(GLFWwindow* window, int button, int action, int mods)
{
    switch (action) 
    {
        case GLFW_PRESS:
        {
            mouseState.buttonState[button] = true;
        }break;
        case GLFW_RELEASE:
        {
            mouseState.buttonState[button] = false;
        }break;
    }
}

void GLFWInputManager::updateEvents()
{
    glfwPollEvents();
}

void GLFWInputManager::setInputManagerCursorPos(double x, double y)
{
    mouseState.xPos = x; mouseState.yPos = y;
    glfwSetCursorPos(window, x, y);
}

bool GLFWInputManager::isMousePressed(int mouseButton)
{
    return mouseState.buttonState[mouseButton];
}

double GLFWInputManager::getCursorPosX()
{
    return mouseState.xPos;
}

double GLFWInputManager::getCursorPosY()
{
    return mouseState.yPos;
}

bool GLFWInputManager::isPressed(int key)
{
    return keyState[key];
}
