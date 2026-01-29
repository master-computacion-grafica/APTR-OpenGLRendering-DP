#pragma once
#include "RenderProgram.h"

class GLSLProgram : public RenderProgram
{
public:
    GLSLProgram() { renderProgramId = -1; }
    ~GLSLProgram() override;
    void addProgram(std::string fileName) override;
    void linkProgram() override;
    void use() override;
    bool checkLinkerErrors() override;
    void setVertexAttrib(std::string name, GLsizei stride, void* offset, GLint count, GLenum type) override;
    void setInt(std::string name, int val) override;
    void setFloat(std::string name, float val) override;
    void setVec3(std::string name, const glm::vec3& vec) override;
    void setVec4(std::string name, const glm::vec4& vec) override;
    void setMatrix(std::string name, const glm::mat4& matrix) override;
    
    void readVarList();
    unsigned int getVarLocation(std::string varName);
};
