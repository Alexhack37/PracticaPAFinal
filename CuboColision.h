/*
 * cubo.h
 *
 *  Created on: Nov 6, 2015
 *      Author: francisco
 */
#pragma once
#include "Solid.h"
class CuboColision : public Solid{
	float s;
public:
	CuboColision();
	CuboColision(Vector3D p, float s = 1) :Solid(p), s(s) {}
	virtual ~CuboColision();
	void Render();
	inline float getS() { return s; }
	inline void setS(float s) { this->s = s; }
	inline Contorno* getContorno();
	inline bool colision(Solid* s);
};

