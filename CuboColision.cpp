/*
 * cubo.cpp
 *
 *  Created on: Nov 6, 2015
 *      Author: francisco
 */
#include "CuboColision.h"
#include "contorno.h"

CuboColision::CuboColision() {
	// TODO Auto-generated constructor stub

}

CuboColision::~CuboColision() {
	// TODO Auto-generated destructor stub
}
void CuboColision::Render() {
	Color c = this->getRgb();
	Vector3D p = this->getPos();
	glPushMatrix();
	glColor3f(c.getRedComponent(), c.getGreenComponent(), c.getBlueComponent());
	glTranslatef(p.getCoordinateX(), p.getCoordinateY(), p.getCoordinateZ());
	glutSolidCube(getS());
	glPopMatrix();
}
inline Contorno* CuboColision::getContorno() {
	return new Contorno(this->getPos(), this->getS());
}
inline bool CuboColision::colision(Solid* s) {
	Contorno* c = s->getContorno();
	return c->colision(this);
}
