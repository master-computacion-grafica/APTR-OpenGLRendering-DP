#pragma once

#include "RenderProgram.h"


class Material
{
protected:

	// ATTRIBUTES //

	RenderProgram* program;


public:

	// CONSTRUCTOR //

	Material();


	// METHODS && FUNCTIONS //

	virtual void loadProgram(std::list<std::string> programNames) = 0;

	virtual void prepare() = 0;
};


//public:
//
//	//propiedades de dibujado
//	Program* renderProgram = nullptr;
//	GLTexture* texture = nullptr;
//
//	Material();
