#pragma once

#include "mapi/common.h"

class Entity
{
private:

	// ATTRIBUTES //

	glm::vec4 position;
	glm::vec4 rotation;
	glm::vec4 scale;

	glm::mat4 MVP;

public:

	// CONTRUCTOR //

	Entity();


	// GETTERS && SETTERS //

	glm::vec4 getPosition() { return this->position; }
	glm::vec4 getRotation() { return this->rotation; }
	glm::vec4 getScale() { return this->scale; }
	glm::mat4 getMVP() { return this->MVP; }

	void setPosition(glm::vec4 position) { this->position = position; }
	void setRotation(glm::vec4 rotation) { this->rotation = rotation; }
	void setScale(glm::vec4 scale) { this->scale = scale; }
	void setMVP(glm::mat4 MVP) { this->MVP = MVP; }


	// METHODS && FUNCTIONS //

	void computeModelMatrix()
	{
		MVP = glm::translate(MVP, glm::vec3(position));

		MVP = glm::rotate(MVP, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
		MVP = glm::rotate(MVP, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
		MVP = glm::rotate(MVP, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));

		MVP = glm::scale(MVP, glm::vec3(scale));
	}

	virtual void step(double deltaTime) = 0;


	// DESTRUCTOR //

	virtual ~Entity() = default;
};