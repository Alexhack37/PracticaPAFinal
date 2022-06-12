#include "FinalBoss.h"
//void FinalBoss::Render() {
//	glPushMatrix();
//	glTranslatef(this->getPos().getCoordinateX(), this->getPos().getCoordinateY(), this->getPos().getCoordinateZ());
//	glColor3f(this->getRgb().getRedComponent(), this->getRgb().getGreenComponent(), this->getRgb().getBlueComponent());
//	glRotatef(this->getAngulo().getCoordinateX(), 1.0, 0.0, 0.0);
//	glRotatef(this->getAngulo().getCoordinateY(), 0.0, 1.0, 0.0);
//	glRotatef(this->getAngulo().getCoordinateZ(), 0.0, 0.0, 1.0);
//
//	for (Triangle& t : triangulos)
//		t.Render();
//	//Por cada(Triangulo t en triángulos) t.Render();
//
//	glPopMatrix();
//}
void FinalBoss::resuelveColision(Solid* s)
{

	float vidaActual = this->getVida();
	this->setVida(vidaActual - 10);
	std::cout << "boss impactado " << "Ahora tiene " << this->getVida() << " puntos restantes" << endl;
}