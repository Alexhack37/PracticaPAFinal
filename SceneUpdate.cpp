/*
 * Escena.cpp
 *
 *  Created on: Oct 5, 2015
 *      Author: francisco
 */
#include "SceneUpdate.h"
//#include "Solid.h"
#include "model2.h"
#include "CuboColision.h"
#include "EsferaColision.h"
#include "Proyectil.h"
#include "Model.h"
#include "ModelLoader.h"
#include "FinalBoss.h"
#include "Text.h"
#include "Teapot.h"

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
		std::cout << "reseteo de camara" << endl;
		this->camera->setAngulo(Vector3D(0.0, 0.0, 0.0));
		this->tuArma->setAngulo(Vector3D(0.0, 0.0, 90.0));
	}
	if (key == '1') { //reset camera
		this->tuArma->setShootMode(0);
	}
	if (key == '2') { //reset camera
		this->tuArma->setShootMode(1);
	}
	if (key == '3') { //reset camera
		this->tuArma->setShootMode(2);
	}
}

//Version que se llama desde dentro
void SceneUpdate::Disparo()
{
	int modoDisparo = this->tuArma->getShootMode();
	Vector3D recamara = this->camera->getPos();
	//Vigila el product es para reducir la verlocidad
	Vector3D trayectoria = this->camera->GetSpeedVector().Product(0.1);
	float tamañoNormal = 0.25f;
	float tamañoGrande = 1.0f;
	float BFG = 30.0f;
	switch (modoDisparo)
	{
	case 0:
		tuProyectil->setRadio(tamañoNormal);
		tuProyectil->setRgb(Color(1.0f, 0.15f, 0.0f));
		tuProyectil->setPos(recamara);
		tuProyectil->setSpeed(trayectoria);
		break;
	case 1:
		tuProyectil->setRadio(tamañoGrande);
		tuProyectil->setRgb(Color(0.7f, 0.7, 0.0));
		tuProyectil->setPos(recamara);
		tuProyectil->setSpeed(trayectoria);
		break;
	case 2:
		tuProyectil->setRadio(BFG);
		tuProyectil->setRgb(Color(0.0f, 0.9, 0.0));
		tuProyectil->setPos(recamara);
		tuProyectil->setSpeed(trayectoria.Product(20));
		break;
	}
	//std::cout << "El speed Vector es " <<
	//	trayectoria.getCoordinateX() << " " <<
	//	trayectoria.getCoordinateY() << " " <<
	//	trayectoria.getCoordinateZ() << std::endl;
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
	//Declaro los modelos
	//string nombreModelo = "objects\\Soda.obj";
	//Modelo* model = new Modelo(nombreModelo);
	Model* muestraModelo = new Model();
	FinalBoss* muestraBoss = new FinalBoss();
	ModelLoader* muestraLoader = new ModelLoader();


	//Este es para poner el tamaño del modelo
	muestraLoader->setScala(1);
	//Asteroide no funciona
	//muestraLoader->LoadModel("objects\\GiantTyraxRobot.dae");
	muestraLoader->LoadModel("objects\\Soda.obj");
    *muestraModelo = muestraLoader->GetModel();
	muestraModelo->setPos(Vector3D(25.0f, 12.0f, 28.0f));
	muestraModelo->setAngulo(Vector3D(180.0f, 0.0f, 0.0f));
	muestraModelo->setOrientationSpeed(Vector3D(0.0f, 0.5f, 0.0f));
	muestraModelo->setSpeed(Vector3D(0.0f, 0.0f, 0.0f));
	muestraModelo->PaintColor(Color(0.0f, 1.0f, 1.0f));
	muestraModelo->setPuntos(100);
	// Este es para poner el tamaño de la hitbox
	muestraModelo->setScala(1.0f);
	escenaCambia->add(muestraModelo);


	muestraModelo = new Model();
	muestraLoader = new ModelLoader();




	//Así se declara un boss
	//Este es para poner el tamaño del modelo
	muestraLoader->setScala(0.5);
	//Asteroide no funciona
	//muestraLoader->LoadModel("objects\\GiantTyraxRobot.dae");
	//muestraLoader->LoadModel("objects\\Asteroide.obj");
	muestraLoader->LoadModel("objects\\Satelite.obj");
   *muestraBoss = muestraLoader->GetBoss();
	muestraBoss->setPos(Vector3D(30.0f, 12.0f, 20.0f));
	muestraBoss->setAngulo(Vector3D(180.0f, 0.0f, 0.0f));
	muestraBoss->setOrientationSpeed(Vector3D(0.0f, 0.5f, 0.0f));
	muestraBoss->setSpeed(Vector3D(0.0f, 0.0f, 0.0f));
	muestraBoss->PaintColor(Color(1.0f, 0.0f, 1.0f));
	muestraBoss->setDano(20);
	// Este es para poner el tamaño de la hitbox
	muestraBoss->setScala(1.0f);
	
	escenaCambia->add(muestraBoss);

	//Declaro los solid
	Solid *muestraSolid;
	muestraSolid = new CuboColision(Vector3D(5, 15, 5), 10);
	muestraSolid->setRgb(Color(1.0f, 0.0f, 0.0f));
	muestraSolid->setSpeed(Vector3D(0.0f, 0.0f, 0.0f));
	escenaCambia->add(muestraSolid);
	muestraSolid = new EsferaColision(Vector3D(55, 15, 5));
	muestraSolid->setRgb(Color(0.0f, 0.0f, 1.0f));
	muestraSolid->setSpeed(Vector3D(0.0f, 0.0f, 0.0f));
	escenaCambia->add(muestraSolid);
	

}
void SceneUpdate::Init(SceneUpdate* escenaCambia, string nombre)
{
	Text* muestraText = new Text();
	Model* muestraModelo = new Model();
	FinalBoss* muestraBoss = new FinalBoss();
	ModelLoader* muestraLoader = new ModelLoader();
	/*Solid* muestraSolid;*/

	muestraText = new Text("Jugar");
	muestraText->setPos(Vector3D(25.0f, 12.0f, 10.0f));
	muestraText->setAngulo(Vector3D(0.0f, 0.0f, 0.0f));
	muestraText->setOrientationSpeed(Vector3D(0.0f, 0.0f, 0.0f));
	muestraText->setRgb(Color(1.0f, 1.0f, 1.0f));
	escenaCambia->addFijo(muestraText);

	muestraText = new Text("Alejandro Cavero y Luis Mateos Sanchez");
	muestraText->setPos(Vector3D(25.0f, 5.0f, 10.0f));
	muestraText->setAngulo(Vector3D(0.0f, 0.0f, 0.0f));
	muestraText->setOrientationSpeed(Vector3D(0.0f, 0.0f, 0.0f));
	muestraText->setRgb(Color(1.0f, 1.0f, 0.0f));
	escenaCambia->addFijo(muestraText);


	muestraLoader->setScala(4);
	muestraLoader->LoadModel("objects\\JUNKBLASTER.obj");
	*muestraModelo = muestraLoader->GetModel();
	muestraModelo->setPos(Vector3D(25.0f, 15.0f, 10.0f));
	muestraModelo->setAngulo(Vector3D(180.0f, 180.0f, 0.0f));
	muestraModelo->setOrientationSpeed(Vector3D(0.0f, 0.0f, 0.0f));
	muestraModelo->setSpeed(Vector3D(0.0f, 0.0f, 0.0f));
	muestraModelo->PaintColor(Color(0.0f, 1.0f, 1.0f));
	// Este es para poner el tamaño de la hitbox
	muestraModelo->setScala(1.0f);
	escenaCambia->add(muestraModelo);
	muestraLoader->Clear();

	muestraModelo = new Model();
	muestraLoader = new ModelLoader();

	//muestraSolid = new Teapot();
	//muestraSolid->setAngulo(Vector3D(30.0f, -60.0f, -10.0f));
	//muestraSolid->setPos(Vector3D(20.0f, 12.0f, 5.0f));
	//muestraSolid->setRgb(Color(1.0f, 0.0f, 0.0f));
	//muestraSolid->setOrientationSpeed(Vector3D(0.0f, 5.0f, 0.0f));
	//muestraSolid->setSpeed(Vector3D(0.1f, 0.2f, 0.0f));
	//muestraSolid->setId(23);
	//escenaCambia->add(muestraSolid);

	muestraLoader->setScala(1);
	muestraLoader->LoadModel("objects\\Satelite.obj");
	*muestraModelo = muestraLoader->GetModel();
	//muestraModelo->setPos(Vector3D(20.0f, 12.0f, 5.0f));
	muestraModelo->setPos(Vector3D(25.0, 14.0, 15.0));
	muestraModelo->setAngulo(Vector3D(30.0f, -60.0f, -10.0f));
	muestraModelo->setOrientationSpeed(Vector3D(0.5f, 1.0f, 0.0f));
	muestraModelo->setSpeed(Vector3D(0.0f, 0.0f, 1.0f));
	muestraModelo->PaintColor(Color(1.0f, 1.0f, 1.0f));
	// Este es para poner el tamaño de la hitbox
	muestraModelo->setScala(1.0f);
	escenaCambia->add(muestraModelo);
	muestraLoader->Clear();



	muestraText = new Text("Nombre Jugador " + nombre);


	muestraText->setPos(Vector3D(25.0f, 10.0f, 10.0f));
	muestraText->setAngulo(Vector3D(0.0f, 0.0f, 0.0f));
	muestraText->setOrientationSpeed(Vector3D(0.0f, 0.0f, 0.0f));
	muestraText->setRgb(Color(1.0f, 1.0f, 1.0f));
	escenaCambia->add(muestraText);

}
void SceneUpdate::EscenaRandom(SceneUpdate* escenaCambia) {

		int tamanoEscena2 = 3;
		//escena = 2;

		srand(time(NULL));
		for (int i = 0; i < tamanoEscena2; i++)
		{
			//float randomScala  = rand() % 3 + 1;
			float randomScala = 4;
			float posX = rand() % 50 + 1;
			float posY = rand() % 20 + 1;
			/*ModelLoader* loaderPEr = new ModelLoader();
			Model* objetoPer = new Model();*/

			Model* muestraModelo = new Model();
			ModelLoader* muestraLoader = new ModelLoader();

			muestraLoader->setScala(randomScala);
			muestraLoader->LoadModel("objects\\" + objetos[rand() % 7] + ".obj");
			*muestraModelo = muestraLoader->GetModel();
			//objetoPer->setPos(Vector3D(static_cast <float>(rand() % 20 + 1.0f), static_cast <float>(rand()%20+ 1.0f) ,7.0f));//2,2,2
			muestraModelo->setPos(Vector3D(posX, posY, 10.0f));
			muestraModelo->setAngulo(Vector3D(180.0f, posY, 0.0f));
			muestraModelo->setOrientationSpeed(Vector3D(0.1f, static_cast <float>(rand() % 10) / 40, 0.0f));
			//objetoPer->setSpeed(Vector3D(static_cast <float>(rand() % 10) / 40 , static_cast <float>(rand() % 10) / 40, 0.0f));
			//muestraModelo->setSpeed(Vector3D(static_cast <float>(rand() % 10) / 40, 0.1f, 0.0f));
			muestraModelo->setSpeed(Vector3D(0.0f, 0.0f, 0.0f));
			muestraModelo->PaintColor(Color(static_cast <float>(rand() % 10) / 30, static_cast <float>(rand() % 10) / 10, static_cast <float>(rand() % 10) / 20));
			muestraModelo->setId(i);
			muestraModelo->setScala(randomScala);
			escenaCambia->add(muestraModelo);
			//escenaUsando->add(muestraLoader);
			//muestraLoader->Clear();
		}

}

void SceneUpdate::checkBoundary() {
	for (size_t i = 0; i < moviles.size(); i++)
	{
		if (moviles[i]->getPos().getCoordinateX() > boundary.getCoordinateX() || moviles[i]->getPos().getCoordinateX() < boundary.getCoordinateX() * -1) {

			moviles[i]->setSpeed(moviles[i]->getSpeed().MultValues(Vector3D(-1.0, 1.0, 1.0)));
		}
		if (moviles[i]->getPos().getCoordinateY() > boundary.getCoordinateY() || moviles[i]->getPos().getCoordinateY() < boundary.getCoordinateY() * -1) {
			moviles[i]->setSpeed(moviles[i]->getSpeed().MultValues(Vector3D(1.0, -1.0, 1.0)));
		}
		if (moviles[i]->getPos().getCoordinateZ() > boundary.getCoordinateZ() || moviles[i]->getPos().getCoordinateZ() < boundary.getCoordinateZ() * -1) {
			moviles[i]->setSpeed(moviles[i]->getSpeed().MultValues(Vector3D(1.0, 1.0, -1.0)));
		}
	}

}