#pragma once
#include "common.h"
#include "vertex.h"

class Mesh3D
{
private:
    
    // ATRIBUTES //
    
    static inline int meshCounter = 0;
    
    int meshID;
    
public:
    
    glm::vec4 colorRGBA;
    
    std::vector<vertex_t> vVertList;
    
    // CONSTRUCTOR //
    
    Mesh3D();
    
    // GETTERS SETTERS //
    
    int getMeshID();
    
    std::vector<vertex_t> getVertexList();
    
    // METHODS //
    
    void addVertex(vertex_t vertex);
};
