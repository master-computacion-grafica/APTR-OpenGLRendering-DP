#pragma once

#include <list>
#include "mapi/common.h"
#include "Object.h"


class World
{
private:

	// ATTRIBUTES //

	std::vector<Object*> objects;


public:

	// CONSTRUCTOR //

	World();


	// GETTERS && SETTERS //

	std::vector<Object*>& getObjects();

	void setObjects(std::vector<Object*> objects);


	// METHODS && FUNCTIONS //

	void addObject(Object* obj);

	void removeObject(Object* obj);

	size_t getNumObjects();

	Object* getObject(size_t index);

	void update(float deltaTime);

};

