#pragma once

#include "mapi/common.h"
#include "Object.h"

class Object3D : public Object
{
public:

	// METHODS && FUCNCTIONS //

	void loadDataFromFile(std::string file) override;

	virtual void step(double deltaTime) = 0;


	// DESTRUCTOR //

	~Object3D() override = default;
};