#pragma once
#include "Model.h"
#include "Solid.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class ModelLoader : Model
{

private:
	float scala;
	Model modelo;
	vector<Vector3D> vertices;
	vector<Vector3D>  normales;

	vector<Color>  colores;

	float xMin, yMin, zMin, xMax, yMax, zMax;

	float getWidth();
	float getHeight();
	float getLength();
	void calcBoundaries(Vector3D lastVertex);

	Triangle Center(Triangle triangle);
	Vector3D parseObjLineToVector3D(const string& archObj);
	Triangle parseObjTriangle(const string& archObj);
public:

	ModelLoader():scala(3.0f), xMin(0.0f), yMin(0.0f) , zMin(0.0f) , xMax(0.0f), yMax(0.0f), zMax(0.0f) {}

	inline Model GetModel() const { return this->modelo; }

	inline float GetScala() const { return this->scala; }
	inline void setScala(const  float& scalaToSet) { this->scala = scalaToSet; }


	void LoadModel(const string& pathobj);
	void Clear();
	

	//pregunta 6.c.1 los elementos del codigo relacionado con el tratamiento de excepciones es el try catch y un if else que avisa si no se pudo abrir el archivo. Mas seguridad y estabilidad, "Excepcion al procesar el archivo"
	// y da un  error Exception ex. Si no existiera un modelo el programa pondira null en algunaas ubicaciones de memoria causando un error.

	// pregunta 6.c.2 el ifstream representa un flujo de caracteres provenientes de un archivo de entrada. Usamos ofstream para representar un flujo de caracteres que van a un archivo de salida. Asocia un obeto a objFile y mientras exista (o tenga lineas) asigna vertices color y normales
	//hay que cerrarlo despies de usarlo

	//pregunta 6.c.3  Clase de flujo de entrada para operar en cadenas. nos permite poder trabajar con cadenas. Los caracteres de la secuencia se pueden extraer de la cadena mediante cualquier operación permitida en las input streams. 
};

