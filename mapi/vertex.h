#pragma once
#include "mapi/common.h"


typedef struct {
    glm::vec4 vPosition; //posicion vertice XYZW
    glm::vec4 vColor; //color RGBA
    glm::vec2 vTexCoords; //coordenadas de textura por vertice
    glm::vec4 vNorm;
}vertex_t;
