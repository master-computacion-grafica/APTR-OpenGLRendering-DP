#define GLAD_BIN
#define STB_IMAGE_IMPLEMENTATION
#include "CameraFPS.h"
#include "FactoryEngine.h"
#include "System.h"
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

	// Crear y anyadir las camaras
	CameraFPS* camFPS = new CameraFPS(projectionType_e::FPS, glm::vec3(0.6f, 1.0f, 0.9f), glm::vec3(-0.54f, -0.93f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), 1.0f);
	CameraKeyboard* camKeyboard = new CameraKeyboard(projectionType_e::KEYBOARD, glm::vec3(0.6f, 1.0f, 0.9f), glm::vec3(-0.54f, -0.93f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), 1.0f);

	World* world = System::getWorld();
	world->addCamera(camFPS);
	world->addCamera(camKeyboard);
	world->setActiveCamera(world->getCameraIndex(camKeyboard));

	// Crear y anyadir las luces
	world->setAmbient(0.2f);

	Light* dirLight = new Light(
		glm::vec4(0.0f, 0.0, 0.0f, 1.0f),
		glm::vec4(0.0f, 0.0f, 0.0f, 1.0f),
		glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),
		lightType::DIRECTIONAL,
		glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),
		glm::vec4(0.0f, 1.0f, -1.0f, 1.0f),
		0.2f,
		true
	);

	OrbitalLight* pointLight = new OrbitalLight(
		glm::vec4(-10.54f, -0.93f, -1.0f, 1.0f),
		glm::vec4(0.0f, 0.0f, 0.0f, 1.0f),
		glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),
		lightType::POINT,
		glm::vec4(0.0f, 0.0f, 0.0f, 1.0f),
		glm::vec4(1.0f, 0.0f, 0.0f, 1.0f),
		0.2f,
		true,
		glm::vec4(-0.54f, -0.93f, -1.0f, 1.0f),
		10.0f,
		1.5f
	);
	
	world->addLight(dirLight);
	world->addLight(pointLight);
	
	//Crear objeto ciudad
	Object3D* fengshui = new Object3D(
		glm::vec4(0,0,0,1), 
		glm::vec4(0,0,0,1), 
		glm::vec4(1,1,1,1));

	// Object3D* box = new Object3D(
	// 	glm::vec4(0,0,0,1), 
	// 	glm::vec4(0,0,0,1), 
	// 	glm::vec4(1,1,1,1));

	// Cargar mallas desde archivo
	fengshui->loadDataFromFile("./data/feng_shui/Feng_Shui.msh");
	fengshui->setPosition(glm::vec4(-0.54f, -0.93f, -1.0f, 1.0f));
	fengshui->setScale(glm::vec4(0.005f, 0.005f, 0.005f, 1.0f));

	// box->loadDataFromFile("./data/lightBox/texturedCube.msh");
	// box->setPosition(glm::vec4(-0.54f, -0.93f, -1.0f, 1.0f));

	// Anyadir el objeto al mundo
	System::addObject(fengshui);
	// System::addObject(box);
	
	System::mainLoop();
}

//		//cerrar librer�as gr�ficas
//
//		glfwTerminate();
//	
//	}
//	return 0;