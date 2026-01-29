#pragma once

#include <vector>
#include <map>
#include "Program.h"
#include "mapi/common.h"


class RenderProgram
{
private:

	// ATTRIBUTES //

	std::vector<Program*> shaders;

	std::map<std::string, unsigned int> varList;


public:
	virtual ~RenderProgram() = default;

	// CONSTRUCTOR //

	RenderProgram();


	// GETTERS && SETTERS //

	std::vector<Program*> getShaders() { return this->shaders; }
	std::map<std::string, unsigned int> varList() { return this->varList; }

	void setShaders(std::vector<Program*> shaders) { this->shaders = shaders; }
	void setVarList(std::map<std::string, unsigned int> varList) { this->varList = varList; }


	// METHODS && FUNCTIONS //

	virtual void addProgram(std::string fileName) = 0;
	virtual void linkProgram() = 0;
	virtual void use() = 0;
	virtual void checkLinkerErrors() = 0;

	virtual void setVertexAttrib(std::string name, GLsizei stride, void* offset, GLint count, GLenum type) = 0;
	virtual void setInt(std::string name, int val) = 0;
	virtual void setFloat(std::string name, float val) = 0;
	virtual void setVec3(std::string name, const glm::vec3& vec) = 0;
	virtual void setVec4(std::string name, const glm::vec4& vec) = 0;
	virtual void setMatrix(std::string name, const glm::mat4& matrix) = 0;
};