#pragma once

#include "mapi/common.h"
#include "Object3D.h"
#include "System.h"

class TrianguloRot : public Object3D
{
public:

	// CONSTRUCTOR //

	TrianguloRot();


	// METHODS && FUNCTIONS //

	

	// Heredado v�a Object3D
	void step(double deltaTime) override;

};

