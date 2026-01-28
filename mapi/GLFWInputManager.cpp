#include "GLFWInputManager.h"

void GLFWInputManager::init()
{
    glfwSetKeyCallback(window, windowKeyboardEvent);//init de funcion de teclado
    glfwSetMouseButtonCallback(window, mouseButtonEvent);//init de funcion boton raton
    glfwSetCursorPosCallback(window, mousePosEvent);//init posicion de raton
    setKMCursorPos(0, 0);
}

void GLFWInputManager::initGLFWInputManager(GLFWwindow* window)
{
    this->window = window;
    init();
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

bool GLFWInputManager::isPressed(char key)
{
    return keyState[key];
}
