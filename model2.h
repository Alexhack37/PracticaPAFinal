/*
 * modelo.h
 *
 *  Created on: Nov 12, 2015
 *      Author: francisco
 */
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "vector3d.h"
#include "contorno.h"
#include "triangle.h"
#include "Triangulo.h"

class Modelo : public Solid {
	vector<Vector3D*> vertices;
	vector<Triangulo*> triangulos;
	float maxX, maxY, maxZ;
	float minX, minY, minZ;
public:
	Modelo(const Modelo& m);
	Modelo(string s);
	virtual ~Modelo();
	Triangulo* centrar(Triangulo* t);
	inline float getAncho() { return maxX - minX; }
	inline float getAlto() { return maxY - minY; }
	inline float getProfundo() { return maxZ - minZ; }
	inline void addTriangulo(Triangulo* t) {
		triangulos.push_back(t);
	}
	inline void setColor(Color c) {
		for (Triangulo* t : triangulos) {
			t->setRgb(c);
		}
	}
	inline void Render() {
		Vector3D p = this->getPos();
		glPushMatrix();
		glTranslatef(p.getCoordinateX(), p.getCoordinateY(), p.getCoordinateZ());
		glTranslatef(0, getAlto() / 2.0, 0);
		glColor3f(1, 0, 0);
		glutWireSphere(getAlto() / 2.0, 10, 10);
		for (Triangulo* t : triangulos)
			t->Render();
		glPopMatrix();
	}
	void cargar(string nombreFichero);
	Vector3D* parseVector3D(string& linea);
	Triangulo* parseTriangulo(string& linea);
	void calculaExtremos(Vector3D* v);
	inline Contorno* getContorno();
};

