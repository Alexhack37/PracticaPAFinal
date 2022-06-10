#include "Solid.h"
#include "contorno.h"


/*void Solid::Render() {
	glPushMatrix();
	glTranslatef(getPos().getCoordinateX(), getPos().getCoordinateY(), getPos().getCoordinateZ());
	glColor3f(getRgb().getRedComponent(), getRgb().getGreenComponent(), getRgb().getBlueComponent());

	glRotatef(getAngulo().getCoordinateX(), 1.0, 0.0, 0.0);
	glRotatef(getAngulo().getCoordinateY(), 0.0, 1.0, 0.0);
	glRotatef(getAngulo().getCoordinateZ(), 0.0, 0.0, 1.0);

	glPopMatrix(); 

}
*/
void Solid::Update(const float& time) {

	this->posicion = this->posicion.Add(this->getSpeed().Product(incremento_de_tiempo));
	//this->posicion = this->posicion + (this->getSpeed() * incremento_de_tiempo);


	this->orientacion = this->orientacion.Add((this->getOrientationSpeed().Product(incremento_de_tiempo)));
	//this->orientacion = this->orientacion + (this->getOrientationSpeed() * incremento_de_tiempo);
}
Solid:: ~Solid() {

}
Contorno* Solid::getContorno() {
	return new Contorno(Vector3D(0, 0, 0), 1);
}
void Solid::resuelveColision(Solid* s) {
	//Vector3D vn = s->getPos().Sub(this->getPos());
	//vn.Normalizar();
	//Vector3D vv = s->getSpeed();
	//Vector3D vr = vv.reflect(vn);
	//s->setSpeed(vr);
	std::cout << "Colision detectada";
}

