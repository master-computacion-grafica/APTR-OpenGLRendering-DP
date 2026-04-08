#define GLAD_BIN
#define STB_IMAGE_IMPLEMENTATION
#include "CameraFPS.h"
#include "FactoryEngine.h"
#include "System.h"
#include "TrianguloRot.h"
#include "CameraKeyboard.h"
#include "CubeTex.h"


int main(int argc, char** argv)
{
	// Configurar el FactoryEngine
	FactoryEngine::setSelectedGraphicsBackend(GraphicsBackend::GL4);
	FactoryEngine::setSelectedInputBackend(InputBackend::GLFW);

	// Inicializar la clase System
	System::initSystem();

	CameraFPS* camFPS = new CameraFPS(projectionType_e::FPS, glm::vec3(0.0f, 0.01f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f), 1.0f);
	CameraKeyboard* camKeyboard = new CameraKeyboard(projectionType_e::KEYBOARD, glm::vec3(0.0f, 0.1f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f), 1.0f);
	World* world = System::getWorld();
	world->addCamera(camFPS);
	world->addCamera(camKeyboard);
	world->setActiveCamera(world->getCameraIndex(camKeyboard));
	
	//Crear objeto ciudad
	Object3D* cubeTest = new Object3D(
		glm::vec4(0,0,0,1), 
		glm::vec4(0,0,0,1), 
		glm::vec4(1,1,1,1));
	
	// Cargar mallas desde archivo
	cubeTest->loadDataFromFile("./data/lightBox/texturedCube.msh");

	System::addObject(cubeTest);
	
	// //Crear objeto ciudad
	// Object3D* town = new Object3D(
	// 	glm::vec4(0,0,0,1), 
	// 	glm::vec4(0,0,0,1), 
	// 	glm::vec4(1,1,1,1));
	//
	// // Cargar mallas desde archivo
	// town->loadDataFromFile("./data/asian_town.msh");

	// System::addObject(town);
	
	System::mainLoop();
	
}

//if (glfwInit() != GLFW_TRUE)
//	{	
//		std::cout << "ERROR iniciando glfw\n";
//	}
//	else {
//	
//		
//		//iniciar opengl
//#ifdef __APPLE__
//		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
//		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
//		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//#endif
//		
//		GLFWwindow* window= glfwCreateWindow(640, 480, "Tutorial APIS3D",nullptr, nullptr);
//		glfwMakeContextCurrent(window);
//
//		
//		gladLoadGL(glfwGetProcAddress);
//		
//		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
//		glEnable(GL_DEPTH_TEST);
//		//iniciar eventos
//		GLFWKeyManager::initKeyManager(window);
//		//bucle principal
//
//		float newTime = static_cast<float>(glfwGetTime());
//		float deltaTime = 0;
//		float lastTime = newTime;
//
//		bool salir = false;
//
//
//		Camera cam(glm::vec4(0, 0, 3,1 ), glm::vec4(0, 0, 0, 1));
//		objectList.push_back(new Object("data/lightBox/texturedCube.msh")); //a�adir un nuevo objeto cargado de fichero
//
//		//por cada objeto
//			//copiar a GPU
//		for (auto& obj : objectList)
//		{
//			setupObject(obj);
//		}
//
//		while (!salir)
//		{
//			newTime = static_cast<float>(glfwGetTime());
//			deltaTime = newTime - lastTime;
//			lastTime = newTime;
//
//			//capturar eventos
//			GLFWKeyManager::updateEvents();
//			//actualizar estado aplicacion
//			//limpiar buffer de imagen
//			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//			updateObjects(deltaTime,cam);
//			//dibujar
//
//			glfwSwapBuffers(window);//una vez dibujado, intercambiar buffer de imagen en ventana
//			salir = glfwWindowShouldClose(window);
//			
//		}
//		//cerrar librer�as gr�ficas
//
//		glfwTerminate();
//	
//	}
//	return 0;