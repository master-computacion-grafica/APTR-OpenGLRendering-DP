#include "World.h"

std::list<Object*>& World::getObjects()
{
    return this->objects;
}

void World::setObjects(std::list<Object*> objects)
{
    this->objects = objects;
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

void World::update(float deltaTime)
{
    for (Object* obj : objects)
    {
        obj->step(deltaTime);
    }
}
