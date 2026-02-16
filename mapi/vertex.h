#pragma once
#include "mapi/common.h"


typedef struct {
    glm::vec4 vPosition; // Posicion vertice XYZW
    glm::vec4 vColor; // Color RGBA
    glm::vec2 vTexCoords; // Coordenadas de textura por vertice
    glm::vec4 vNormal; // Normal del vertice
}vertex_t;
