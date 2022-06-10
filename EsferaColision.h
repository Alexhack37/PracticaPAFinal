#pragma once
/*
 * Esfera.h
 *
 *  Created on: Oct 5, 2015
 *      Author: francisco
 */
#include "Solid.h"

class EsferaColision : public Solid {
	float r;
public:
	EsferaColision();
	EsferaColision(Vector3D p, float r = 0.5) :Solid(p), r(r) {}
	virtual ~EsferaColision();
	void Render();
	inline float getR() const { return r; }
	inline void setR(float r) { this->r = r; }
	inline Contorno* getContorno();
	inline bool colision(Solid* s);
};

