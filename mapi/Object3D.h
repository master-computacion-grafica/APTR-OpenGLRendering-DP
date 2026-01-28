#pragma once

#include "mapi/common.h"
#include "Object.h"

class Object3D : Object
{
public:

	// METHODS && FUCNCTIONS //

	virtual void loadDataFromFile(std::string file) override = 0;

	virtual void step(double deltaTime) override = 0;
};