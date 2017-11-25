/***************************
Materia:Gráficas Computacionales Gráficas
Fecha: 02/10/2017
Autor: A01167344 Jorge Luis Alvarado Durán
*****************************/
#pragma once
#include <string>

class InputFile {
private:
	std::string _contents;

public:
	bool Read(std::string _fileName);
	std::string GetContents();
};