#pragma once

#include "RenderProgram.h"


class Material
{
protected:

	// ATTRIBUTES //

	RenderProgram* program;


public:


	// GETTERS && SETTERS //

	RenderProgram* getProgram() { return this->program; }

	void setProgram(RenderProgram* program) { this->program = program; }


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
