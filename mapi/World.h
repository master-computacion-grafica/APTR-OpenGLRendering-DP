#pragma once

#include "mapi/common.h"
#include "Object.h"
#include "Camera.h"


class World
{
private:

	// ATTRIBUTES //

	std::list<Object*> objects;
	std::list<Camera*> cameras;

	int activeCamera;


public:

	// CONSTRUCTOR //

	World();


	// GETTERS && SETTERS //

	std::list<Object*>& getObjects();
	std::list<Camera*>& getCameras();
	int getActiveCamera();

	void setObjects(std::list<Object*> objects);
	void setCameras(std::list<Camera*> cameras);
	void setActiveCamera(int activeCamera);


	// METHODS && FUNCTIONS //

	void addObject(Object* obj);

	void removeObject(Object* obj);

	size_t getNumObjects();

	Object* getObject(size_t index);

	void update(float deltaTime);

	void addCamera(Camera* cam);

	void removeCamera(Camera* cam);

	size_t getNumCameras();

	Camera* getCamera(size_t index);

};

