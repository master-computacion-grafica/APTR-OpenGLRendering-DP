#pragma once

#include "mapi/common.h"
#include "Render.h"
#include "InputManager.h"
#include "GLFWInputManager.h"
#include "GLSLMaterial.h"
#include "GL4Render.h"


static enum GraphicsBackend
{
	GL1, GL2, GL3, GL4
};

static enum InputBackend 
{
	GLFW
};

static class FactoryEngine
{
private:

	// ATTRIBUTES //

	static GraphicsBackend  selectedGraphicsBackend;

	static InputBackend selectedInputBackend;

	static Render* activeRender;


public:


	// GETTERS && SETTERS //

	static GraphicsBackend getSelectedGraphicsBackend();
	static InputBackend getSelectedInputBackend();

	static void setSelectedGraphicsBackend(GraphicsBackend newSelectedGraphicsBackend);
	static void setSelectedInputBackend(InputBackend newSelectedInputBackend);


	// METHODS && FUNCTIONS //

	static Render* getNewRender();
	static InputManager* getNewInputManager();
	static Material* getNewMaterial();

	static bool isClosed();
};

