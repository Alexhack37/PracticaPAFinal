#pragma once
#include <GL/glut.h>
#include "Vector3D.h"
#include "Color.h"
#include "Solid.h"

#include "Model.h"
#include "ModelLoader.h"
class Tarta: public Solid
{
private:


	float puntos;
	float scala;


public:

	Tarta(Vector3D position = Vector3D(0.0, 0.0, 0.0),
		Vector3D orientation = Vector3D(0.0, 0.0, 0.0),
		Color    rgb = Color(0.0, 0.0, 0.0),
		Vector3D vectorRotacion = Vector3D(0.0, 0.0, 0.0),
		Vector3D vectorDesplazamiento = Vector3D(0.0, 0.0, 0.0),
		float puntos = 0.0f, float scala = 4.0f,
		int identificacion = 0)
		:Solid{ position, orientation, rgb, vectorRotacion, vectorDesplazamiento, identificacion },
		puntos{ puntos }, scala(scala){}


	inline float getPuntos() const { return this->puntos; }
	inline void setPuntos(const  float& puntosToSet) { this->puntos = puntosToSet; }


	inline float getScala() const { return this->scala; }
	inline void setScala(const  float& scalaToSet) { this->scala = scalaToSet; }

	void SpawnerTarta();
	void Render();
};

