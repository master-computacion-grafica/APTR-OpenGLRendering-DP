#include "Object3D.h"

#include "FactoryEngine.h"
#include "GLTexture.h"
#include "pugixml.hpp"

Object3D::Object3D(glm::vec4 position, glm::vec4 rotation, glm::vec4 scale)
{
	this->position = position;
	this->rotation = rotation;
	this->scale = scale;
	
	computeModelMatrix();
}

void Object3D::loadDataFromFile(std::string file)
{
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file(file.c_str());
	
	if (result) {
		// Cargado correctamente, podemos analizar su contenido ...
		pugi::xml_node buffersNode = doc.child("mesh").child("buffers");
		
		for (pugi::xml_node bufferNode = buffersNode.child("buffer");
			bufferNode;
			bufferNode = bufferNode.next_sibling("buffer"))
		{
			// Iteramos por todos los buffers
			auto materialNode = bufferNode.child("material");
			auto material = FactoryEngine::getNewMaterial();
            
			auto textureNode = materialNode.child("texture");
			if (textureNode)
			{
				//layers
				//a�adir nueva textura
				
				auto texture = FactoryEngine::getNewTexture();
				texture->load(textureNode.child("layer").text().as_string());
				dynamic_cast<GLTexture*>(texture)->setupGLTexture();
				material->setTexture(texture);
			} else
			{
				textureNode = materialNode.child("color");

				if (textureNode)
				{
					std::string colorStr = textureNode.text().as_string();
					auto colorComponents = splitString<float>(colorStr, ',');
					material->setColor(glm::vec4(colorComponents[0], colorComponents[1], colorComponents[2], 1));
				} else
				{
					material->setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
				}
			}
			
			auto shaderNode = materialNode.child("shader");
			if (shaderNode)
			{
				auto shaderVector = splitString<std::string>(shaderNode.text().as_string(), ',');
				
				std::list<std::string> shaderList{std::begin(shaderVector), std::end(shaderVector)};
				
				material->loadProgram(shaderList);
			}

			auto lightNode = materialNode.child("light");
			if (lightNode)
			{
				material->setLightEnable(lightNode.text().as_bool());
			}

			auto shininessNode = materialNode.child("shininess");
			if (shininessNode)
			{
				material->setShininess(shininessNode.text().as_float());
			}

			std::string meshData = bufferNode.child("meshData").text().as_string();
			loadObj(meshData, material);
		}

	}
	else {
		// No se ha podido cargar
		std::cout << result.description() << std::endl;
	}
}

void Object3D::recomputeNormals()
{
	for (auto& m : meshes) {
		std::vector<vertex_t> vertexList = m->getVertexList();
		
		for (auto& v : vertexList) //por cada v�rtice, resetear sus normales
			v.vNormal = { 0,0,0,0 };
		for (auto it = m->getTriangleIndexList()->begin(); it != m->getTriangleIndexList()->end();)//recorrer la lista de indices de vertices
		{
			//cada tres vertices, una faceta
			vertex_t& v1 = vertexList[*it]; it++; 
			vertex_t& v2 = vertexList[*it]; it++;
			vertex_t& v3 = vertexList[*it]; it++;
			
			glm::vec3 l1 = glm::normalize(v2.vPosition - v1.vPosition); //obtener dos aristas
			glm::vec3 l2 = glm::normalize(v2.vPosition - v3.vPosition);
			glm::vec3 norm = glm::normalize(glm::cross(l2, l1)); //obtener la normal
			
			v1.vNormal = glm::normalize(v1.vNormal + glm::vec4(norm, 0.0f)); //acumular la normal, en caso de ser v�rtices compartidos
			v2.vNormal = glm::normalize(v2.vNormal + glm::vec4(norm, 0.0f));
			v3.vNormal = glm::normalize(v3.vNormal + glm::vec4(norm, 0.0f));
		}
	}
}

void Object3D::loadObj(std::string objFile, Material* material)
{

	
        std::ifstream f(objFile, std::ios_base::in);
        std::vector<glm::vec4> vPos;
        std::vector<glm::vec2> vTC;
        std::vector<glm::vec4> vNorm;
        std::string line;
        Mesh3D* m = nullptr;
        int vertexOffset = 0;
		bool computeNormals = true;
	
        while (std::getline(f, line, '\n')) {
            std::istringstream str(line);
            std::string key;
            str >> key;
            if (key[0] != '#') {
                if (key == "o")
                {
                    if (m) meshes.push_back(m);
                    m = new Mesh3D();
                    m->setMaterial(material);
                    vertexOffset = vPos.size();
                }
                else if (key == "v")
                {
                    glm::vec4 v(1.0f);
                    str >> v.x >> v.y >> v.z;
                    vPos.push_back(v);
                	m->getVertexList().push_back(vertex_t{});
                }
                else if (key == "vn")
                {
                    glm::vec4 v(0);
                    str >> v.x >> v.y >> v.z;
                    vNorm.push_back(v);

                	if (computeNormals) computeNormals = false;
                }

                else if (key == "vt")
                {
                    glm::vec2 v(0);
                    str >> v.x >> v.y;
                    vTC.push_back(v);
                }
                else if (key == "f")
                {
                    std::string vert;
                    vertex_t v[3];
                    int vIndex[3] = { 0 };
                    for (int i = 0; i < 3; i++)
                    {
                        str >> vert;
                        auto indexes = splitString<int>(vert, '/');
                        v[i] = { vPos[indexes[0] - 1],{0,0,0,0},vNorm[indexes[2] - m1],
                            vTC[indexes[1] - 1] };
                        m->getVertexList()[indexes[0] - 1 - vertexOffset] = v[i];
                        m->getTriangleIndexList()->push_back(indexes[0] - 1 - vertexOffset);
                    }
                }
            }
        }
		if (computeNormals)
			this->recomputeNormals();
        if (m) meshes.push_back(m);
}

void Object3D::step(double deltaTime)
{
}

