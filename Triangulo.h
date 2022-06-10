/*
 * triangulo.h
 *
 *  Created on: Nov 12, 2015
 *      Author: Francisco Dominguez
 */
#include "plano.h"
#include "vector3d.h"

class Triangulo : public Plano {
	Vector3D p0, p1, p2;
public:
	Triangulo(Vector3D p0, Vector3D p1, Vector3D p2) :Plano(), p0(p0), p1(p1), p2(p2) {
		Vector3D v0 = p1.Sub(p0);
		Vector3D v1 = p2.Sub(p1);
		Vector3D vn = v0.crossProduct(v1);
		if (vn.Modulo() < 0.001)
			cout << "longitud muy pequeña" << endl;
		else
			vn.Normalizar();
		float d = vn.DotProduct(p2);
		this->setA(vn.getCoordinateX());
		this->setB(vn.getCoordinateY());
		this->setC(vn.getCoordinateZ());
		this->setD(d);
	}
	inline Vector3D getP0() { return p0; }
	inline Vector3D getP1() { return p1; }
	inline Vector3D getP2() { return p2; }
	virtual ~Triangulo();
	void Render();
};


