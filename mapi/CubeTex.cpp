#include "CubeTex.h"

#include "FactoryEngine.h"
#include "GLTexture.h"

CubeTex::CubeTex()
{
    setPosition({ 0,0,0,1 });
    setRotation({ 0,0,0,1 });
    setScale({ 1,1,1,1 });
    
    auto mesh1 = new Mesh3D();
    auto mesh2 = new Mesh3D();
    
    mesh1->setMaterial(FactoryEngine::getNewMaterial());
    mesh2->setMaterial(FactoryEngine::getNewMaterial());
    
    //Se cargan los shaders de la primera malla para reutilizarlos.
    mesh1->getMaterial()->loadProgram({"data/shader.vert","data/shader.frag"});
    mesh2->getMaterial()->setProgram(mesh1->getMaterial()->getProgram());
    
    // Mesh 1 - Front face
	mesh1->addVertex({
		glm::vec4(0.5f, 0.5f, 0.5f, 1.0f),
		glm::vec4(0.0f, 0.0f, 0.0f, 1.0f),
		glm::vec4(0,0,0,0),
		glm::vec2(1, 1)
		});
	mesh1->addVertex({
		glm::vec4(-0.5f, 0.5f, 0.5f, 1.0f),
		glm::vec4(0.0f, 0.0f, 0.0f, 1.0f),
		glm::vec4(0,0,0,0),
		glm::vec2(0, 1)
		});
	mesh1->addVertex({
		glm::vec4(-0.5f, -0.5f, 0.5f, 1.0f),
		glm::vec4(0.0f, 0.0f, 0.0f, 1.0f),
		glm::vec4(0,0,0,0),
		glm::vec2(0, 0)
		});
	mesh1->addVertex({
		glm::vec4(0.5f, -0.5f, 0.5f, 1.0f),
		glm::vec4(0.0f, 0.0f, 0.0f, 1.0f),
		glm::vec4(0,0,0,0),
		glm::vec2(1, 0)
		});

	// Mesh 1 - Back face
	mesh1->addVertex({
		glm::vec4(0.5f, 0.5f, -0.5f, 1.0f),
		glm::vec4(0.0f, 0.0f, 0.0f, 1.0f),
		glm::vec4(0,0,0,0),
		glm::vec2(0, 1)
		});
	mesh1->addVertex({
		glm::vec4(-0.5f, 0.5f, -0.5f, 1.0f),
		glm::vec4(0.0f, 0.0f, 0.0f, 1.0f),
		glm::vec4(0,0,0,0),
		glm::vec2(1, 1)
		});
	mesh1->addVertex({
		glm::vec4(-0.5f, -0.5f, -0.5f, 1.0f),
		glm::vec4(0.0f, 0.0f, 0.0f, 1.0f),
		glm::vec4(0,0,0,0),
		glm::vec2(1, 0)
		});
	mesh1->addVertex({
		glm::vec4(0.5f, -0.5f, -0.5f, 1.0f),
		glm::vec4(0.0f, 0.0f, 0.0f, 1.0f),
		glm::vec4(0,0,0,0),
		glm::vec2(0, 0)
		});

	// Mesh 2 - Top face
	mesh2->addVertex({
		glm::vec4(0.5f, 0.5f, -0.5f, 1.0f),   // Back-right
		glm::vec4(0.0f, 0.0f, 0.0f, 1.0f),
		glm::vec4(0,0,0,0),
		glm::vec2(1, 1)
		});
	mesh2->addVertex({
		glm::vec4(-0.5f, 0.5f, -0.5f, 1.0f),  // Back-left
		glm::vec4(0.0f, 0.0f, 0.0f, 1.0f),
		glm::vec4(0,0,0,0),
		glm::vec2(0, 1)
		});
	mesh2->addVertex({
		glm::vec4(-0.5f, 0.5f, 0.5f, 1.0f),   // Front-left
		glm::vec4(0.0f, 0.0f, 0.0f, 1.0f),
		glm::vec4(0,0,0,0),
		glm::vec2(0, 0)
		});
	mesh2->addVertex({
		glm::vec4(0.5f, 0.5f, 0.5f, 1.0f),    // Front-right
		glm::vec4(0.0f, 0.0f, 0.0f, 1.0f),
		glm::vec4(0,0,0,0),
		glm::vec2(1, 0)
		});

	// Mesh 2 - Bottom face
	mesh2->addVertex({
		glm::vec4(0.5f, -0.5f, 0.5f, 1.0f),   // Front-right
		glm::vec4(0.0f, 0.0f, 0.0f, 1.0f),
		glm::vec4(0,0,0,0),
		glm::vec2(1, 1)
		});
	mesh2->addVertex({
		glm::vec4(-0.5f, -0.5f, 0.5f, 1.0f),  // Front-left
		glm::vec4(0.0f, 0.0f, 0.0f, 1.0f),
		glm::vec4(0,0,0,0),
		glm::vec2(0, 1)
		});
	mesh2->addVertex({
		glm::vec4(-0.5f, -0.5f, -0.5f, 1.0f), // Back-left
		glm::vec4(0.0f, 0.0f, 0.0f, 1.0f),
		glm::vec4(0,0,0,0),
		glm::vec2(0, 0)
		});
	mesh2->addVertex({
		glm::vec4(0.5f, -0.5f, -0.5f, 1.0f),  // Back-right
		glm::vec4(0.0f, 0.0f, 0.0f, 1.0f),
		glm::vec4(0,0,0,0),
		glm::vec2(1, 0)
		});

	// Front face
	mesh1->addTriangle(2, 1, 0);
	mesh1->addTriangle(2, 0, 3);

	// Back face
	mesh1->addTriangle(4, 5, 6);
	mesh1->addTriangle(4, 6, 7);

	// Right face
	mesh1->addTriangle(3, 0, 4);
	mesh1->addTriangle(3, 4, 7);

	// Left face
	mesh1->addTriangle(6, 5, 1);
	mesh1->addTriangle(6, 1, 2);

	// Top face
	mesh2->addTriangle(0, 1, 2);
	mesh2->addTriangle(0, 2, 3);

	// Bottom face
	mesh2->addTriangle(4, 5, 6);
	mesh2->addTriangle(4, 6, 7);
	
	auto texture1 = FactoryEngine::getNewTexture();
	auto texture2 = FactoryEngine::getNewTexture();
	
	texture1->load("data/textures/front.png");
	texture2->load("data/textures/top.png");
	
	dynamic_cast<GLTexture*>(texture1)->setupGLTexture();
	dynamic_cast<GLTexture*>(texture2)->setupGLTexture();
	
	mesh1->getMaterial()->setTexture(texture1);
	mesh2->getMaterial()->setTexture(texture2);
	
	setMeshes(std::vector<Mesh3D*>{mesh1, mesh2});
	
	computeModelMatrix();
}

void CubeTex::step(double deltaTime)
{
	//rotation.y += angularVelocity * deltaTime;
}
