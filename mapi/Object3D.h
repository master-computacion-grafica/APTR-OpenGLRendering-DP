#pragma once

#include "mapi/common.h"
#include "Object.h"

class Object3D : public Object
{
	bool computeNormals;
public:

	// CONSTRUCTOR //

	Object3D(glm::vec4 position = {0.0f, 0.0f, 0.0f, 1.0f}, glm::vec4 rotation = {0.0f, 0.0f, 0.0f, 0.0f}, glm::vec4 scale = {1.0f, 1.0f, 1.0f, 1.0f});
	

	// METHODS && FUCNCTIONS //

	void loadDataFromFile(std::string file) override;
	void loadObj(std::string objFile, Material* material);
	void recomputeNormals();

	virtual void step(double deltaTime);


	// DESTRUCTOR //

	~Object3D() override = default;
};