#include "GLSLProgram.h"

#include "GLSLShader.h"
#include "GLTexture.h"

GLSLProgram::~GLSLProgram()
= default;

void GLSLProgram::addProgram(std::string fileName)
{
    GLSLShader* shader = new GLSLShader(fileName);
    shaders.push_back(shader);
}

void GLSLProgram::linkProgram()
{
    renderProgramId = glCreateProgram();
    for(auto &shader : shaders)
    {
        shader->compile();
        if(!shader->isCompiled())
        {
            std::cerr << "ERROR: Shader not compiled" << '\n';
            return;
        }
        glAttachShader(renderProgramId, shader->getIdProgram());
    }
    glLinkProgram(renderProgramId);
}

void GLSLProgram::use()
{
    glUseProgram(renderProgramId);
}

bool GLSLProgram::checkLinkerErrors()
{
    GLint program_linked;
    glGetProgramiv(renderProgramId, GL_LINK_STATUS, &program_linked);
    if (program_linked != GL_TRUE)
    {
        GLsizei log_length = 0;
        GLchar message[1024];
        glGetProgramInfoLog(renderProgramId, 1024, &log_length, message);
        std::cout << "ERROR linking program \"" << message << "\"\n";
        return true;
    }
    return false;
}

void GLSLProgram::setVertexAttrib(std::string name, GLsizei stride, void* offset, GLint count, GLenum type)
{
    if (varList.find(name) != varList.end())
    {
        glEnableVertexAttribArray(varList[name]);
        
        glVertexAttribPointer(varList[name], count, type, false, stride, offset);
    }
}

void GLSLProgram::setInt(std::string name, int val)
{
    glUniform1i(varList[name], val);
}

void GLSLProgram::setFloat(std::string name, float val)
{
    glUniform1f(varList[name], val);
}

void GLSLProgram::setVec3(std::string name, const glm::vec3& vec)
{
    glUniform3f(varList[name], vec.x, vec.y, vec.z);
}

void GLSLProgram::setVec4(std::string name, const glm::vec4& vec)
{
    glUniform4f(varList[name], vec.x, vec.y, vec.z, vec.w);
}

void GLSLProgram::setMatrix(std::string name, const glm::mat4& matrix)
{
    glUniformMatrix4fv(varList[name], 1, GL_FALSE, glm::value_ptr(matrix));
}

void GLSLProgram::setColorTextEnable()
{
    glUniform1i(varList["material.useColorText"], 1);
}

void GLSLProgram::setColorTextDisable()
{
    glUniform1i(varList["material.useColorText"], 0);
}

void GLSLProgram::setComputeLightEnable()
{
    glUniform1i(varList["material.computeLight"], 1);
}

void GLSLProgram::setComputeLightDisable()
{
    glUniform1i(varList["material.computeLight"], 0);
}

void GLSLProgram::setLightEnable(int i)
{
    glUniform1i(varList["lights[" + std::to_string(i) + "].enable"], 1);
}

void GLSLProgram::setLightDisable(int i)
{
    glUniform1i(varList["lights[" + std::to_string(i) + "].enable"], 0);
}

void GLSLProgram::bindColorTextureSample(int binding, Texture* texture)
{
    glActiveTexture(GL_TEXTURE0 + binding);
    GLenum textureType;
    if (texture->isCubeMap())
        textureType = GL_TEXTURE_CUBE_MAP;
    else
        textureType = GL_TEXTURE_2D;
    glBindTexture(textureType, dynamic_cast<GLTexture*>(texture)->getGlTextureID());
    glUniform1i(varList["material.colorText"], binding);
    
}

void GLSLProgram::readVarList()
{
    int numAttributes = 0;
    int numUniforms = 0;
    glGetProgramiv(renderProgramId, GL_ACTIVE_ATTRIBUTES, &numAttributes);
    for (int i = 0; i < numAttributes; i++)
    {
        char varName[100];
        int bufSize = 100, length = 0, size = 0;
        GLenum type = -1;
        glGetActiveAttrib(renderProgramId, (GLuint)i, bufSize, &length, &size, &type, varName);
        varList[std::string(varName)] = glGetAttribLocation(renderProgramId, varName);
    }
    glGetProgramiv(renderProgramId, GL_ACTIVE_UNIFORMS, &numUniforms);
    for (int i = 0; i < numUniforms; i++)
    {
        char varName[100];
        int bufSize = 100, length = 0, size = 0;
        GLenum type = -1;
        glGetActiveUniform(renderProgramId, (GLuint)i, bufSize, &length, &size, &type, varName);
        varList[std::string(varName)] = glGetUniformLocation(renderProgramId, varName);
    }
}

unsigned int GLSLProgram::getVarLocation(std::string varName) 
{
    if (varList.find(varName) != varList.end())
        return varList[varName];
    std::cout << "ERROR: variable " << varName << " no encontrada en shader\n";
    return -1;
    
}




