#include "GLSLMaterial.h"
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
	World* world = System::getWorld();
	Camera* cam = world->getCamera(world->getActiveCamera());

	glm::mat4 M = System::getModelMatrix();
	glm::mat4 MVP = cam->getProjection() * cam->getView() * M;
	program->setMatrix("MVP", MVP);
	program->setMatrix("M", M);
	program->setMatrix("NORM", glm::transpose(glm::inverse(M)));
	
	program->setVertexAttrib("vPos", sizeof(vertex_t), (void*)offsetof(vertex_t, vPosition), 4, GL_FLOAT);
	program->setVertexAttrib("vColor", sizeof(vertex_t), (void*)offsetof(vertex_t, vColor), 4, GL_FLOAT);
	program->setVertexAttrib("vTexCoord", sizeof(vertex_t), (void*)offsetof(vertex_t, vTexCoords), 2, GL_FLOAT);
	program->setVertexAttrib("vNorm", sizeof(vertex_t), (void*)offsetof(vertex_t, vNormal), 4, GL_FLOAT);
	
	if (!texture)
		program->setColorTextDisable();
	else
	{
		program->setColorTextEnable();
		program->bindColorTextureSample(texture->getTextureID(), texture);
	}

	if (lightEnable)
	{
		program->setBool("mat.lightEnable", true);
		program->setFloat("mat.shininess", shininess);
		
		if (!world->getLights().empty())
		{
			// Si el mundo tiene luces settearlas para el shader de fragmentos
			program->setLight(*(world->getLight(0)));
		}
		else
		{
			// En caso contrario, settear una luz apagada (para que funcione el shader de fragmentos)
			Light l(
				glm::vec4(0.0f, 0.0f, 0.0f, 1.0f),
				glm::vec4(0.0f, 0.0f, 0.0f, 1.0f),
				glm::vec4(0.0f, 0.0f, 0.0f, 0.0f),
				lightType::POINT,
				glm::vec4(0.0f, 0.0f, 0.0f, 0.0f),
				glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),
				1.0f,
				false
			);
			program->setLight(l);
		}	
		program->setFloat("ambient", world->getAmbient());
	}
	else
	{
		program->setFloat("ambient", 1.0f);
	}
	
	program->readVarList();
}
