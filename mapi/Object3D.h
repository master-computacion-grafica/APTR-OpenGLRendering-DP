#pragma once

#include "mapi/common.h"
#include "Object.h"

class Object3D : Object
{
public:

	// METHODS && FUCNCTIONS //

	void loadDataFromFile(std::string file) override;

	void step(double deltaTime) override;


	// DESTRUCTOR //

	~Object3D() override = default;
};