#include "GL4Render.h"
#include "common.h"
#include "System.h"

GL4Render::GL4Render(int width, int height)
{
    this->width = width;
    this->height = height;
}

void GL4Render::init()
{
    if (glfwInit() != GLFW_TRUE)
    {	
        std::cout << "ERROR iniciando glfw\n";
    }
    else
    {
        window = glfwCreateWindow(width, height, "Practica APIS3D",nullptr, nullptr);
        glfwMakeContextCurrent(window);
    
        gladLoadGL(glfwGetProcAddress);
		
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
        glEnable(GL_DEPTH_TEST);
    }
}

void GL4Render::setupObject(Object* obj)
{
    for (int i = 0; i < obj->getMeshes().size(); i++)
    {
        bo_t bo = { 0,0,0 };

        //crear buffers objects
        glGenVertexArrays(1, &bo.arrayBufferId);
        glGenBuffers(1, &bo.vertexArrayId);
        glGenBuffers(1, &bo.vertexIdxArrayId);
        //copiar datos a GPU
        glBindVertexArray(bo.arrayBufferId); //activar lista de arrays
        glBindBuffer(GL_ARRAY_BUFFER, bo.vertexArrayId);//activar lista de vertices
    
        int numElements = obj->getMesh(i)->vVertList.size();
        glBufferData(GL_ARRAY_BUFFER, numElements *sizeof(vertex_t), obj->getMesh(i)->vVertList.data(), GL_STATIC_DRAW); //copiar vertices

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bo.vertexIdxArrayId);//activar lista de indices de vertices
        numElements = obj->getMesh(i)->getTriangleIndexList()->size();
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, numElements * sizeof(unsigned int), obj->getMesh(i)->getTriangleIndexList()->data(), GL_STATIC_DRAW); //copiar indices de vertices
        //guardar ids de buffers
        bufferObjectList[obj->getMesh(i)->getMeshID()] = bo;
    }
    
}

void GL4Render::removeObject(Object* obj)
{
    for (int i = 0; i < obj->getMeshes().size(); i++)
        bufferObjectList.erase(obj->getMesh(i)->getMeshID());
}

void GL4Render::drawObjects(std::vector<Object*>* objs)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    for (auto& obj : *objs)
    {
        for (int i = 0; i < obj->getMeshes().size(); i++)
        {
            //calcular matriz modelo
            System::setModelMatrix(obj->getModelMatrix());
            auto mat = obj->getMesh(i)->getMaterial();
            auto renderProgram = mat->getProgram();
		
            renderProgram->use();
		
            //mat->renderProgram->setMVP(cam.cameraProjection* cam.cameraView * model);

            //activar buffers de datos
            auto bo = bufferObjectList[obj->getMesh(i)->getMeshID()]; //recuperar ids de buffers de este objeto
            glBindVertexArray(bo.arrayBufferId); //activar lista de arrays
            glBindBuffer(GL_ARRAY_BUFFER, bo.vertexArrayId);//activar lista de v�rtices
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bo.vertexIdxArrayId);//activar lista de indices de v�rtices
            //describir buffers
            mat->prepare();
            

            //ordenar a dibujar
            glDrawElements(GL_TRIANGLES, obj->getMesh(i)->getTriangleIndexList()->size(), GL_UNSIGNED_INT, nullptr);
        }
        
    }
    glfwSwapBuffers(window);
}

bool GL4Render::isClosed()
{
    return glfwWindowShouldClose(window);
}

void GL4Render::setWidth(int w)
{
    Render::setWidth(w);
}

void GL4Render::setHeight(int h)
{
    Render::setHeight(h);
}

int GL4Render::getWidth()
{
    return Render::getWidth();
}

int GL4Render::getHeight()
{
    return Render::getHeight();
}

GL4Render::~GL4Render()
{
}
