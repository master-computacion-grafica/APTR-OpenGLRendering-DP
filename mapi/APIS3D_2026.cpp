#define GLAD_BIN
#include "mapi/common.h"
#include "GLFWKeyManager.h"
#include "Object.h"
#include "Camera.h"

using namespace std;

typedef struct {

	//id de array de buffers
	unsigned int arrayBufferId;
	//id de vertex array buffer
	unsigned int vertexArrayId;
	//id de vertex index buffer
	unsigned int vertexIdxArrayId;
}bo_t; //datos de buffer objects

vector<Object*> objectList; //lista de objetos en el mundo 3D
map<int, bo_t> bufferObjectList; //listas de datos en GPU, indexadas por Identificador único de Objeto


void setupObject(Object* obj)
{
	bo_t bo = { 0,0,0 };

	//crear buffers objects
	glGenVertexArrays(1, &bo.arrayBufferId);
	glGenBuffers(1, &bo.vertexArrayId);
	glGenBuffers(1, &bo.vertexIdxArrayId);
	//copiar datos a GPU
	glBindVertexArray(bo.arrayBufferId); //activar lista de arrays
	glBindBuffer(GL_ARRAY_BUFFER, bo.vertexArrayId);//activar lista de vértices
	int numElements = obj->vertexList.size();
	glBufferData(GL_ARRAY_BUFFER, numElements *sizeof(vertex_t), obj->vertexList.data(), GL_STATIC_DRAW); //copiar vertices

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bo.vertexIdxArrayId);//activar lista de indices de vértices
	numElements = obj->vertexIndexList.size();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, numElements * sizeof(unsigned int), obj->vertexIndexList.data(), GL_STATIC_DRAW); //copiar indices de vertices
	//guardar ids de buffers
	bufferObjectList[obj->objectId] = bo;

}

void updateObjects(float timeStep, Camera& cam)
{

	//por cada objeto
		//actualizar eventos
	cam.step(timeStep);

	for (auto &obj : objectList)
	{
		obj->step(timeStep);
	}

	//por cada objeto
		//dibujar
	for (auto& obj : objectList)
	{
		//calcular matriz modelo
		auto model = obj->getModelMatrix();
		auto mat = obj->material;
		//copiar matriz a GPU
		/*glPushMatrix(); //añadir una matriz en GPU
		glLoadIdentity(); //cargar identidad
		glMultMatrixf(&model[0][0]); //multiplicar por modelo
		*/
		mat->renderProgram->activate();
		
		mat->renderProgram->setMVP(cam.cameraProjection* cam.cameraView * model);

		//activar buffers de datos
		auto bo = bufferObjectList[obj->objectId]; //recuperar ids de buffers de este objeto
		glBindVertexArray(bo.arrayBufferId); //activar lista de arrays
		glBindBuffer(GL_ARRAY_BUFFER, bo.vertexArrayId);//activar lista de vértices
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bo.vertexIdxArrayId);//activar lista de indices de vértices
		//describir buffers
		mat->renderProgram->setAttributeMetaData("vPos", 4, GL_FLOAT, false, sizeof(vertex_t), (void*)offsetof(vertex_t, vPosition));
		mat->renderProgram->setAttributeMetaData("vColor", 4, GL_FLOAT, false, sizeof(vertex_t), (void*)offsetof(vertex_t, vColor));
		mat->renderProgram->setAttributeMetaData("vTexCoord", 2, GL_FLOAT, false, sizeof(vertex_t), (void*)offsetof(vertex_t, vTexCoord));
		//si hay textura, activarla
		if (mat->texture)
			mat->renderProgram->setTextureData(0, mat->texture->GlTextID, GL_TEXTURE_2D);

		//ordenar a dibujar
		glDrawElements(GL_TRIANGLES, obj->vertexIndexList.size(), GL_UNSIGNED_INT, nullptr);
	}
}


int main(int argc, char** argv)
{
	
	if (glfwInit() != GLFW_TRUE)
	{	
		std::cout << "ERROR iniciando glfw\n";
	}
	else {
	
		
		//iniciar opengl
#ifdef __APPLE__
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif
		
		GLFWwindow* window= glfwCreateWindow(640, 480, "Tutorial APIS3D",nullptr, nullptr);
		glfwMakeContextCurrent(window);

		
		gladLoadGL(glfwGetProcAddress);
		
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
		glEnable(GL_DEPTH_TEST);
		//iniciar eventos
		GLFWKeyManager::initKeyManager(window);
		//bucle principal

		float newTime = static_cast<float>(glfwGetTime());
		float deltaTime = 0;
		float lastTime = newTime;

		bool salir = false;


		Camera cam(glm::vec4(0, 0, 3,1 ), glm::vec4(0, 0, 0, 1));
		objectList.push_back(new Object("data/lightBox/texturedCube.msh")); //añadir un nuevo objeto cargado de fichero

		//por cada objeto
			//copiar a GPU
		for (auto& obj : objectList)
		{
			setupObject(obj);
		}

		while (!salir)
		{
			newTime = static_cast<float>(glfwGetTime());
			deltaTime = newTime - lastTime;
			lastTime = newTime;

			//capturar eventos
			GLFWKeyManager::updateEvents();
			//actualizar estado aplicacion
			//limpiar buffer de imagen
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			updateObjects(deltaTime,cam);
			//dibujar

			glfwSwapBuffers(window);//una vez dibujado, intercambiar buffer de imagen en ventana
			salir = glfwWindowShouldClose(window);
			
		}
		//cerrar librerías gráficas

		glfwTerminate();
	
	}
	return 0;

}