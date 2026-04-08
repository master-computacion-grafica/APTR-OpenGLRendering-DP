#pragma once

#include "RenderProgram.h"


class Material
{
protected:

	// ATTRIBUTES //

	RenderProgram* program;
	
	Texture* texture;
	
	glm::vec4 color;
	
	int shininess;
	
	bool 
		light,
		shadow,
		refraction, 
		reflection;
	
	float refractIndex;


public:


	// GETTERS && SETTERS //

	RenderProgram* getProgram() { return this->program; }

	void setProgram(RenderProgram* program) { this->program = program; }

	Texture* getTexture() {	return texture;	}

	void setTexture(Texture* texture) {	this->texture = texture; }
	
	glm::vec4 getColor() { return color; }
	
	void setColor(glm::vec4 color) { this->color = color; }
	
	bool getLight() { return light; }
	
	void setLight(bool value) { this->light = value; }
	
	bool getShadow() { return shadow; }
	
	void setShadow(bool value) { this->shadow = value; }
	
	int getShininess() { return shininess; }
	
	void setShininess(int value) { this->shininess = value; }
	
	bool getReflection() { return reflection; }
	
	void setReflection(bool value) { this->reflection = value; }
	
	bool getRefraction() { return refraction; }
	
	void setRefraction(bool value) { this->refraction = value; }
	
	float getRefractIndex() { return refractIndex; }
	
	void setRefractIndex(float value) { this->refractIndex = value; }

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
