#pragma once

#include "mapi/common.h"
#include "Program.h"


class GLSLShader: public Program
{
public:

	// CONSTRUCTOR //

	GLSLShader(std::string fileName);


	// METHODS && FUNCTIONS //

	void compile() override;

	void checkErrors() override;

	char* readFile(GLint& fileSize) override;
};

