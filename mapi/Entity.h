#pragma once

#include "mapi/common.h"

class Entity
{
private:

	// ATTRIBUTES //

	glm::vec4 position;
	glm::vec4 rotation;
	glm::vec4 scale;

	glm::mat4 modelMatrix;

public:

	// CONTRUCTOR //

	Entity();


	// GETTERS && SETTERS //

	glm::vec4 getPosition() { return this->position; }
	glm::vec4 getRotation() { return this->rotation; }
	glm::vec4 getScale() { return this->scale; }
	glm::mat4 getModelMatrix() { return this->modelMatrix; }

	void setPosition(glm::vec4 position) { this->position = position; }
	void setRotation(glm::vec4 rotation) { this->rotation = rotation; }
	void setScale(glm::vec4 scale) { this->scale = scale; }
	void setModelMatrix(glm::mat4 modelMatrix) { this->modelMatrix = modelMatrix; }


	// METHODS && FUNCTIONS //

	void computeModelMatrix()
	{
		modelMatrix = glm::translate(modelMatrix, glm::vec3(position));

		modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
		modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
		modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));

		modelMatrix = glm::scale(modelMatrix, glm::vec3(scale));
	}

	virtual void step(double deltaTime) = 0;
};