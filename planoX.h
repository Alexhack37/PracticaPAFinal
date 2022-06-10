/*
 * Plano.h
 *
 *  Created on: Oct 5, 2015
 *      Author: francisco
 */
#pragma once
#include "plano.h"
class PlanoX : public Plano{
public:
	float p;
	float s;
public:
	PlanoX(float p = 0, float s = 100) :Plano(Vector3D(1, 0, 0), Vector3D(-p, 0, 0)), p(p), s(s) { this->setRgb(Color(1, 1, 1)); }
	virtual ~PlanoX();
	void Render();
	void resuelveColision(Solid* s) {
		Vector3D v = s->getSpeed();
		float vx = v.getCoordinateX();
		vx *= -1;
		v.setCoordnateX(vx);
	}
};

