#define GLAD_BIN
#define STB_IMAGE_IMPLEMENTATION
#include "CameraFPS.h"
#include "FactoryEngine.h"
#include "System.h"
#include "TrianguloRot.h"
#include "CameraKeyboard.h"
#include "CubeTex.h"
#include "OrbitalLight.h"


int main(int argc, char** argv)
{
	// Configurar el FactoryEngine
	FactoryEngine::setSelectedGraphicsBackend(GraphicsBackend::GL4);
	FactoryEngine::setSelectedInputBackend(InputBackend::GLFW);

	// Inicializar la clase System
	System::initSystem();

	CameraFPS* camFPS = new CameraFPS(projectionType_e::FPS, glm::vec3(0.0f, 0.01f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f), 1.0f);
	CameraKeyboard* camKeyboard = new CameraKeyboard(projectionType_e::KEYBOARD, glm::vec3(0.6f, 1.0f, 0.9f), glm::vec3(-0.54f, -0.93f, -1), glm::vec3(0.0f, 1.0f, 0.0f), 3.0f);
	Light* light = new Light(
		glm::vec4(0,0,0,1), 
		glm::vec4(0,0,0,1), 
		glm::vec4(1,1,1,1), 
		DIRECTIONAL, 
		glm::vec4(1,1,1,1), 
		glm::vec4(0,1,-1,1), 
		0.0f, 
		true);
	
	OrbitalLight* pointLight = new OrbitalLight(
		glm::vec4(0,0,0,1), 
		glm::vec4(0,0,0,1), 
		glm::vec4(1,1,1,1), 
		POINT, 
		glm::vec4(1,0,0,1), 
		glm::vec4(0,0,0,1), 
		0.2f, 
		true,
		glm::vec4(-0.54f, -0.93f, -1, 1),
		10,
		1.5f);
	
	World* world = System::getWorld();
	world->addCamera(camFPS);
	world->addCamera(camKeyboard);
	world->setActiveCamera(world->getCameraIndex(camKeyboard));
	world->setAmbient(0.2f);
	
	world->addLight(light);
	world->addLight(pointLight);
	
	//Crear objeto Test
	// Object3D* cubeTest = new Object3D(
	// 	glm::vec4(0,0,0,1), 
	// 	glm::vec4(0,0,0,1), 
	// 	glm::vec4(1,1,1,1));
	//
	// // Cargar mallas desde archivo
	// cubeTest->loadDataFromFile("./data/lightBox/texturedCube.msh");
	// System::addObject(cubeTest);
	
	//Crear objeto estatua
	Object3D* fengShui = new Object3D(
		glm::vec4(0,0,0,1), 
		glm::vec4(0,0,0,1), 
		glm::vec4(0.005,0.005,0.005,1));
	
	// Cargar mallas desde archivo
	fengShui->loadDataFromFile("./data/feng_shui/Feng_Shui.msh");
	
	System::addObject(fengShui);
	
	System::mainLoop();
	
}