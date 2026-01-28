#include "Object.h"
#include "GLFWKeyManager.h"
#include "pugixml.hpp"

Object::Object()
{
    this->objectId = objectCounter++;

    this->vertexList = 
    { 
      {{ 0.5f, 0.5f,0.0f,1.0f},{ 1.0f,0.0f,0.0f,1.0f},{1,1}},//superior derecha
      {{-0.5f, 0.5f,0.0f,1.0f},{ 1.0f,0.0f,0.0f,1.0f},{0,1}},//superior izquierda
      {{-0.5f,-0.5f,0.0f,1.0f},{ 1.0f,0.0f,1.0f,1.0f},{0,0}},//inferior izquierda 
      {{ 0.5f,-0.5f,0.0f,1.0f},{ 0.0f,0.0f,1.0f,1.0f},{1,0}} //inferior derecha
    }; //posiciones de vertices

    this->vertexIndexList = { 2,1,0, 2,0,3 };

    this->pos = { 0.0f,0.0f,0.0f,1.0f };
    this->rot = { 0.0f,0.0f,0.0f,1.0f };
    this->scaling = { 1.0f,1.0f,1.0f,1.0f };

    //crear programa de dibujado
    material = new Material();
    material->renderProgram = new Program();
    material->renderProgram->addShader("data/shader.vert"); //añadir codigo de renderizado
    material->renderProgram->addShader("data/shader.frag");
    material->renderProgram->linkProgram(); //compilar/linkar

    material->texture = new GLTexture("data/ship.png");


}

Object::Object(string mshFile):mshFile(mshFile)
{
    this->objectId = objectCounter++;

    this->pos = { 0.0f,0.0f,0.0f,1.0f };
    this->rot = { 0.0f,0.0f,0.0f,1.0f };
    this->scaling = { 1.0f,1.0f,1.0f,1.0f };


    loadFile(mshFile);
}

glm::mat4 Object::getModelMatrix()
{
    glm::mat4  model= glm::mat4(1.0f);

    model = glm::translate(model, glm::vec3(pos));//aplicar posicion

    model = glm::rotate(model, glm::radians(rot.x), glm::vec3(1.0f, 0.0f, 0.0f)); //rotar x
    model = glm::rotate(model, glm::radians(rot.y), glm::vec3(0.0f, 1.0f, 0.0f)); //rotar y
    model = glm::rotate(model, glm::radians(rot.z), glm::vec3(0.0f, 0.0f, 1.0f)); //rotar z

    model = glm::scale(model, glm::vec3(scaling));//aplicar posicion


    return model;
}

void Object::step(float timeStep)
{
    float vel = 0.1f; //unidadesGl segundo
    float velRot = 40.0f;
    /*if (GLFWKeyManager::keyboardState[GLFW_KEY_D])
        this->pos.x += vel * timeStep;
    if (GLFWKeyManager::keyboardState[GLFW_KEY_A])
        this->pos.x -= vel * timeStep;
    if (GLFWKeyManager::keyboardState[GLFW_KEY_W])
        this->pos.y += vel * timeStep;
    if (GLFWKeyManager::keyboardState[GLFW_KEY_S])
        this->pos.y -= vel * timeStep;
        */
    if (GLFWKeyManager::keyboardState[GLFW_KEY_R])
        this->rot.x += velRot * timeStep;
    if (GLFWKeyManager::keyboardState[GLFW_KEY_T])
        this->rot.x -= velRot * timeStep;

}

void Object::loadFile(string mshFile)
{


    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(mshFile.c_str());
    if (result) {
        // Cargado correctamente, podemos analizar su contenido ...
        pugi::xml_node buffersNode = doc.child("mesh").child("buffers");

        for (pugi::xml_node bufferNode = buffersNode.child("buffer");
            bufferNode;
            bufferNode = bufferNode.next_sibling("buffer"))
        {
            // Iteramos por todos los buffers
            auto materialNode = bufferNode.child("material");
            material = new Material();
            
            auto textureNode = materialNode.child("texture");
            if (textureNode)
            {
                //layers
                //añadir nueva textura
                material->texture = new GLTexture(textureNode.child("layer").text().as_string());
            }
            auto shaderNode = materialNode.child("shader");
            if (shaderNode)
            {
                material->renderProgram = new Program();
                auto shaderList = splitString<string>(shaderNode.text().as_string(), ',');
                for (auto& s : shaderList) {
                    material->renderProgram->addShader(s);
                }
                material->renderProgram->linkProgram();
            }

            string meshData = bufferNode.child("meshData").text().as_string();
            loadObj(meshData);
        }

    }
    else {
        // No se ha podido cargar
        std::cout << result.description() << std::endl;
    }
}

void Object::loadObj(string objFile)
{

        std::ifstream f(objFile, std::ios_base::in);
        std::vector<glm::vec4> vPos;
        std::vector<glm::vec2> vTC;
        std::vector<glm::vec4> vNorm;
        std::string line;
        //Mesh* m = nullptr;
        int vertexOffset = 0;
        while (std::getline(f, line, '\n')) {
            std::istringstream str(line);
            std::string key;
            str >> key;
            if (key[0] != '#') {
                if (key == "o")
                {
                    //if (m) meshList.push_back(m);
                    //m = new Mesh();
                    //m->mat = mat;
                    vertexOffset = vPos.size();
                }
                else if (key == "v")
                {
                    glm::vec4 v(1.0f);
                    str >> v.x >> v.y >> v.z;
                    vPos.push_back(v);
                    this->vertexList.push_back(vertex_t{});
                }
                else if (key == "vn")
                {
                    glm::vec4 v(0);
                    str >> v.x >> v.y >> v.z;
                    vNorm.push_back(v);
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
                        v[i] = { vPos[indexes[0] - 1],{0,0,0,0},//vNorm[indexes[2] -m1],
                            vTC[indexes[1] - 1] };
                        this->vertexList[indexes[0] - 1 - vertexOffset] = v[i];
                        this->vertexIndexList.push_back(indexes[0] - 1 - vertexOffset);
                    }
                }
            }
        }
        //if (m) meshList.push_back(m);
}




