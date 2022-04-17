#pragma once
#include "Solid.h"
#include "Triangle.h"
#include <vector>
using namespace std;

class Model: public Solid
{
private:

	vector<Triangle> triangulos;

	float puntos;

public:


	inline float getPuntos() const { return this->puntos; }
	inline void setPuntos(const  float& puntosToSet) { this->puntos = puntosToSet; }

	void AddTriangle(Triangle triangle);
	void Clear();
	void PaintColor(Color color);
	void Render();


	
};

