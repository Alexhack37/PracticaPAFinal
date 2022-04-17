#include "FinalBoss.h"
void FinalBoss::Render() {

	glPushMatrix();
	glTranslatef(this->getPos().getCoordinateX(), this->getPos().getCoordinateY(), this->getPos().getCoordinateZ());
	glColor3f(this->getRgb().getRedComponent(), this->getRgb().getGreenComponent(), this->getRgb().getBlueComponent());
	glRotatef(this->getAngulo().getCoordinateX(), 1.0, 0.0, 0.0);
	glRotatef(this->getAngulo().getCoordinateY(), 0.0, 1.0, 0.0);
	glRotatef(this->getAngulo().getCoordinateZ(), 0.0, 0.0, 1.0);
	//glScalef(this->getSize());
	glutSolidOctahedron();
	glPopMatrix();

}