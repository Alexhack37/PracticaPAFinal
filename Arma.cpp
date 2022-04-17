#include "Arma.h"
#include <iostream>


void Arma::Render() {

	glPushMatrix();
	glTranslatef(this->getPos().getCoordinateX(), this->getPos().getCoordinateY(), this->getPos().getCoordinateZ());
	glColor3f(this->getRgb().getRedComponent(), this->getRgb().getGreenComponent(), this->getRgb().getBlueComponent());
	glRotatef(this->getAngulo().getCoordinateX(), 1.0, 0.0, 0.0);
	glRotatef(this->getAngulo().getCoordinateY(), 0.0, 1.0, 0.0);
	glRotatef(this->getAngulo().getCoordinateZ(), 0.0, 0.0, 1.0);
	glScalef(this->getLongit(), this->getHeight(), this->getWidth());
	glutSolidCube(1);
	glPopMatrix();

}
void Arma ::ProcessMouseMovement(int x, int y)
{
	if (this->GetMouseX() >= 0 && this->GetMouseY() >= 0)
	{
		Vector3D orientation = this->getAngulo().Add(Vector3D(-(y - this->GetMouseY()),
			-(x - this->GetMouseX()), 0));
		this->setAngulo(orientation);
	}
	this->SetMouseX(x);
	this->SetMouseY(y);
}
void Arma::Dispara() {
	std::cout << "Se ha disparado"<< std::endl;
	if (this->getShootMode() == 0) {
		std::cout << "Un disparo normal" << std::endl;
	}
	else if(this->getShootMode() == 1) {
		std::cout << "Un disparo instantaneo" << std::endl;
	}
	else if(this->getShootMode() == 2) {
		std::cout << "En area" << std::endl;
	}
	else if(this->getShootMode() == 3) {
		std::cout << "Un disparo BFG" << std::endl;
	}
}
