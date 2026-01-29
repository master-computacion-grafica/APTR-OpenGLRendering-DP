#include "GLSLMaterial.h"


GLSLMaterial::GLSLMaterial()
{
	this->program = new GLSLProgram();
}


void GLSLMaterial::loadProgram(std::list<std::string> programNames)
{
	for (std::string name : programNames)
	{
		program->addProgram(name);
	}
}


void GLSLMaterial::prepare()
{

}
