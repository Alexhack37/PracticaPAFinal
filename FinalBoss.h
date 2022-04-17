#pragma once
#include <GL/glut.h>
#include "Vector3D.h"
#include "Color.h"
#include "Solid.h"
class FinalBoss : public Solid
{
private:


	float vida;
	float size;
public:


	FinalBoss(Vector3D position = Vector3D(0.0, 0.0, 0.0),
		Vector3D orientation = Vector3D(0.0, 0.0, 0.0),
		Color rgb = Color(0.0, 0.0, 0.0),
		Vector3D vectorRotacion = Vector3D(0.0, 0.0, 0.0),
		Vector3D vectorDesplazamiento = Vector3D(0.0, 0.0, 0.0), float size = 0.0f, float vida = 10.0f)
		:Solid{ position, orientation, rgb, vectorRotacion, vectorDesplazamiento },size(size), vida(vida){}


	inline float getVida() const { return this->vida; }
	inline void  setVida(const  float& VidaToSet) { this->vida = VidaToSet; }

	inline float getSize() const { return this->size; }
	inline void  setSize(const  float& SizeToSet) { this->size = SizeToSet; }


	void Render();
};



