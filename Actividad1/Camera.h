/***************************
Materia:Gráficas Computacionales Gráficas
Fecha: 02/10/2017
Autor: A01167344 Jorge Luis Alvarado Durán
*****************************/
#pragma once
#include <glm/glm.hpp>
#include "Transform.h"

class Camera {

public:
	Camera();

	glm::mat4 GetViewProjection();
	glm::mat4 GetViewMatrix();
	glm::mat4 GetProjectionMatrix();
	glm::vec3 GetPosition();

	void SetPosition(float x, float y, float z);
	void SetRotation(float x, float y, float z);

	void MoveForward(float delta, bool world = false);
	void MoveUp(float delta, bool world = false);
	void MoveRight(float delta, bool world = false);
	//Rota LA CAMARA en el eje Y
	void Yaw(float degrees);
	//Rota la camara enel eje z
	void Roll(float degrees);
	//Rotacion de la camara en el eje x
	void Pitch(float degrees);
	void Rotate(float x, float y, float z, bool world = false);

	void SetPerspective(float nearPlane, float farPlane, float fieldOfView, float aspectRatio); //Camara 3d
	void SetOrthographic(float size, float aspectRatio); //camara 2d

private:
	Transform _transform;

	glm::mat4 _viewMatrix;
	glm::mat4 _projectionMatrix;

};