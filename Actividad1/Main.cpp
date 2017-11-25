/***************************
Materia:Gráficas Computacionales Gráficas
Fecha: 02/10/2017
Autor: A01167344 Jorge Luis Alvarado Durán
*****************************/
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include "Transform.h"
#include "Mesh.h"
#include "ShaderProgram.h"
#include "Camera.h"
#include <iostream>
#include <vector>
#include <IL/il.h>
#include "Texture2D.h"
#include "DepthBuffer.h"

Mesh _mesh, _mesh1;
ShaderProgram _shaderProgram,_shaderProgram1;
Transform _transform, _transform1, _dedo1,_dedo2,_dedo3,_dedo4,_dedo5, _dedo6, _dedo7, _dedo8;
Camera _camera, _camara1;
Texture2D _myTexture, _myTexture1;
DepthBuffer _depthBuffer;
float t = 0.0f, t1= 0.3f;

void Initialize() {
	//Vector de posiciones para la palma de la mano
	std::vector<glm::vec3> positions;
	//principal
	positions.push_back(glm::vec3(-2.5f, -3.5f, 0.3f));
	positions.push_back(glm::vec3(2.5f, -3.5f, 0.3f));
	positions.push_back(glm::vec3(-2.5f, -3.5f, -0.3f));
	positions.push_back(glm::vec3(2.5f, -3.5f, -0.3f));//

	positions.push_back(glm::vec3(-2.5f, -3.5f, 0.3f));
	positions.push_back(glm::vec3(-2.5f, 3.5f, 0.3f));
	positions.push_back(glm::vec3(2.5f, -3.5f, 0.3f));
	positions.push_back(glm::vec3(2.5f, 3.5f, 0.3f));//

	positions.push_back(glm::vec3(-2.5f, 3.5f, -0.3f));
	positions.push_back(glm::vec3(2.5f, 3.5f, -0.3f));
	positions.push_back(glm::vec3(-2.5f, 3.5f, 0.3f));
	positions.push_back(glm::vec3(2.5f, 3.5f, 0.50f));//

	positions.push_back(glm::vec3(-2.5f, -3.5f, -0.3f));
	positions.push_back(glm::vec3(2.5f, -3.5f, -0.3f));
	positions.push_back(glm::vec3(-2.5f, 3.5f, -0.3f));
	positions.push_back(glm::vec3(2.5f, 3.5f, -0.3f));//

	positions.push_back(glm::vec3(-2.5f, 3.5f, 0.3f));
	positions.push_back(glm::vec3(-2.5f, -3.5f, 0.3f));
	positions.push_back(glm::vec3(-2.5f, 3.5f, -0.3f));
	positions.push_back(glm::vec3(-2.5f, -3.5f, -0.3f));

	positions.push_back(glm::vec3(2.5f, -3.5f, -0.3f));
	positions.push_back(glm::vec3(2.5f, -3.5f, 0.3f));
	positions.push_back(glm::vec3(2.5f, 3.5f, -0.3f));
	positions.push_back(glm::vec3(2.5f, 3.5f, 0.3f));

	std::vector<glm::vec3> positions1;
	//Posiciones para las falanges
	positions1.push_back(glm::vec3(-0.5f, -1.2, 0.3f));
	positions1.push_back(glm::vec3(0.5f, -1.2, 0.3f));
	positions1.push_back(glm::vec3(-0.5f, -1.2, -0.3f));
	positions1.push_back(glm::vec3(0.5f, -1.2, -0.3f));

	positions1.push_back(glm::vec3(-0.5f, -1.2, 0.3f));
	positions1.push_back(glm::vec3(-0.5f, 1.2, 0.3f));
	positions1.push_back(glm::vec3(0.5f, -1.2, 0.3f));
	positions1.push_back(glm::vec3(0.5f, 1.2, 0.3f));

	positions1.push_back(glm::vec3(-0.5f, 1.2, -0.3f));
	positions1.push_back(glm::vec3(0.5f, 1.2, -0.3f));
	positions1.push_back(glm::vec3(-0.5f, 1.2, 0.3f));
	positions1.push_back(glm::vec3(0.5f, 1.2, 0.3f));

	positions1.push_back(glm::vec3(-0.5f, -1.2, -0.3f));
	positions1.push_back(glm::vec3(0.5f, -1.2, -0.3f));
	positions1.push_back(glm::vec3(-0.5f, 1.2, -0.3f));
	positions1.push_back(glm::vec3(0.5f, 1.2, -0.3f));

	positions1.push_back(glm::vec3(-0.5f, 1.2, 0.3f));
	positions1.push_back(glm::vec3(-0.5f, -1.2, 0.3f));
	positions1.push_back(glm::vec3(-0.5f, 1.2, -0.3f));
	positions1.push_back(glm::vec3(-0.5f, -1.2, -0.3f));

	positions1.push_back(glm::vec3(0.5f, -1.2, -0.3f));
	positions1.push_back(glm::vec3(0.5f, -1.2, 0.3f));
	positions1.push_back(glm::vec3(0.5f, 1.2, -0.3f));
	positions1.push_back(glm::vec3(0.5f, 1.2, 0.3f));

	
	//Normales
	std::vector<glm::vec3> normals;
	normals.push_back(glm::vec3(0.0f, -1.0f, 0.0f));
	normals.push_back(glm::vec3(0.0f, -1.0f, 0.0f));
	normals.push_back(glm::vec3(0.0f, -1.0f, 0.0f));
	normals.push_back(glm::vec3(0.0f, -1.0f, 0.0f));//

	normals.push_back(glm::vec3(0.0f, 0.0f, 1));//
	normals.push_back(glm::vec3(0.0f, 0.0f, 1));
	normals.push_back(glm::vec3(0.0f, 0.0f, 1));
	normals.push_back(glm::vec3(0.0f, 0.0f, 1));

	normals.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	normals.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	normals.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	normals.push_back(glm::vec3(0.0f, 1.0f, 0.0f));//

	normals.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
	normals.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
	normals.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
	normals.push_back(glm::vec3(0.0f, 0.0f, -1.0f));//

	normals.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
	normals.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
	normals.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
	normals.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));

	normals.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	normals.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	normals.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	normals.push_back(glm::vec3(1.0f, 0.0f, 0.0f));

	//Vector de texturas
	std::vector<glm::vec2> texturas;
	texturas.push_back(glm::vec2(1.0f, 0.0f));  
	texturas.push_back(glm::vec2(0.0f, 0.0f));
	texturas.push_back(glm::vec2(1.0f, 1.0f)); 
	texturas.push_back(glm::vec2(1.0f, 0.0f));
	texturas.push_back(glm::vec2(1.0f, 0.0f));
	texturas.push_back(glm::vec2(0.0f, 0.0f));
	texturas.push_back(glm::vec2(1.0f, 1.0f));
	texturas.push_back(glm::vec2(1.0f, 0.0f)); 
	texturas.push_back(glm::vec2(1.0f, 0.0f));
	texturas.push_back(glm::vec2(0.0f, 0.0f));
	texturas.push_back(glm::vec2(1.0f, 1.0f));
	texturas.push_back(glm::vec2(1.0f, 0.0f)); 
	texturas.push_back(glm::vec2(1.0f, 0.0f));
	texturas.push_back(glm::vec2(0.0f, 0.0f));
	texturas.push_back(glm::vec2(1.0f, 1.0f));
	texturas.push_back(glm::vec2(1.0f, 0.0f)); 
	texturas.push_back(glm::vec2(1.0f, 0.0f));
	texturas.push_back(glm::vec2(0.0f, 0.0f));
	texturas.push_back(glm::vec2(1.0f, 1.0f));
	texturas.push_back(glm::vec2(1.0f, 0.0f)); 
	texturas.push_back(glm::vec2(1.0f, 0.0f));
	texturas.push_back(glm::vec2(0.0f, 0.0f));
	texturas.push_back(glm::vec2(1.0f, 1.0f));
	texturas.push_back(glm::vec2(1.0f, 0.0f));

	//Los índices son ingresados en el orden en el que se dibujarán
	std::vector<unsigned int> indices = { 0,2,3,3,1,0, 5,4,6,6,7,5, 8,10,11,11,9,8, 15,13,12,12,14,15, 18,19,17,17,16,18, 23,21,20,20, 22, 23 };

	std::vector<glm::vec3> colors;
	/*colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.5f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.5f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.5f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.5f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 0.5f, 0.5f));
	colors.push_back(glm::vec3(1.0f, 0.5f, 0.5f));
	colors.push_back(glm::vec3(1.0f, 0.5f, 0.5f));
	colors.push_back(glm::vec3(1.0f, 0.5f, 0.5f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.5f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.5f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.5f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.5f));*/

	//buffer de profundidad
	_depthBuffer.Create(2052);

	_mesh.SetIndices(indices, GL_STATIC_DRAW);
	_mesh.CreateMesh(24);
	_mesh.SetPositionAttribute(positions, GL_STATIC_DRAW, 0);
	_mesh.SetColorAttribute(colors, GL_STATIC_DRAW, 1);
	_mesh.SetIndices(indices, GL_STATIC_DRAW);
	_mesh.SetNormalAttribute(normals, GL_STATIC_DRAW, 2);
	_mesh.SetTexCoordAttribute(texturas, GL_STATIC_DRAW, 3);

	_mesh1.SetIndices(indices, GL_STATIC_DRAW);
	_mesh1.CreateMesh(24);
	_mesh1.SetPositionAttribute(positions1, GL_STATIC_DRAW, 0);
	_mesh1.SetColorAttribute(colors, GL_STATIC_DRAW, 1);
	_mesh1.SetIndices(indices, GL_STATIC_DRAW);
	_mesh1.SetNormalAttribute(normals, GL_STATIC_DRAW, 2);
	_mesh1.SetTexCoordAttribute(texturas, GL_STATIC_DRAW, 3);

	_shaderProgram.CreateProgram();
	_shaderProgram.AttachShader("Shadow.vert", GL_VERTEX_SHADER);
	_shaderProgram.AttachShader("Shadow.frag", GL_FRAGMENT_SHADER);
	_shaderProgram.SetAttribute(0, "VertexPosition");
	_shaderProgram.SetAttribute(1, "VertexColor");
	_shaderProgram.SetAttribute(2, "VertexNormal");
	_shaderProgram.SetAttribute(3, "VertexTexCoord");

	_shaderProgram1.CreateProgram();
	_shaderProgram1.AttachShader("Default.frag", GL_FRAGMENT_SHADER);
	_shaderProgram1.AttachShader("Default.vert", GL_VERTEX_SHADER);
	_shaderProgram1.SetAttribute(0, "VertexPosition");
	_shaderProgram.LinkProgram();
	_shaderProgram1.LinkProgram();

	//Palma
	_transform.MoveUp(-4, true);
	_transform.Rotate(-60.0f, 0.00f, 0.0f, true);

	//Piso
	_transform1.SetScale(200, .6, 200);
	_transform1.MoveUp(-10, true);

	//Posicion de los dedos
	_dedo1.MoveRight(-1.8, true);
	_dedo1.MoveUp(5.3f, true);
	_dedo2.MoveUp(5.3f, true);
	_dedo3.MoveUp(5.3f, true);
	_dedo3.MoveRight(2.0, true);
	_dedo4.Rotate(0, 0, -90, true);//Pulgar
	_dedo4.MoveRight(4.1f, true);

	//Abajo separación
	_dedo4.MoveUp(-2.5f, true);
	_dedo5.MoveUp(2.5f, true);
	_dedo6.MoveUp(2.5f, true);
	_dedo7.MoveUp(2.5f, true);
	_dedo8.MoveUp(2.5f, true);

	_camera.MoveForward(25.0f);
	_camara1.SetOrthographic(90.0f, 1);
	_camara1.Pitch(-100);
	_camara1.SetPosition(0, 60, -30);

	//Texturas
	_myTexture.LoadTexture("caja.jpg");
	_myTexture1.LoadTexture("piso.jpg");
}

