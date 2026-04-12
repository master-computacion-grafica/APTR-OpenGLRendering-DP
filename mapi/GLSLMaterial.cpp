#include "GLSLMaterial.h"

#include <algorithm>

#include "System.h"
#include "GLSLProgram.h"



GLSLMaterial::GLSLMaterial()
{
	this->program = new GLSLProgram();
}


void GLSLMaterial::loadProgram(std::list<std::string> programNames)
{
	for (std::string name : programNames)
	{
		program->addProgram(name);
	}

	for (Program* shader : program->getShaders()) 
	{
		shader->compile();

		if (!shader->isCompiled())
		{
			std::cerr << "ERROR: Shader couldn't compile!" << std::endl;
			return;
		}
	}

	program->linkProgram();
	if (program->checkLinkerErrors()) 
	{
		std::cerr << "ERROR: Couldn't link program!" << std::endl;
		return;
	}
}


void GLSLMaterial::prepare()
{
	// Obtener la camara activa
	World* world = System::getWorld();
	Camera* cam = world->getCamera(world->getActiveCamera());

	// Settear en el shader las matrices derivades del objeto y la camara
	glm::mat4 M = System::getModelMatrix();
	glm::mat4 MVP = cam->getProjection() * cam->getView() * M;
	program->setMatrix("MVP", MVP);
	program->setMatrix("M", M);
	program->setMatrix("NORM", glm::transpose(glm::inverse(M)));

	// Settear en el shader los datos de los vertices
	program->setVertexAttrib("vPos", sizeof(vertex_t), (void*)offsetof(vertex_t, vPosition), 4, GL_FLOAT);
	program->setVertexAttrib("vColor", sizeof(vertex_t), (void*)offsetof(vertex_t, vColor), 4, GL_FLOAT);
	program->setVertexAttrib("vTexCoord", sizeof(vertex_t), (void*)offsetof(vertex_t, vTexCoords), 2, GL_FLOAT);
	program->setVertexAttrib("vNorm", sizeof(vertex_t), (void*)offsetof(vertex_t, vNormal), 4, GL_FLOAT);

	// Settear la flag de textura en el shader
	if (!texture)
		program->setColorTextDisable();
	else
	{
		program->setColorTextEnable();
		program->bindColorTextureSample(texture->getTextureID(), texture);
	}

	// Si el material permite interaccion con luces
	if (lightEnable)
	{
		// Settear la flag y la propiedad shininess en el shader
		program->setBool("mat.lightEnable", true);
		program->setFloat("mat.shininess", shininess);

		// Settear la posicion de la camara
		program->setVec3("camPos", cam->getPosition());
		
		// Si el mundo tiene luces settearlas para el shader de fragmentos
		if (!world->getLights().empty())
		{
			// Obtener el número de luces en el mundo y tener en cuenta como maximo las 8 primeras (limite del shader)
			int n = world->getLights().size();
			n = glm::clamp(n, 0, 8);

			// Settear en el shader tanto el numero de luces como las luces
			program->setInt("nLights", n);
			
			for (int i = 0; i < n; i++)
			{
				program->setLight(i);
			}
		}

		// Settear la componente ambiental del mundo
		program->setFloat("ambient", world->getAmbient());
	}

	// Leer la lista de variables
	program->readVarList();
}
