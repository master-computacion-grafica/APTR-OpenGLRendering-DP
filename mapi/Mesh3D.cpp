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

void Mesh3D::setVertexList(std::vector<vertex_t> vertexList)
{
    vVertList = vertexList;
}

Material* Mesh3D::getMaterial()
{
    return mat;
}

void Mesh3D::setMaterial(Material* material)
{
    mat = material;
}

std::vector<glm::uint32>* Mesh3D::getTriangleIndexList()
{
    return vTriangleIdxList;
}

void Mesh3D::setTriangleIndexList(std::vector<glm::uint32>* triangleIdxList)
{
    vTriangleIdxList = triangleIdxList;
}

void Mesh3D::addTriangle(glm::uint32 vID1, glm::uint32 vID2, glm::uint32 vID3)
{
    vTriangleIdxList->push_back(vID1);
    vTriangleIdxList->push_back(vID2);
    vTriangleIdxList->push_back(vID3);
}

void Mesh3D::addVertex(vertex_t vertex)
{
    vVertList.push_back(vertex);
}