void Idle() {
	glutPostRedisplay();
}

void GameLoop() {

	_depthBuffer.Bind();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (t >= 110.0f || t < 0.0f) {
		t1 *= -1;
	}
	t += t1;

	_dedo1.MoveForward(t1 / 50, false);
	_dedo1.Rotate(t1, 0, 0.0f, false);
	_dedo2.MoveForward(t1 / 50, false);
	_dedo2.Rotate(t1, 0, 0.0f, false);
	_dedo3.MoveForward(t1 / 50, false);
	_dedo3.Rotate(t1, 0, 0.0f, false);
	_dedo4.MoveForward(t1 / 50, false);
	_dedo4.Rotate(t1, 0, 0.0f, false);
	_dedo5.MoveForward(t1 / 50, false);
	_dedo5.Rotate(t1, 0, 0.0f, false);
	_dedo6.MoveForward(t1 / 50, false);
	_dedo6.Rotate(t1, 0, 0.0f, false);
	_dedo7.MoveForward(t1 / 50, false);
	_dedo7.Rotate(t1, 0, 0.0f, false);
	_dedo8.MoveForward(t1 / 50, false);
	_dedo8.Rotate(t1, 0, 0.0f, false);

	//Rotación de la mano
	_transform.Rotate(0.0f, 0.12f, 0.0f, true);
		
	_shaderProgram1.Activate();	
	_shaderProgram1.SetUniformMatrix("mvpMatrix", _camara1.GetViewProjection()*_transform.GetModelMatrix());
	_mesh.Draw(GL_TRIANGLES);
	_shaderProgram1.SetUniformMatrix("mvpMatrix", _camara1.GetViewProjection()* _transform1.GetModelMatrix());
	_mesh.Draw(GL_TRIANGLES);
	_shaderProgram1.SetUniformMatrix("mvpMatrix", _camara1.GetViewProjection()*_transform.GetModelMatrix()*_dedo1.GetModelMatrix());
	_mesh1.Draw(GL_TRIANGLES); 
	_shaderProgram1.SetUniformMatrix("mvpMatrix", _camara1.GetViewProjection()*_transform.GetModelMatrix()*_dedo2.GetModelMatrix());
	_mesh1.Draw(GL_TRIANGLES); 
	_shaderProgram1.SetUniformMatrix("mvpMatrix", _camara1.GetViewProjection()*_transform.GetModelMatrix()*_dedo3.GetModelMatrix());
	_mesh1.Draw(GL_TRIANGLES); 
	_shaderProgram1.SetUniformMatrix("mvpMatrix", _camara1.GetViewProjection()*_transform.GetModelMatrix()*_dedo4.GetModelMatrix());
	_mesh1.Draw(GL_TRIANGLES); 
	_shaderProgram1.SetUniformMatrix("mvpMatrix", _camara1.GetViewProjection()*_transform.GetModelMatrix()*_dedo1.GetModelMatrix()*_dedo5.GetModelMatrix());
	_mesh1.Draw(GL_TRIANGLES); 
	_shaderProgram1.SetUniformMatrix("mvpMatrix", _camara1.GetViewProjection()*_transform.GetModelMatrix()*_dedo2.GetModelMatrix()*_dedo6.GetModelMatrix());
	_mesh1.Draw(GL_TRIANGLES); 
	_shaderProgram1.SetUniformMatrix("mvpMatrix", _camara1.GetViewProjection()*_transform.GetModelMatrix()*_dedo3.GetModelMatrix()*_dedo7.GetModelMatrix());
	_mesh1.Draw(GL_TRIANGLES); 
	_shaderProgram1.SetUniformMatrix("mvpMatrix", _camara1.GetViewProjection()*_transform.GetModelMatrix()*_dedo4.GetModelMatrix()*_dedo8.GetModelMatrix());
	_mesh1.Draw(GL_TRIANGLES); 

	_depthBuffer.Unbind();
	_shaderProgram1.Deactivate();
	glViewport(0, 0, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	_shaderProgram.Activate();
	_shaderProgram.SetUniformf("positionx", _camera.GetPosition()[0]);
	_shaderProgram.SetUniformf("positiony", _camera.GetPosition()[1]);
	_shaderProgram.SetUniformf("positionz", _camera.GetPosition()[2]);
	_shaderProgram.SetUniformf("x", 0);
	_shaderProgram.SetUniformf("y", .1);
	_shaderProgram.SetUniformf("z", -5);
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	_shaderProgram.SetUniformi("ShadowMap", 1);

	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _transform.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _camara1.GetViewProjection());
	glActiveTexture(GL_TEXTURE0);
	_myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.BindDepthMap();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	_myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.UnbindDepthMap();

	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix()*_dedo1.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _transform.GetModelMatrix()*_dedo1.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _camara1.GetViewProjection());
	glActiveTexture(GL_TEXTURE0);
	_myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.BindDepthMap();
	_mesh1.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	_myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.UnbindDepthMap();

	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix()*_dedo2.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _transform.GetModelMatrix()*_dedo2.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _camara1.GetViewProjection());
	glActiveTexture(GL_TEXTURE0);
	_myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.BindDepthMap();
	_mesh1.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	_myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.UnbindDepthMap();

	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix()*_dedo3.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _transform.GetModelMatrix()*_dedo3.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _camara1.GetViewProjection());
	glActiveTexture(GL_TEXTURE0);
	_myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.BindDepthMap();
	_mesh1.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	_myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.UnbindDepthMap();

	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix()*_dedo4.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _transform.GetModelMatrix()*_dedo4.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _camara1.GetViewProjection());
	glActiveTexture(GL_TEXTURE0);
	_myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.BindDepthMap();
	_mesh1.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	_myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.UnbindDepthMap();

	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix()*_dedo1.GetModelMatrix()*_dedo5.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _transform.GetModelMatrix()*_dedo1.GetModelMatrix()*_dedo5.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _camara1.GetViewProjection());
	glActiveTexture(GL_TEXTURE0);
	_myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.BindDepthMap();
	_mesh1.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	_myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.UnbindDepthMap();

	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix()*_dedo2.GetModelMatrix()*_dedo6.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _transform.GetModelMatrix()*_dedo2.GetModelMatrix()*_dedo6.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _camara1.GetViewProjection());
	glActiveTexture(GL_TEXTURE0);
	_myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.BindDepthMap();
	_mesh1.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	_myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.UnbindDepthMap();

	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix()*_dedo3.GetModelMatrix()*_dedo7.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _transform.GetModelMatrix()*_dedo3.GetModelMatrix()*_dedo7.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _camara1.GetViewProjection());
	glActiveTexture(GL_TEXTURE0);
	_myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.BindDepthMap();
	_mesh1.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	_myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.UnbindDepthMap();
	
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix()*_dedo4.GetModelMatrix()*_dedo8.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _transform.GetModelMatrix()*_dedo4.GetModelMatrix()*_dedo8.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _camara1.GetViewProjection());
	glActiveTexture(GL_TEXTURE0);
	_myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.BindDepthMap();
	_mesh1.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	_myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.UnbindDepthMap();

	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform1.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _transform1.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _camara1.GetViewProjection());
	glActiveTexture(GL_TEXTURE0);
	_myTexture1.Bind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.BindDepthMap();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	_myTexture1.Unbind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.UnbindDepthMap();

	_shaderProgram.Deactivate();
	glutSwapBuffers();
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	//version
	glutInitContextVersion(4, 0);

	glutInitContextProfile(GLUT_CORE_PROFILE);

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(600, 600);

	glutCreateWindow("Hello World GL");

	glutDisplayFunc(GameLoop);
	glutIdleFunc(Idle);

	glewInit();
	//Color de la pantalla
	glClearColor(1.0f, 1.0f, 0.5f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	// Inicializar DevIL
	ilInit();
	// Le decimos que queremos cambiar el punto de origen
	ilEnable(IL_ORIGIN_SET);
	// Configuramos el origen de las texturas cargadas por
	// DevIL como abajo a la izquierda
	ilOriginFunc(IL_ORIGIN_LOWER_LEFT);

	std::cout << glGetString(GL_VERSION) << std::endl;

	Initialize();

	glutMainLoop();

	return 0;
}