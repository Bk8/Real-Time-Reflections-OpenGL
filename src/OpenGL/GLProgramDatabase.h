#pragma once

#include <string>
#include <map>
#include <gl3w/gl3w.h>

#include "GLProgram.h"
#include "Programs/GLProgram_Material.h"
#include "Programs/GLProgram_White.h"
#include "../GlobalValues.h"

class GLProgramDatabase
{
public:
	GLProgramDatabase();
	~GLProgramDatabase();

	GLProgram* loadProgram(std::string programType);
	

	static std::string TYPE_WHITE;
	static std::string TYPE_MATERIAL;

private:
	GLProgram* findProgram(std::string programType);
	GLProgram* makeProgramByName(std::string name);
	std::pair<std::string, std::string> getShadersByType(std::string shaderType);
	std::map<std::string,GLProgram*> programMap;

	//Compiling shaders -- low level
	const char* GetShaderName(GLenum eShaderType);
	GLuint CreateShader(GLenum eShaderType,const std::string &strShaderFile, const std::string &strShaderName);
	GLuint LoadShader(GLenum eShaderType, const std::string &strShaderFilename);
	GLuint CreateProgram(const std::vector<GLuint> &shaderList);
};