#include "Proyectil.h"
#include "Arma.h"
#include "contorno.h"

void Proyectil::Render() {

	glPushMatrix();
	glTranslatef(this->getPos().getCoordinateX(), this->getPos().getCoordinateY(), this->getPos().getCoordinateZ());
	glColor3f(this->getRgb().getRedComponent(), this->getRgb().getGreenComponent(), this->getRgb().getBlueComponent());
	glRotatef(this->getAngulo().getCoordinateX(), 1.0, 0.0, 0.0);
	glRotatef(this->getAngulo().getCoordinateY(), 0.0, 1.0, 0.0);
	glRotatef(this->getAngulo().getCoordinateZ(), 0.0, 0.0, 1.0);
	//glutSolidSphere(this->getRadio(),this->getSlices(), this->getSlacks());
	glutSolidSphere(this->getRadio(), this->getSlices(), this->getStacks());
	glPopMatrix();

}

void Proyectil::resuelveColision(Solid* s)
{
	std::cout << "colision proyectil" << endl;
}

Contorno* Proyectil::getContorno() {
	return new Contorno(getPos(), getRadio());
}
bool Proyectil::colision(Solid* s) {
	Contorno* c = s->getContorno();
	return c->colision(this);
}

 