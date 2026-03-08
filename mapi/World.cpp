#include "World.h"
#include "System.h"

World::World()
{
}

std::list<Object*>& World::getObjects()
{
    return this->objects;
}

std::list<Camera*>& World::getCameras()
{
    return this->cameras;
}

int World::getActiveCamera()
{
    return this->activeCamera;
}

std::list<Light*>& World::getLights()
{
    return this->lights;
}

float World::getAmbient()
{
    return this->ambient;
}

void World::setObjects(std::list<Object*> objects)
{
    this->objects = objects;
}

void World::setCameras(std::list<Camera*> cameras)
{
    this->cameras = cameras;
}

void World::setActiveCamera(int activeCamera)
{
    if (activeCamera < 0)
    {
    this->activeCamera = 0;
    }
    else if (activeCamera >= this->cameras.size())
    {
        this->activeCamera = this->cameras.size() - 1;
    }
    else
    {
        this->activeCamera = activeCamera;
    }
}

void World::setLigths(std::list<Light*> lights)
{
    this->lights = lights;
}

void World::setAmbient(float ambient)
{
    this->ambient = ambient;
}

void World::addObject(Object* obj)
{
    objects.push_back(obj);
}

void World::removeObject(Object* obj)
{
    objects.remove(obj);
}

size_t World::getNumObjects()
{
    return objects.size();
}

Object* World::getObject(size_t index)
{
    auto iterator = objects.begin();
    std::advance(iterator, index);

    return *iterator;
}

void World::update(double deltaTime)
{
    for (Object* obj : objects)
    {
        obj->step(deltaTime);
        obj->computeModelMatrix();
    }

    for (Light* light : lights)
    {
        light->step(deltaTime);
    }
    
    if (System::getInputManager()->wasPressedThisFrame(GLFW_KEY_C))
    {
        int index = getActiveCamera();
        if (++index >= this->cameras.size())
            index = 0;
        this->setActiveCamera(index);
    }
        
    getCamera(activeCamera)->step(deltaTime);
    getCamera(activeCamera)->computeViewMatrix();
    getCamera(activeCamera)->computeModelMatrix();
}

void World::addCamera(Camera* cam)
{
    cameras.push_back(cam);
}

void World::removeCamera(Camera* cam)
{
    cameras.remove(cam);
}

size_t World::getNumCameras()
{
    return cameras.size();
}

Camera* World::getCamera(size_t index)
{
    auto iterator = cameras.begin();
    std::advance(iterator, index);

    return *iterator;
}

int World::getCameraIndex(Camera* cam)
{
    int index = 0;

    while (index < cameras.size() && getCamera(index) != cam)
    {
        index++;
    }

    if (index >= cameras.size() || cameras.empty())
        return -1;
    
    return index;
}

Light* World::getLight(int pos)
{
    auto iterator = lights.begin();
    std::advance(iterator, pos);

    return *iterator;
}

void World::addLight(Light* light)
{
    lights.push_back(light);
}

void World::deleteLight(int lightPos)
{
    auto iterator = lights.begin();
    std::advance(iterator, lightPos);
    lights.erase(iterator);
}
