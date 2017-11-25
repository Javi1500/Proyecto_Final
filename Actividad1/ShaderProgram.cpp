/***************************
Materia:Gráficas Computacionales Gráficas
Fecha: 02/10/2017
Autor: A01167344 Jorge Luis Alvarado Durán
*****************************/
#include "ShaderProgram.h"
#include "Shader.h"
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <iostream>

ShaderProgram::ShaderProgram() {
	_programHandle = 0;
}

ShaderProgram::~ShaderProgram() {
	DeleteProgram();
}

void ShaderProgram::CreateProgram() {

	_programHandle = glCreateProgram();
}

void ShaderProgram::AttachShader(std::string path, GLenum type) {
	std::unique_ptr<Shader> shader(new Shader);
	shader->CreateShader(path, type);
	_attachedShaders.push_back(std::move(shader));

}

void ShaderProgram::LinkProgram() {
	for (size_t i = 0; i < _attachedShaders.size(); i++)
		glAttachShader(_programHandle, _attachedShaders[i]->GetHandle());
	glLinkProgram(_programHandle);
	GLint linkSuccess = 0;
	glGetProgramiv(_programHandle, GL_LINK_STATUS, &linkSuccess);
	if (linkSuccess == GL_FALSE)
	{
		GLint logLength = 0;
		glGetProgramiv(_programHandle, GL_INFO_LOG_LENGTH, &logLength);
		if (logLength > 0)
		{
			std::vector<GLchar> linkLog(logLength);
			glGetProgramInfoLog(_programHandle, logLength, &logLength, &linkLog[0]);
			for (size_t i = 0; i < linkLog.size(); i++)
				std::cout << linkLog[i];
			std::cout << std::endl;
		}
		DeleteProgram();
		return;
	}
	DeleteAndDetachShaders();
}

void ShaderProgram::Activate() {
	glUseProgram(_programHandle);
}

void ShaderProgram::Deactivate() {
	glUseProgram(0);
}

void ShaderProgram::SetAttribute(GLuint locationIndex, std::string name) {
	glBindAttribLocation(_programHandle, locationIndex, (const GLchar*)name.c_str());

}

void ShaderProgram::SetUniformi(std::string name, int x) {
	GLint uniformLocation = glGetUniformLocation(_programHandle, name.c_str());
	glUniform1i(uniformLocation, x);
}

void ShaderProgram::SetUniformf(std::string name, float x) {
	GLint uniformLocation = glGetUniformLocation(_programHandle, name.c_str());
	glUniform1f(uniformLocation, x);
}

void ShaderProgram::SetUniformf(std::string name, float x, float y) {
	GLint uniformLocation = glGetUniformLocation(_programHandle, name.c_str());
	glUniform2f(uniformLocation, x, y);
}

void ShaderProgram::SetUniformf(std::string name, float x, float y, float z) {
	GLint uniformLocation = glGetUniformLocation(_programHandle, name.c_str());
	glUniform3f(uniformLocation, x, y, z);
}

void ShaderProgram::SetUniformf(std::string name, float x, float y, float z, float w) {
	GLint uniformLocation = glGetUniformLocation(_programHandle, name.c_str());
	glUniform4f(uniformLocation, x, y, z, w);
}

void ShaderProgram::SetUniformMatrix(std::string name, glm::mat3 matrix) {
	GLint uniformLocation = glGetUniformLocation(_programHandle, name.c_str());
	glUniformMatrix3fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(matrix));
}

void ShaderProgram::SetUniformMatrix(std::string name, glm::mat4 matrix) {
	GLint uniformLocation = glGetUniformLocation(_programHandle, name.c_str());
	glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(matrix));
}

void ShaderProgram::DeleteAndDetachShaders() {

	for (auto &sh : _attachedShaders) {
		glDetachShader(_programHandle, sh->GetHandle());
		glDeleteShader(sh->GetHandle());
	}
	_attachedShaders.erase(_attachedShaders.begin(), _attachedShaders.end()); //
}

void ShaderProgram::DeleteProgram() {
	DeleteAndDetachShaders();
	glDeleteProgram(_programHandle);
}