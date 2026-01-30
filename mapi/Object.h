#pragma once

#include "common.h"
#include "Mesh3D.h"
#include "Entity.h"

enum Tipo
{
	D3, D2
};

class Object : public Entity
{
private:

	// ATTRIBUTES //

	Mesh3D* mesh;

	Tipo tipo;


public:


	// GETTERS && SETTERS //

	Mesh3D* getMesh() { return this->mesh; }
	Tipo getTipo() { return this->tipo; }

	void setMesh(Mesh3D* mesh) { this->mesh = mesh; }
	void setTipo(Tipo tipo) { this->tipo = tipo; }


	// METHODS && FUNCTIONS //

	virtual void loadDataFromFile(std::string file) = 0;


	// DESTRUCTOR //

	virtual ~Object() override = default;
};

