#pragma once

#include "mapi/common.h"
#include "Object.h"


class World
{
private:

	// ATTRIBUTES //

	std::list<Object*> objects;


public:

	// CONSTRUCTOR //

	World();


	// GETTERS && SETTERS //

	std::list<Object*>& getObjects();

	void setObjects(std::list<Object*> objects);


	// METHODS && FUNCTIONS //

	void addObject(Object* obj);

	void removeObject(Object* obj);

	size_t getNumObjects();

	Object* getObject(size_t index);

	void update(float deltaTime);

};

