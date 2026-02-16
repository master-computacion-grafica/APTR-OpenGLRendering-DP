#pragma once

#include "RenderProgram.h"


class Material
{
protected:

	// ATTRIBUTES //

	RenderProgram* program;
	
	Texture* texture;
	glm::vec4 color;

	float shininess;
	bool lightEnable;


public:


	// GETTERS && SETTERS //

	RenderProgram* getProgram() { return this->program; }
	void setProgram(RenderProgram* program) { this->program = program; }

	Texture* getTexture() {	return texture;	}
	void setTexture(Texture* texture) {	this->texture = texture; }

	glm::vec4 getColor() { return color; }
	void setColor(glm::vec4 color) { this->color = color; }

	float getShininess() { return this->shininess; }
	void setShininess(float shininess) { this->shininess = shininess; }

	bool getLightEnable() { return this->lightEnable; }
	void setLightEnable(bool lightEnable) { this->lightEnable = lightEnable; } 
	

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
