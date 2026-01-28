#include "GL4Render.h"

GL4Render::GL4Render(int width, int height)
{
    this->width = width;
    this->height = height;
}

void GL4Render::init()
{
    window = glfwCreateWindow(width, height, "Practica APIS3D",nullptr, nullptr);
    glfwMakeContextCurrent(window);
    
    gladLoadGL(glfwGetProcAddress);
		
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    glEnable(GL_DEPTH_TEST);
}

void GL4Render::setupObject(Object* obj)
{
}

void GL4Render::removeObject(Object* obj)
{
}

void GL4Render::drawObjects(std::vector<Object*>* objs)
{
}
