/*
 * triangulo.cpp
 *
 *  Created on: Nov 12, 2015
 *      Author: francisco
 */
#include "Triangulo.h"
Triangulo::~Triangulo() {
	// TODO Auto-generated destructor stub
}
void Triangulo::Render() {
	Color c = this->getRgb();
	glColor3f(c.getRedComponent(), c.getGreenComponent(), c.getBlueComponent());
	Vector3D vn = this->getNormal();
	float vnx = vn.getCoordinateX();
	float vny = vn.getCoordinateY();
	float vnz = vn.getCoordinateZ();
	glBegin(GL_TRIANGLES);
	glNormal3f(vnx, vny, vnz);
	glVertex3f(p0.getCoordinateX(), p0.getCoordinateY(), p0.getCoordinateZ());
	glNormal3f(vnx, vny, vnz);
	glVertex3f(p1.getCoordinateX(), p1.getCoordinateY(), p1.getCoordinateZ());
	glNormal3f(vnx, vny, vnz);
	glVertex3f(p2.getCoordinateX(), p2.getCoordinateY(), p2.getCoordinateZ());
	glEnd();
}