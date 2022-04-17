#include "Boton.h"



void Boton::Render() {

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
void Boton::botonPlaceHolder() {

		std::cout << "hola " << std::endl;
	
	//glutButtonBoxFunc(*Saludar(), boton1, estado);

	//glutAddMenuEntry();
}