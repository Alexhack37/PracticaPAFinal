#include "Text.h"



void Text::Render(){
	glPushMatrix();
	glColor3f(this->getRgb().getRedComponent(), this->getRgb().getGreenComponent(), this->getRgb().getBlueComponent());
	glTranslatef(this->getPos().getCoordinateX(), this->getPos().getCoordinateY(), this->getPos().getCoordinateZ());
	glRasterPos3d(0,0,0);
	for (char c : text)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c);
	glPopMatrix();
}


//std::ostream& operator<<(std::ostream& os, const Text& v)
//{
//	// TODO: Insertar una instrucción "return" aquí
//	os << static_cast<const Solid&>(v);
//	os << ", text=" << v.text;
//	return os;
//}
