/***************************
Materia:Gráficas Computacionales Gráficas
Fecha: 02/10/2017
Autor: A01167344 Jorge Luis Alvarado Durán
*****************************/
#pragma once

#include <string>
#include <GL/glew.h>
#include <GL/freeglut.h>

class Texture2D
{
public:
	Texture2D();
	~Texture2D();

	void Bind();
	void Unbind();

	void LoadTexture(std::string path);
	void LoadTexture(GLint format, GLsizei width, GLsizei height, const void* pixels);
private:
	GLuint _textureId;
};