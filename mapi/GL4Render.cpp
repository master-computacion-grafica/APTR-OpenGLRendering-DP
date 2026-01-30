#include "GL4Render.h"
#include "common.h"

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
    bo_t bo = { 0,0,0 };

    //crear buffers objects
    glGenVertexArrays(1, &bo.arrayBufferId);
    glGenBuffers(1, &bo.vertexArrayId);
    glGenBuffers(1, &bo.vertexIdxArrayId);
    //copiar datos a GPU
    glBindVertexArray(bo.arrayBufferId); //activar lista de arrays
    glBindBuffer(GL_ARRAY_BUFFER, bo.vertexArrayId);//activar lista de v�rtices
    int numElements = obj->getMesh()->vVertList.size();
    glBufferData(GL_ARRAY_BUFFER, numElements *sizeof(vertex_t), obj->getMesh()->vVertList.data(), GL_STATIC_DRAW); //copiar vertices

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bo.vertexIdxArrayId);//activar lista de indices de v�rtices
    numElements = obj->getMesh()->getTriangleIndexList()->size();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, numElements * sizeof(unsigned int), obj->getMesh()->getTriangleIndexList()->data(), GL_STATIC_DRAW); //copiar indices de vertices
    //guardar ids de buffers
    bufferObjectList[obj->getMesh()->getMeshID()] = bo;
}

void GL4Render::removeObject(Object* obj)
{
    bufferObjectList.erase(obj->getMesh()->getMeshID());
}

void GL4Render::drawObjects(std::vector<Object*>* objs)
{
    for (auto& obj : *objs)
    {
        //calcular matriz modelo
        auto model = obj->getModelMatrix();
        auto mat = obj->getMesh()->getMaterial();
        auto renderProgram = mat->getProgram();
		
        renderProgram->use();
		
        //mat->renderProgram->setMVP(cam.cameraProjection* cam.cameraView * model);

        //activar buffers de datos
        auto bo = bufferObjectList[obj->getMesh()->getMeshID()]; //recuperar ids de buffers de este objeto
        glBindVertexArray(bo.arrayBufferId); //activar lista de arrays
        glBindBuffer(GL_ARRAY_BUFFER, bo.vertexArrayId);//activar lista de v�rtices
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bo.vertexIdxArrayId);//activar lista de indices de v�rtices
        //describir buffers
        renderProgram->setVertexAttrib("vPos", sizeof(vertex_t), (void*)offsetof(vertex_t, vPosition), 4, GL_FLOAT);
        renderProgram->setVertexAttrib("vColor", sizeof(vertex_t), (void*)offsetof(vertex_t, vColor), 4, GL_FLOAT);
        renderProgram->setVertexAttrib("vTexCoord", sizeof(vertex_t), (void*)offsetof(vertex_t, vTexCoord), 2, GL_FLOAT);
        ////si hay textura, activarla
        //if (mat->texture)
        //    renderProgram->setTextureData(0, mat->texture->GlTextID, GL_TEXTURE_2D);

        //ordenar a dibujar
        glDrawElements(GL_TRIANGLES, obj->getMesh()->getTriangleIndexList()->size(), GL_UNSIGNED_INT, nullptr);
    }
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
