//#define GLAD_BIN
//#include "mapi/common.h"
//#include "GLFWKeyManager.h"
//#include "Object.h"
//#include "Camera.h"
//
//using namespace std;
//
//vector<Object*> objectList; //lista de objetos en el mundo 3D
//
//void updateObjects(float timeStep, Camera& cam)
//{
//
//	//por cada objeto
//		//actualizar eventos
//	cam.step(timeStep);
//
//	for (auto &obj : objectList)
//	{
//		obj->step(timeStep);
//	}
//}

#include "FactoryEngine.h"
#include "System.h"
#include "TrianguloRot.h"


int main(int argc, char** argv)
{
	// Configurar el FactoryEngine
	FactoryEngine::setSelectedGraphicsBackend(GraphicsBackend::GL4);
	FactoryEngine::setSelectedInputBackend(InputBackend::GLFW);

	// Inicializar la clase System
	System::initSystem();

	//Crear objeto TrianguloRot
	TrianguloRot triangle = TrianguloRot();

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