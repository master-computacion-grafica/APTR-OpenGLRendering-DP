#pragma once
#include "Program.h"
#include "GLTexture.h"

class Material
{

public:

    //propiedades de dibujado
    Program* renderProgram=nullptr;
    GLTexture* texture = nullptr;

    Material();

};

