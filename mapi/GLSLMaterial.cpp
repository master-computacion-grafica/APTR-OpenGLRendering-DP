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

	for (Program* shader : program->getShaders()) 
	{
		shader->compile();

		if (!shader->isCompiled())
		{
			std::cerr << "ERROR: Shader couldn't compile!" << std::endl;
			return;
		}
	}

	program->linkProgram();
	if (program->checkLinkerErrors()) 
	{
		std::cerr << "ERROR: Couldn't link program!" << std::endl;
		return;
	}
}


void GLSLMaterial::prepare()
{
	program->readVarList();
}
