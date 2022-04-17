#include "Camera.h"


void Camera::Render()
{
	glTranslatef(-1 * getPos().getCoordinateX(), -1 * getPos().getCoordinateY(), -1 * getPos().getCoordinateZ()); 
	glRotatef(this->getAngulo().getCoordinateX(), 1.0, 0.0, 0.0); 
	glRotatef(this->getAngulo().getCoordinateY(), 0.0, 1.0, 0.0);
	glRotatef(this->getAngulo().getCoordinateZ(), 0.0, 0.0, 1.0);
};