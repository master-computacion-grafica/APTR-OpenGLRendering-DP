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
	float ambient;

	int activeCamera;


public:

	// CONSTRUCTOR //

	World();


	// GETTERS && SETTERS //

	std::list<Object*>& getObjects();
	std::list<Camera*>& getCameras();
	int getActiveCamera();
	std::list<Light*>& getLights();
	float getAmbient();

	void setObjects(std::list<Object*> objects);
	void setCameras(std::list<Camera*> cameras);
	void setActiveCamera(int activeCamera);
	void setLigths(std::list<Light*> lights);
	void setAmbient(float ambient);


	// METHODS && FUNCTIONS //

	void addObject(Object* obj);

	void removeObject(Object* obj);

	size_t getNumObjects();

	Object* getObject(size_t index);

	void update(double deltaTime);

	void addCamera(Camera* cam);

	void removeCamera(Camera* cam);

	size_t getNumCameras();

	Camera* getCamera(size_t index);

	int getCameraIndex(Camera* cam);

	Light* getLight(int pos);

	void addLight(Light* light);

	void deleteLight(int lightPos);

};

