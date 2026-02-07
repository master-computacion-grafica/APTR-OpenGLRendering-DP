#pragma once

#include "Object3D.h"


class TrianguloRot : public Object3D
{
public:

	// CONSTRUCTOR //

	TrianguloRot();


	// METHODS && FUNCTIONS //

	

	// Heredado v�a Object3D
	void step(double deltaTime) override;

};

