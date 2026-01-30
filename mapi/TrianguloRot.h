#pragma once

#include "mapi/common.h"
#include "Object3D.h"
#include "System.h"

class TrianguloRot : Object3D
{
public:

	// CONSTRUCTOR //

	TrianguloRot();


	// METHODS && FUNCTIONS //

	

	// Heredado vía Object3D
	void step(double deltaTime) override;

};

