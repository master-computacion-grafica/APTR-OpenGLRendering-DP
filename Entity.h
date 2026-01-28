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

	glm::vec4 getPosition();
	glm::vec4 getRotation();
	glm::vec4 getScale();
	glm::mat4 getMVP();

	void setPosition(glm::vec4 position);
	void setRotation(glm::vec4 rotation);
	void setScale(glm::vec4 scale);
	void setMVP(glm::mat4 MVP);


	// METHODS && FUNCTIONS //

	void computeModelMatrix()
	{
		MVP = glm::translate(MVP, glm::vec3(position));

		MVP = glm::rotate(MVP, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
		MVP = glm::rotate(MVP, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
		MVP = glm::rotate(MVP, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));

		MVP = glm::scale(MVP, glm::vec3(scale));
	}

	virtual void step(double deltaTime);
};