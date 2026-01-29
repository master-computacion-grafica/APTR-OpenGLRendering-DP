#include "GLSLShader.h"

GLSLShader::GLSLShader(std::string fileName) : Program(fileName)
{
    this->fileName = fileName;

    if (fileName.ends_with(".frag"))
    {
        this->type = programTypes_e::fragment;
    }
    else if (fileName.ends_with(".vert"))
    {
        this->type = programTypes_e::vertex;
    }

    GLenum programType;
    if (type == programTypes_e::vertex)
        programType = GL_VERTEX_SHADER;
    else if (type == programTypes_e::fragment)
        programType = GL_FRAGMENT_SHADER;
    this->idProgram = glCreateShader(programType);
}


void GLSLShader::compile()
{
    GLint fileSize;
    auto code = readFile(fileSize);

    glShaderSource(idProgram, 1, &code, &fileSize);
    glCompileShader(idProgram);

    checkErrors();
}


void GLSLShader::checkErrors()
{
    GLint fragment_compiled;
    glGetShaderiv(idProgram, GL_COMPILE_STATUS, &fragment_compiled);
    if (fragment_compiled != GL_TRUE)
    {
        GLsizei log_length = 0;
        GLchar message[1024];
        glGetShaderInfoLog(idProgram, 1024, &log_length, message);
        std::cout << "ERROR " << fileName << "\n" << message << "\n\n";
        compiled = false;
        return;
    }
    compiled = true;
}


char* GLSLShader::readFile(GLint& fileSize)
{
    std::ifstream f(fileName);
    if (f.is_open()) {
        char* code = std::string(std::istreambuf_iterator<char>(f), {}).data();
        fileSize = std::strlen(code);
        f.close();
        return code;
    }

    std::cout << "ERROR: FICHERO NO ENCONTRADO " << __FILE__ << ":" << __LINE__ << " " << fileName << "\n";
    return nullptr;

}