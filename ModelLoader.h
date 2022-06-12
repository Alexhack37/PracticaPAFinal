#pragma once
#include "Model.h"
#include "FinalBoss.h"
#include "Mercader.h"
#include "Solid.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class ModelLoader : public Model
{

private:
	//float scala;
	Model modelo;
	FinalBoss boss;
	Mercader mercader;
	vector<Vector3D> vertices;
	vector<Vector3D>  normales;

	vector<Color>  colores;

	float xMin, yMin, zMin, xMax, yMax, zMax;

	
	void calcBoundaries(Vector3D lastVertex);

	Triangle Center(Triangle triangle);
	Vector3D parseObjLineToVector3D(const string& archObj);
	Triangle parseObjTriangle(const string& archObj);
public:

	ModelLoader() {
		xMin = 0.0f;
		yMin = 0.0f;
		zMin = 0.0f;
		xMax = 0.0f;
		xMax = 0.0f;
		xMax = 0.0f;
	}

	inline Model GetModel() const { return this->modelo; }
	inline FinalBoss GetBoss() const { return this->boss; }
	inline Mercader GetModelMer() const { return this->mercader; }

	//inline float GetScala() const { return this->scala; }
	//inline void setScala(const  float& scalaToSet) { this->scala = scalaToSet; }
	float getWidth();
	float getHeight();
	float getLength();

	void LoadModel(const string& pathobj);
	void Clear();

	//Contorno* getContorno();
	//bool colision(Solid* s);
	//void resuelveColision(Solid* s);

};

