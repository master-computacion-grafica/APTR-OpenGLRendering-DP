#pragma once

#include "mapi/common.h"
#include "Program.h"


class GLSLShader: Program
{
public:

	// CONSTRUCTOR //

	GLSLShader(std::string fileName);


	// METHODS && FUNCTIONS //

	void readFile() override;

	void compile() override;

	void checkErrors() override;

	void readFile() override;
};

