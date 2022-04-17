#include "Mira.h"
#include <iostream>


void Mira::Render() {
	if (this->modoMira) {
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
}
void Mira::ProcessMouseMovement(int x, int y)
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
void Mira::CambiarScope()
{
	if (this->modoMira) {
		this->setScopeMode(false);
	}
	else {
		this->setScopeMode(true);
	}
}
