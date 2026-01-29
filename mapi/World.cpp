#include "World.h"
#include "System.h"

World::World()
{
}

std::vector<Object*>& World::getObjects()
{
    return this->objects;
}

void World::setObjects(std::vector<Object*> objects)
{
    this->objects = objects;
}

void World::addObject(Object* obj)
{
    objects.push_back(obj);
}

void World::removeObject(Object* obj)
{
    auto iterator = objects.begin();

    while (*iterator != obj && iterator != objects.end()) 
    {
        std::advance(iterator, 1);
    }

    if (iterator != objects.end())
    {
        objects.erase(iterator);
    } 
    else
    {
        std::cerr << "ERROR: Object not found!" << std::endl;
    }
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
