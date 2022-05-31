#include "Triangle.h"


void Triangle::Render() {


	

	glBegin(GL_TRIANGLES);
	//vértice 1
	glColor3f(this->GetVcolor1().getRedComponent(), this->GetVcolor1().getGreenComponent(), this->GetVcolor1().getBlueComponent());
	glNormal3f(this->GetNormal1().getCoordinateX(), this->GetNormal1().getCoordinateY(), this->GetNormal1().getCoordinateZ());
	glVertex3f(this->GetVertice1().getCoordinateX(), this->GetVertice1().getCoordinateY(), this->GetVertice1().getCoordinateZ());
	//vértice 2
	glColor3f(this->GetVcolor2().getRedComponent(), this->GetVcolor2().getGreenComponent(), this->GetVcolor2().getBlueComponent());
	glNormal3f(this->GetNormal2().getCoordinateX(), this->GetNormal2().getCoordinateY(), this->GetNormal2().getCoordinateZ());
	glVertex3f(this->GetVertice2().getCoordinateX(), this->GetVertice2().getCoordinateY(), this->GetVertice2().getCoordinateZ());
	//vértice 3
	glColor3f(this->GetVcolor3().getRedComponent(), this->GetVcolor3().getGreenComponent(), this->GetVcolor3().getBlueComponent());
	glNormal3f(this->GetNormal3().getCoordinateX(), this->GetNormal3().getCoordinateY(), this->GetNormal3().getCoordinateZ());
	glVertex3f(this->GetVertice3().getCoordinateX(), this->GetVertice3().getCoordinateY(), this->GetVertice3().getCoordinateZ());


	/*glScalef(this->getScaleX(), this->getScaleY(), this->getScaleZ());*/
	glEnd();

}