#include "Mesh3D.h"

Mesh3D::Mesh3D()
{
    meshID = meshCounter++;
    
    colorRGBA = {1,1,1,1};
    
    vVertList;
}

int Mesh3D::getMeshID()
{
    return meshID;
}

std::vector<vertex_t> Mesh3D::getVertexList()
{
    return vVertList;
}

void Mesh3D::addVertex(vertex_t vertex)
{
    vVertList.push_back(vertex);
}
