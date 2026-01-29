#include "System.h"

System::System()
{
}

Render* System::getRender()
{
	return render;
}

InputManager* System::getInputManager()
{
	return inputManager;
}

bool System::getEnd()
{
	return end;
}

World* System::getWorld()
{
	return world;
}

glm::mat4 System::getModelMatrix()
{
	return ModelMatrix;
}

void System::setRender(Render* newRender)
{
	render = newRender;
}

void System::setInputManager(InputManager* newInputManager)
{
	inputManager = newInputManager;
}

void System::setEnd(bool newEnd)
{
	end = newEnd;
}

void System::setWorld(World* newWorld)
{
	world = newWorld;
}

void System::setModelMatrix(glm::mat4 newModelMatrix)
{
	ModelMatrix = newModelMatrix;
}

void System::initSystem()
{
	FactoryEngine::setSelectedGraphicsBackend(GraphicsBackend::GL4);
	FactoryEngine::setSelectedInputBackend(InputBackend::GLFW);

	render = FactoryEngine::getNewRender();
	inputManager = FactoryEngine::getNewInputManager();
	render->init();
	inputManager->init();

	end = false;

	world = new World();
}

void System::addObject(Object* obj)
{
	world->addObject(obj);
}

void System::exit()
{
	end = render->isClosed();
}

void System::mainLoop()
{
	for (Object* obj : world->getObjects())
	{
		render->setupObject(obj);
	}

	while (!end)
	{
		newTime = static_cast<float>(glfwGetTime());
		deltaTime = newTime - lastTime;
		lastTime = newTime;

		world->update(deltaTime);

		std::vector<Object*> obj_vector{ std::begin(world->getObjects()), std::end(world->getObjects()) };
		render->drawObjects(&obj_vector);

		delete obj_vector;
	}
}
