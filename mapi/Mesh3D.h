#pragma once
#include "Material.h"
#include "vertex.h"

class Mesh3D
{
private:
    
    // ATRIBUTES //
    
    static inline int meshCounter = 0;
    
    int meshID;
    
    Material* mat;
    
    std::vector<glm::uint32>* vTriangleIdxList;
    
public:
    
    glm::vec4 colorRGBA;
    
    std::vector<vertex_t> vVertList;
    
    // CONSTRUCTOR //
    
    Mesh3D();
    
    // GETTERS SETTERS //
    
    int getMeshID();
    
    // Este set sobra, puesto que se establece la ID en el constructor y depende
    // del meshCount.
    // void setMeshID(int id);
    
    std::vector<vertex_t>& getVertexList();
    
    void setVertexList(std::vector<vertex_t> vertexList);
    
    Material* getMaterial();
    
    void setMaterial(Material* material);
    
    std::vector<glm::uint32>* getTriangleIndexList();
    
    void setTriangleIndexList(std::vector<glm::uint32>* triangleIdxList);
    
    
    
    // METHODS //
    
    void addVertex(vertex_t vertex);
    
    void addTriangle(glm::uint32 vID1, glm::uint32 vID2, glm::uint32 vID3);
};
