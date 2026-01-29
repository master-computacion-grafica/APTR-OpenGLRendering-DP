#pragma once
#include <string>

typedef enum class programTypes_e {
	vertex = 0, fragment = 1
}programTypes_e;


class Program
{
protected:

	// ATTRIBUTES //

	programTypes_e type;

	std::string fileName;

	unsigned int idProgram;

	static unsigned int count;


public:

	// CONSTRUCTOR //

	Program(std::string fileName);


	// GETTERS && SETTERS //

	programTypes_e getType() { return this->type; }
	std::string getFileName() { return this->fileName; }
	unsigned int getIdProgram() { return this->idProgram; }

	void setType(programTypes_e type) { this->type = type; }
	void setFileName(std::string fileName) { this->fileName = fileName; }
	void setIdProgram(unsigned int idProgram) { this->idProgram = idProgram; }


	// METHODS && FUNCTIONS //

	virtual void readFile() = 0;

	virtual void compile() = 0;

	virtual void checkErrors() = 0;
};

//private:
//	vector<string> shaderList;//lista de archivos de codigo GLSL shader
//	unsigned int programId; //identificador OpenGl de programa GLSL
//	map<string, unsigned int> varList; //Lista de variables en programa
//	bool linked = false;
//public:
//	Program() { programId = -1; };
//	void addShader(string fileName) { shaderList.push_back(fileName); };
//	void linkProgram();
//	void readVarList();
//	void activate() { glUseProgram(programId); };
//	//set datos de atributos
//	void setAttributeMetaData(string attribName, GLint size, GLenum type, GLboolean
//		normalized, GLsizei stride, const GLvoid* pointer);
//	//set datos de uniform
//	void setMVP(glm::mat4 m);
//	void setTextureData(int textureUnit, int textureId, GLenum textureType);