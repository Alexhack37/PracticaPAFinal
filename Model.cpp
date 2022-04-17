#include "Model.h"


void Model::AddTriangle(Triangle triangle) {
	triangulos.push_back(triangle);
}
void Model::Clear() {
	triangulos.clear();
}

void Model::PaintColor(Color color) {
	for (Triangle& triangle : this->triangulos) {
		triangle.SetVcolor1(color);
		triangle.SetVcolor2(color);
		triangle.SetVcolor3(color);

		
	}
}

void Model::Render() {

	glPushMatrix();
	glTranslatef(this->getPos().getCoordinateX(), this->getPos().getCoordinateY(), this->getPos().getCoordinateZ());
	glColor3f(this->getRgb().getRedComponent(), this->getRgb().getGreenComponent(), this->getRgb().getBlueComponent());
	glRotatef(this->getAngulo().getCoordinateX(), 1.0, 0.0, 0.0);
	glRotatef(this->getAngulo().getCoordinateY(), 0.0, 1.0, 0.0);
	glRotatef(this->getAngulo().getCoordinateZ(), 0.0, 0.0, 1.0);

	for (Triangle& t : triangulos)
		t.Render();
	//Por cada(Triangulo t en triángulos) t.Render();

	glPopMatrix();

}

//respouesta a la pregunta 6.b.1  || La finalidad de andpersant significa que estamos pasando la variable por referencia, aceptando la direccion de la variable en vez del valor de triagulos, si no se pone no funciona