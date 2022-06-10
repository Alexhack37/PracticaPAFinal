/*
 * Esfera.cpp
 *
 *  Created on: Oct 5, 2015
 *      Author: francisco
 */
#include "EsferaColision.h"
#include "contorno.h"

EsferaColision::EsferaColision() {
	// TODO Auto-generated constructor stub

}

EsferaColision::~EsferaColision() {
	// TODO Auto-generated destructor stub
}

void EsferaColision::Render() {
	Color c = this->getRgb();
	Vector3D p = this->getPos();
	glPushMatrix();
	glColor3f(c.getRedComponent(), c.getGreenComponent(), c.getBlueComponent());
	glTranslatef(p.getCoordinateX(), p.getCoordinateY(), p.getCoordinateZ());
	glutSolidSphere(getR(), 10, 10);
	glPopMatrix();
}
inline Contorno* EsferaColision::getContorno() {
	return new Contorno(getPos(), getR());
}
inline bool EsferaColision::colision(Solid* s) {
	Contorno* c = s->getContorno();
	return c->colision(this);
}