#pragma once

#include "mapi/common.h"
#include "Object.h"
#include "Camera.h"
#include "Light.h"


class World
{
private:

	// ATTRIBUTES //

	std::list<Object*> objects;
	std::list<Camera*> cameras;
	std::list<Light*> lights;

	int activeCamera;
	float ambient;


public:

	// CONSTRUCTOR //

	World();


	// GETTERS && SETTERS //

	std::list<Object*>& getObjects();
	std::list<Camera*>& getCameras();
	std::list<Light*>& getLights();
	int getActiveCamera();
	Camera* getCamera(size_t index);
	Light* getLight(size_t index);
	int getCameraIndex(Camera* cam);

	void setObjects(std::list<Object*> objects);
	void setCameras(std::list<Camera*> cameras);
	void setActiveCamera(int activeCamera);
	float getAmbient() const;
	void setAmbient(float ambient);


	// METHODS && FUNCTIONS //

	void addObject(Object* obj);

	void removeObject(Object* obj);

	size_t getNumObjects();

	Object* getObject(size_t index);

	void update(double deltaTime);

	void addCamera(Camera* cam);
	
	void addLight(Light* light);

	void removeCamera(Camera* cam);
	
	void removeLight(Light* light);

	size_t getNumCameras();

};

