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

	std::vector<Mesh3D*> meshes;

	Tipo tipo;


public:
	
	// GETTERS && SETTERS //

	std::vector<Mesh3D*> getMeshes() { return this->meshes; }
	Tipo getTipo() { return this->tipo; }

	void setMeshes(std::vector<Mesh3D*> meshes) { this->meshes = meshes; }
	void setTipo(Tipo tipo) { this->tipo = tipo; }


	// METHODS && FUNCTIONS //

	virtual void loadDataFromFile(std::string file) = 0;

	void addMesh(Mesh3D* m)
	{
		meshes.push_back(m);
	}
	
	Mesh3D* getMesh(int pos)
	{
		return meshes[pos];
	}


	// DESTRUCTOR //

	virtual ~Object() override = default;
};

