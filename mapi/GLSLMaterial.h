#pragma once

#include "Material.h"
#include "GLSLProgram.h"
#include "GLSLShader.h"


class GLSLMaterial: public Material
{
public:

	// CONSTRUCTOR //

	GLSLMaterial();


	// METHODS && FUNCTIONS //

	void loadProgram(std::list<std::string> programNames) override;

	void prepare() override;
};

