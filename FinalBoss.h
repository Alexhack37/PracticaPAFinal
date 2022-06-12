#pragma once
#include <GL/glut.h>
#include "Vector3D.h"
#include "Color.h"
#include "Model.h"

class FinalBoss : public Model
{
private:
	float vida;
public:


	FinalBoss() {
		vida = 50;

	}

	inline float getVida() const { return this->vida; }
	inline void  setVida(const  float& VidaToSet) { this->vida = VidaToSet; }

	//inline vector get

	//void Render();

	void resuelveColision(Solid* s);
};



