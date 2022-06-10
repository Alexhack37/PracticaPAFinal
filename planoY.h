/*
 * planoY.h
 *
 *  Created on: Nov 6, 2015
 *      Author: francisco
 */

#include "plano.h"

class PlanoY : public Plano {
	float p;
	float s;
public:
	PlanoY(float p = 0, float s = 100) :Plano(Vector3D(0, 1, 0), Vector3D(0, -p, 0)), p(p), s(s) { this->setRgb(Color(0.5, 1, 0.5)); }
	virtual ~PlanoY();
	void Render();
	void resuelveColision(Solid* s) {
		Vector3D v = s->getSpeed();
		float vy = v.getCoordinateY();
		vy *= -1;
		v.setCoordnateY(vy);
	}
};
