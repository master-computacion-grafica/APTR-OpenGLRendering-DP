#include "GLSLShader.h"

GLSLShader::GLSLShader(std::string fileName)
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

	idProgram = count++;
}


void GLSLShader::compile()
{

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
	}
}


void GLSLShader::readFile()
{
	std::ifstream f(fileName);
	if (f.is_open()) {
		std::string code = std::string(std::istreambuf_iterator<char>(f), {});
		f.close();
	}
	else {
		std::cout << "ERROR: FICHERO NO ENCONTRADO " <<
			__FILE__ << ":" << __LINE__ << " " << fileName << "\n";
	}
}