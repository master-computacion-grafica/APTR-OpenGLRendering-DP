#include "TrianguloRot.h"

TrianguloRot::TrianguloRot()
{
	Mesh3D mesh = Mesh3D();

	mesh.vVertList =
	{
		{.vPosition = {0.0f, 0.5f, 0.0f, 1.0f}, .vColor = {1.0f, 0.0f, 0.0f, 1.0f}}, //Vertice superior
		{.vPosition = {-0.5f, -0.5f, 0.0f, 1.0f}, .vColor = {1.0f, 0.0f, 1.0f, 1.0f}}, //Vertice izquierda
		{.vPosition = {0.5f, -0.5f, 0.0f, 1.0f}, .vColor = {0.0f, 1.0f, 0.0f, 1.0f}},  //Vertice derecha
	};

	std::vector<glm::uint32>* vec = new std::vector<glm::uint32>();
	vec->push_back(0);
	vec->push_back(1);
	vec->push_back(2);

	mesh.setTriangleIndexList(vec);

	mesh.setMaterial(FactoryEngine::getNewMaterial());
	Material* mat = mesh.getMaterial();

	mat->loadProgram({"data/shader.vert","data/shader.frag"});
	mat->prepare();

	setPosition({ 0,0,0,1 });
	setRotation({ 0,0,0,1 });
	setScale({ 1,1,1,1 });
}


void TrianguloRot::step(double deltaTime)
{
	float angularVelocity = 90.0f;

	if (System::getInputManager()->isPressed(GLFW_KEY_A))
	{
		rotation.y += angularVelocity * deltaTime;
	} 
	
	if (System::getInputManager()->isPressed(GLFW_KEY_D))
	{
		rotation.y -= angularVelocity * deltaTime;
	}

	if (System::getInputManager()->isPressed(GLFW_KEY_E))
	{
		System::exit();
	}
}
