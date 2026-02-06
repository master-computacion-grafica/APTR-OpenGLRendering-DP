
#pragma once

#include "mapi/common.h"
#include "Render.h"
#include "InputManager.h"
#include "World.h"
#include "FactoryEngine.h"


class System
{
private:

	// ATTRIBUTES //

	static inline Render* render;

	static inline InputManager* inputManager;

	static inline bool end;

	static inline World* world;

	static inline double deltaTime, newTime, lastTime;

	static inline glm::mat4 ModelMatrix;


public:

	// GETTERS && SETTERS //

	static Render* getRender();
	static InputManager* getInputManager();
	static bool getEnd();
	static World* getWorld();
	static glm::mat4 getModelMatrix();

	static void setRender(Render* newRender);
	static void setInputManager(InputManager* newInputManager);
	static void setEnd(bool newEnd);
	static void setWorld(World* newWorld);
	static void setModelMatrix(glm::mat4 newModelMatix);


	// METHODS && FUNCTIONS //

	static void initSystem();
	static void addObject(Object* obj);
	static void exit();
	static void mainLoop();


	// DESTRUCTOR //

	~System() = default;

};