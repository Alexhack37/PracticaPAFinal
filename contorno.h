/*
 * contorno.h
 *
 *  Created on: Nov 7, 2015
 *      Author: francisco
 */
#pragma once
#include <cmath>
#include "planoX.h"
#include "planoX.h"
#include "planoY.h"
#include "planoZ.h"
#include "EsferaColision.h"
#include "CuboColision.h"
#include "Proyectil.h"
class Contorno{
	Vector3D p;
	float r;
public:
	Contorno(Vector3D p, float r) :p(p), r(r) {}
	virtual ~Contorno();
	bool colision(Plano* p);
	bool colision(EsferaColision* e);
	bool colision(CuboColision* c);
	bool colision(Proyectil* bala);
	//Objetos enemigo

	//Final boss

	/////////////////////////////////////////
	const Vector3D& getP() const { return p; }
	void setP(const Vector3D& p) { this->p = p; }
	float getR() const { return r; }
	void setR(float r) { this->r = r; }
};

