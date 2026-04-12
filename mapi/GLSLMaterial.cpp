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
	program->setVertexAttrib("vNorm", sizeof(vertex_t), (void*)offsetof(vertex_t, vNorm), 4, GL_FLOAT);
	
	if (!texture)
		program->setColorTextDisable();
	else
	{
		program->setColorTextEnable();
		program->bindColorTextureSample(texture->getTextureID(), texture);
	}
	
	if (light)
	{
		program->setComputeLightEnable();
		program->setFloat("material.shininess", shininess);
		program->setFloat("material.ambientK", world->getAmbient());
		program->setVec4("cameraPos", cam->getPosition());
		int nLights = world->getNumLights();
		program->setInt("nLights", nLights);
		
		for (int i = 0; i < nLights; i++)
		{
			auto light = world->getLight(i);
			if (light)
			{
				if (light->getIsEnabled())
				{
					program->setVec4("lights[" + std::to_string(i) + "].position", light->getPosition());
					program->setVec4("lights[" + std::to_string(i) + "].direction", light->getDirection());
					program->setVec4("lights[" + std::to_string(i) + "].color", light->getColor());
					program->setInt("lights[" + std::to_string(i) + "].type", light->getLightType());
					program->setFloat("lights[" + std::to_string(i) + "].linearAttenuation", light->getLinearAttenuation());
					program->setLightEnable(i);
				}
				else
				{
					program->setLightDisable(i);
				}
				
			}
		}
	}
	
	program->readVarList();
}
