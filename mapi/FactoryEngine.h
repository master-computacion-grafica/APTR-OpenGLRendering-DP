#pragma once

#include "Render.h"
#include "InputManager.h"
#include "GLSLMaterial.h"
#include "Texture.h"


static enum GraphicsBackend
{
	GL1, GL2, GL3, GL4
};

static enum InputBackend 
{
	GLFW
};

class FactoryEngine
{
private:

	// ATTRIBUTES //

	static inline GraphicsBackend  selectedGraphicsBackend;

	static inline InputBackend selectedInputBackend;

	static inline Render* activeRender;


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
	static Texture* getNewTexture();

	static bool isClosed();
};

