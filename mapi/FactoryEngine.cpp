#include "FactoryEngine.h"

FactoryEngine::FactoryEngine()
{
}


GraphicsBackend FactoryEngine::getSelectedGraphicsBackend()
{
	return selectedGraphicsBackend;
}


InputBackend FactoryEngine::getSelectedInputBackend()
{
	return selectedInputBackend;
}


void FactoryEngine::setSelectedGraphicsBackend(GraphicsBackend newSelectedGraphicsBackend)
{
	selectedGraphicsBackend = newSelectedGraphicsBackend;
}


void FactoryEngine::setSelectedInputBackend(InputBackend newSelectedInputBackend)
{
	selectedInputBackend = newSelectedInputBackend;
}


Render* FactoryEngine::getNewRender()
{
	switch (selectedGraphicsBackend)
	{
	case (int)GL1:
		// activeRender = new GL1Render();
		// return activeRender;
		break;

	case (int)GL2:
		// activeRender = new GL2Render();
		// return activeRender;
		break;

	case (int)GL3:
		// activeRender = new GL3Render();
		// return activeRender;
		break;

	case (int)GL4:
		activeRender = new GL4Render(640, 480);
		return activeRender;

	default:
		std::cerr << "ERROR: Input manager type not recognised!" << std::endl;
		break;
	}
}


InputManager* FactoryEngine::getNewInputManager()
{
	switch (selectedInputBackend)
	{
	case (int)GLFW:
		return new GLFWInputManager();

	default:
		std::cout << "ERROR: Input manager type not recognised!" << std::endl;
		break;
	}
}


Material* FactoryEngine::getNewMaterial()
{
	if (selectedGraphicsBackend == GraphicsBackend::GL4) 
	{
		return new GLSLMaterial();
	}
}


bool FactoryEngine::isClosed()
{
	return activeRender->isClosed();
}
