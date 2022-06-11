/*
 * Escena.cpp
 *
 *  Created on: Oct 5, 2015
 *      Author: francisco
 */
#include "SceneUpdate.h"
//#include "Solid.h"
#include "CuboColision.h"
#include "EsferaColision.h"
#include "Proyectil.h"

SceneUpdate::~SceneUpdate() {
	// TODO Auto-generated destructor stub
}

void SceneUpdate::ProcessMouseMovement(int x, int y)
{
	this->camera->ProcessMouseMovement(x, y);
}

void SceneUpdate::ProcessKeyPressed(unsigned char key, int px, int py)
{
	
	if (key == 'f'|| key == 'F') {
		this->Disparo();
	}
	if (key == 'r' || key == 'R') { //reset camera
		this->camera->SetSpeedVector(Vector3D(0.0, 0.0, -1.0));
		this->tuArma->setAngulo(Vector3D(0.0, 0.0, 90.0));
	}
}
//Version que se llama desde dentro
void SceneUpdate::Disparo()
{
	int modoDisparo = this->tuArma->getShootMode();
	float tamañoNormal = 0.25f;
	float tamañoGrande = 1.0f;
	float BFG = 10.0f;
	switch (modoDisparo)
	{
	case 0:
		tuProyectil->setRadio(tamañoNormal);
		tuProyectil->setRgb(Color(1.0f, 0.15f, 0.0f));
		break;
	case 1:
		tuProyectil->setRadio(tamañoGrande);
		tuProyectil->setRgb(Color(0.7f, 0.7, 0.0));
		break;
	case 2:
		tuProyectil->setRadio(BFG);
		tuProyectil->setRgb(Color(0.0f, 0.9, 0.0));
		break;
	}
	Vector3D recamara = this->camera->getPos();
	Vector3D trayectoria = this->camera->GetSpeedVector().Product(0.1);
	tuProyectil->setPos(recamara);
	tuProyectil->setSpeed(trayectoria);
}

//Version que se llama desde game
//void SceneUpdate::Disparo(SceneUpdate* object)
//{
//	Vector3D recamara = this->camera->getPos();
//	Vector3D trayectoria = this->camera->GetSpeedVector().Product(0.1);
//	tuProyectil->setPos(recamara);
//	tuProyectil->setSpeed(trayectoria);
//}

//void SceneUpdate::Init(SceneUpdate* )
void SceneUpdate::EscenaTesteo(SceneUpdate* escenaCambia)
{
	//Declaro el cubo colisionante
	Solid *muestra;
	muestra = new CuboColision(Vector3D(5, 15, 5), 10);
	muestra->setRgb(Color(1.0f, 0.0f, 0.0f));
	muestra->setSpeed(Vector3D(0.0f, 0.0f, 0.0f));
	escenaCambia->add(muestra);
	muestra = new EsferaColision(Vector3D(55, 15, 5));
	muestra->setRgb(Color(0.0f, 0.0f, 1.0f));
	muestra->setSpeed(Vector3D(0.0f, 0.0f, 0.0f));
	escenaCambia->add(muestra);

}
