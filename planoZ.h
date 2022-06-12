/*
 * planoZ.h
 *
 *  Created on: Nov 7, 2015
 *      Author: francisco
 */
#pragma once
#include "plano.h"

class PlanoZ : public Plano {
public:
	float p;
	float s;
public:
	PlanoZ(float p = 0, float s = 100) :Plano(Vector3D(0, 0, 1), Vector3D(0, 0, -p)), p(p), s(s) { this->setRgb(Color(0.2, 0.2, 0)); }
	virtual ~PlanoZ();
	void Render();
	inline void resuelveColision(Solid* s) {
		std::cout << "boss impactado impacto en plano z"<< endl;
		Vector3D v = s->getSpeed();
		float vz = v.getCoordinateZ();
		vz *= -1;
		v.setCoordnateZ(vz);
	}
};

