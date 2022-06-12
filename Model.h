#pragma once
#include "Solid.h"
#include "Triangle.h"
#include <vector>
using namespace std;

class Model: public Solid
{
private:

	float escala;

	

	float puntos;

public:

	vector<Triangle> triangulos;

	inline float getPuntos() const { return this->puntos; }
	inline void setPuntos(const  float& puntosToSet) { this->puntos = puntosToSet; }

	inline float GetScala() const { return this->escala; }
	inline void setScala(const  float& scalaToSet) { this->escala = scalaToSet; }

	void AddTriangle(Triangle triangle);
	void Clear();
	void PaintColor(Color color);
	void Render();

	Contorno* getContorno();
	bool colision(Solid* s);
	void resuelveColision(Solid* s);

	
};

