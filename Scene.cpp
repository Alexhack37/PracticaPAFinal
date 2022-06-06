#include "Scene.h"
#include "Solid.h"

#include "Camera.h"
#include "Proyectil.h"
#include "ProyectilArea.h"
#include "camera_fps.h"
#include <iostream>


Mercader* comerciante = new Mercader();



//Objetos en el juego
Model* Mecanico = new Model();
ModelLoader* loader = new ModelLoader();
Teapot* teapot0 = new Teapot();
Teapot* teapot = new Teapot();
Teapot* teapotB = new Teapot();
Teapot* teapotA = new Teapot();
Model* Refresco = new Model();
Model* Burger = new Model();
Model* Cake = new Model();
Model* CupcakeCherry = new Model();
Model* SodaLataTria = new Model();
FinalBoss* boss = new FinalBoss();


Proyectil* bala = new Proyectil();

void Scene::AddGameObject(Solid* object) {
	
	gameObjects.push_back(object);

};

int Scene::Size() {
	return gameObjects.size();
}

void Scene::Render() {

	this->camera->Render();
	this->tuMirila->Render();
	this->tuArma->Render();
	for (size_t i = 0; i < gameObjects.size(); i++){
		gameObjects[i]->Render();
	}
}


void Scene::Update(const float& time) {

	this->camera->Update(0.00001);
	this->tuArma->Update(time);
	this->tuMirila->Update(time);
	for (size_t i = 0; i < gameObjects.size(); i++) {
		gameObjects[i]->Update(time);
	}
	checkBoundary();
	if (bala->getPos().getCoordinateZ() == 1.0f) {
		DeleteObjectByMyId(10);
	}
	//INIT no funciona
	if (bala->getPos().getCoordinateX() > teapot0->getPos().getCoordinateX() && bala->getPos().getCoordinateX() < loader->getHeight() + teapot0->getPos().getCoordinateX()
		&& bala->getPos().getCoordinateY() > teapot0->getPos().getCoordinateY() && bala->getPos().getCoordinateY() < loader->getLength() + teapot0->getPos().getCoordinateY()) {
		DeleteObjectByMyId(23);
		teapot0->setPos(Vector3D(24.0f, 10.0f, 100.0f));
	}
	//PRIMERA ESCENA
	if (bala->getPos().getCoordinateX() > Refresco->getPos().getCoordinateX() && bala->getPos().getCoordinateX() < loader->getHeight() + Refresco->getPos().getCoordinateX()
		&& bala->getPos().getCoordinateY() > Refresco->getPos().getCoordinateY() && bala->getPos().getCoordinateY() < loader->getLength() + Refresco->getPos().getCoordinateY()) {
		DeleteObjectByMyId(1);
		Refresco->setPos(Vector3D(24.0f, 10.0f, 100.0f));
	}
	if (bala->getPos().getCoordinateX() > teapot->getPos().getCoordinateX() && bala->getPos().getCoordinateX() < loader->getHeight() + teapot->getPos().getCoordinateX()
		&& bala->getPos().getCoordinateY() > teapot->getPos().getCoordinateY() && bala->getPos().getCoordinateY() < loader->getLength() + teapot->getPos().getCoordinateY()
		&& bala->getPos().getCoordinateZ() > teapot->getPos().getCoordinateZ() && bala->getPos().getCoordinateZ() < loader->getWidth() + teapot->getPos().getCoordinateZ()) {
		this->DeleteObjectByMyId(2);
		player->setVida(50.0f);
		teapot->setPos(Vector3D(24.0f, 10.0f, 100.0f));
	}
	if (bala->getPos().getCoordinateX() > Burger->getPos().getCoordinateX() && bala->getPos().getCoordinateX() < loader->getHeight() + Burger->getPos().getCoordinateX()
		&& bala->getPos().getCoordinateY() > Burger->getPos().getCoordinateY() && bala->getPos().getCoordinateY() < loader->getLength() + Burger->getPos().getCoordinateY()) {
		this->DeleteObjectByMyId(3);
		Burger->setPos(Vector3D(24.0f, 10.0f, 100.0f));
	}
	if (bala->getPos().getCoordinateX() > Cake->getPos().getCoordinateX() && bala->getPos().getCoordinateX() < loader->getHeight() + Cake->getPos().getCoordinateX()
		&& bala->getPos().getCoordinateY() > Cake->getPos().getCoordinateY() && bala->getPos().getCoordinateY() < loader->getLength() + Cake->getPos().getCoordinateY()) {
		this->DeleteObjectByMyId(4);
		Cake->setPos(Vector3D(24.0f, 10.0f, 100.0f));
	}
	if (bala->getPos().getCoordinateX() > CupcakeCherry->getPos().getCoordinateX() && bala->getPos().getCoordinateX() < loader->getHeight() + CupcakeCherry->getPos().getCoordinateX()
		&& bala->getPos().getCoordinateY() > CupcakeCherry->getPos().getCoordinateY() && bala->getPos().getCoordinateY() < loader->getLength() + CupcakeCherry->getPos().getCoordinateY()) {
		this->DeleteObjectByMyId(5);
		CupcakeCherry->setPos(Vector3D(24.0f, 10.0f, 100.0f));
	}
	if (bala->getPos().getCoordinateX() > SodaLataTria->getPos().getCoordinateX() && bala->getPos().getCoordinateX() < loader->getHeight() + SodaLataTria->getPos().getCoordinateX()
		&& bala->getPos().getCoordinateY() > SodaLataTria->getPos().getCoordinateY() && bala->getPos().getCoordinateY() < loader->getLength() + SodaLataTria->getPos().getCoordinateY()) {
		this->DeleteObjectByMyId(6);
		SodaLataTria->setPos(Vector3D(24.0f, 10.0f, 100.0f));
	}
	//SEGUNDA ESCENA
	if (bala->getPos().getCoordinateX() > boss->getPos().getCoordinateX() && bala->getPos().getCoordinateX() < loader->getHeight() + boss->getPos().getCoordinateX()
		&& bala->getPos().getCoordinateY() > boss->getPos().getCoordinateY() && bala->getPos().getCoordinateY() < loader->getLength() + boss->getPos().getCoordinateY()) {
		boss->setVida(boss->getVida() - 10.0f);
		cout << boss->getVida() << endl;
		if (boss->getVida() < 0.0f) {
			this->DeleteObjectByMyId(9);
			boss->setPos(Vector3D(24.0f, 10.0f, 100.0f));
		}
	}
	if (bala->getPos().getCoordinateX() > teapotA->getPos().getCoordinateX() && bala->getPos().getCoordinateX() < loader->getHeight() + teapotA->getPos().getCoordinateX()
		&& bala->getPos().getCoordinateY() > teapotA->getPos().getCoordinateY() && bala->getPos().getCoordinateY() < loader->getLength() + teapotA->getPos().getCoordinateY()) {
		teapotA->setPos(Vector3D(24.0f, 10.0f, 100.0f));
		this->DeleteObjectByMyId(7);
	}
	if (bala->getPos().getCoordinateX() > teapotB->getPos().getCoordinateX() && bala->getPos().getCoordinateX() < loader->getHeight() + teapotB->getPos().getCoordinateX()
		&& bala->getPos().getCoordinateY() > teapotB->getPos().getCoordinateY() && bala->getPos().getCoordinateY() < loader->getLength() + teapotB->getPos().getCoordinateY()) {
		teapotB->setPos(Vector3D(24.0f, 10.0f, 100.0f));
		this->DeleteObjectByMyId(8);
	}
}

void Scene::ProcessMouseMovement(int x, int y) {

	this->tuArma->ProcessMouseMovement(x, y);
	this->tuMirila->ProcessMouseMovement(x, y);
	//this->camera->ProcessMouseMovement(x, y);
}

void Scene::ProcessKeyPressed(unsigned char key, int px, int py) {
	////this->camera->ProcessKeyPressed(key,px,py);
	//int modoDisparo = this->tuArma->getShootMode();
	//float estabilizadoX = 0.01;
	//float estabilizadoY = 0.01;

	//Vector3D vectorDisparo = Vector3D(this->tuArma->getAngulo().getCoordinateY() * -1, this->tuArma->getAngulo().getCoordinateX(), -1.0f);

	//int saltosEstablX = this->tuArma->getAngulo().getCoordinateX() / 5;
	//int saltosEstablY = this->tuArma->getAngulo().getCoordinateY() / 5;

	//estabilizadoX += 0.001 * saltosEstablX;
	//estabilizadoY += 0.001 * saltosEstablY;

	////Velocidad y trayectorias segun la mira
	//Vector3D vectorDisparoAdapt = vectorDisparo.MultValues(Vector3D(estabilizadoX, estabilizadoY, 0.5f));
}
void Scene::DeleteLastGameObject() {
	gameObjects.pop_back();
}
void Scene::DeleteGameObject(int i) {
	gameObjects.erase(gameObjects.begin() + i-1);
}
void Scene::DeleteObjectByMyId(int a) {

	for (size_t i = 0; i < gameObjects.size(); i++)
	{
		if (gameObjects[i]->getId() == a) {
			gameObjects.erase(gameObjects.begin() + i );
		}
		
	}
	
}

bool Scene::checkObjetIndex(int a) {

	for (size_t i = 0; i < gameObjects.size(); i++)
	{
		if (gameObjects[i]->getId() == a) {
			return true;
		}
	}
	return false;
}

//Controla rebotes de los objetos en la caja
void Scene::checkBoundary() {
	for (size_t i = 0; i < gameObjects.size(); i++)
	{
		if (gameObjects[i]->getPos().getCoordinateX() > boundary.getCoordinateX() || gameObjects[i]->getPos().getCoordinateX() < 0.0f) {

			gameObjects[i]->setSpeed(gameObjects[i]->getSpeed().MultValues(Vector3D(-1.0, 1.0, 1.0)));	
		}
		if (gameObjects[i]->getPos().getCoordinateY() > boundary.getCoordinateY() || gameObjects[i]->getPos().getCoordinateY() < 0.0f) {
			gameObjects[i]->setSpeed(gameObjects[i]->getSpeed().MultValues(Vector3D(1.0, -1.0, 1.0)));
		}						

		if (gameObjects[i]->getPos().getCoordinateZ() > boundary.getCoordinateZ() || gameObjects[i]->getPos().getCoordinateZ() < 0.0f) {
			
			gameObjects[i]->setSpeed(gameObjects[i]->getSpeed().MultValues(Vector3D(1.0, 1.0, -1.0)));
			//gameObjects[i]->~Solid();
			//cout << "bala borrada" << endl;
		}

	}
}

void Scene::Disparo(Scene* scene) {


	float estabilizadoX = 0.01;
	float estabilizadoY = 0.01;

	Vector3D vectorDisparo = Vector3D(scene->tuArma->getAngulo().getCoordinateY() * -1, scene->tuArma->getAngulo().getCoordinateX(), -1.0f);


	int saltosEstablX = scene->tuArma->getAngulo().getCoordinateX() / 10;
	int saltosEstablY = scene->tuArma->getAngulo().getCoordinateY() / 10;

	estabilizadoX += 0.001 * saltosEstablX;
	estabilizadoY += 0.001 * saltosEstablY;

	Vector3D vectorDisparoAdapt = vectorDisparo.MultValues(Vector3D(estabilizadoX, estabilizadoY, 1.0f));

	bala->setPos(scene->tuArma->getPos());
	bala->setAngulo(Vector3D(0.0, 0.0, 0.0));
	bala->setRgb(Color(1.0, 0.0, 0.0));
	bala->setOrientationSpeed(Vector3D(0.0, 0.0, 0.0));
	bala->setSpeed(vectorDisparoAdapt);
	bala->setId(10);
	scene->AddGameObject(bala);
	player->cambiarMunicion(-1.0f);
}

void Scene::Init(Scene* object) {


	//texto
	
	Text* intro = new Text("Jugar");

	intro->setPos(Vector3D(25.0f, 10.0f, 10.0f));
	intro->setAngulo(Vector3D(0.0f, 0.0f, 0.0f));
	intro->setOrientationSpeed(Vector3D(0.0f, 0.0f, 0.0f));
	intro->setRgb(Color(1.0f, 1.0f, 1.0f));
	object->AddGameObject(intro);

	Text* nombres = new Text("Alejandro Cavero y Luis Mateos Sanchez");

	nombres->setPos(Vector3D(25.0f, 5.0f, 10.0f));
	nombres->setAngulo(Vector3D(0.0f, 0.0f, 0.0f));
	nombres->setOrientationSpeed(Vector3D(0.0f, 0.0f, 0.0f));
	nombres->setRgb(Color(1.0f, 1.0f, 0.0f));
	object->AddGameObject(nombres);


	//modelo personalizado


	ModelLoader* loader = new ModelLoader();
	Model* Masterblaster = new Model();
	loader->setScala(4.0f);
	loader->LoadModel("objects\\JUNKBLASTER.obj");


	*Masterblaster = loader->GetModel();
	Masterblaster->setAngulo(Vector3D(0.0f, 0.0f, 180.0f));
	Masterblaster->setPos(Vector3D(25.0f, 15.0f, 10.0f));
	Masterblaster->PaintColor(Color(1.0f, 1.0f, 0.0f));
	Masterblaster->setOrientationSpeed(Vector3D(0.0f, 0.0f, 0.0f));
	Masterblaster->setSpeed(Vector3D(0.0f, 0.0f, 0.0f));

	object->AddGameObject(Masterblaster);
	loader->Clear();

	
	teapot0->setAngulo(Vector3D(30.0f, -60.0f, -10.0f));
	teapot0->setPos(Vector3D(20.0f, 12.0f, 5.0f));
	teapot0->setRgb(Color(1.0f, 1.0f, 1.0f));
	teapot0->setOrientationSpeed(Vector3D(0.0f, 5.0f, 0.0f));
	teapot0->setSpeed(Vector3D(0.0f, 0.0f, 0.0f));
	teapot0->setId(23);
	object->AddGameObject(teapot0);

}

//escena principal
void Scene::Escena1(Scene* escenaUsando) {
	
	loader->setScala(1);
	loader->LoadModel("objects\\Soda.obj");
	*Refresco = loader->GetModel();
	Refresco->setPos(Vector3D(24.0f, 10.0f, 5.0f));
	Refresco->setAngulo(Vector3D(180.0f, 0.0f, 0.0f));
	Refresco->setOrientationSpeed(Vector3D(0.0f, 0.5f, 0.0f));
	Refresco->setSpeed(Vector3D(0.0f, 0.0f, 0.0f));
	Refresco->PaintColor(Color(1.0f, 1.0f, 1.0f));
	Refresco->setId(1);
	escenaUsando->AddGameObject(Refresco);
	loader->Clear();

	teapot->setAngulo(Vector3D(30.0f, -60.0f, -10.0f));
	teapot->setPos(Vector3D(20.0f, 10.0f, 5.0f));
	teapot->setRgb(Color(1.0f, 1.0f, 1.0f));
	teapot->setOrientationSpeed(Vector3D(0.0f, 0.5f, 0.0f));
	teapot->setSpeed(Vector3D(0.0f, 0.0f, 0.0f));
	teapot->setId(2);
	escenaUsando->AddGameObject(teapot);

	loader->setScala(5);
	loader->LoadModel("objects\\Burger.obj");
	*Burger = loader->GetModel();
	Burger->setPos(Vector3D(30.0f, 10.0f, 5.0f));
	Burger->setAngulo(Vector3D(180.0f, 0.0f, 0.0f));
	Burger->setOrientationSpeed(Vector3D(0.0f, 0.5f, 0.0f));
	Burger->setSpeed(Vector3D(0.01f, 0.0f, 0.0f));
	Burger->PaintColor(Color(1.0f, 1.0f, 1.0f));
	Burger->setId(3);
	escenaUsando->AddGameObject(Burger);
	loader->Clear();

	loader->setScala(2);
	loader->LoadModel("objects\\Cake.obj");
	*Cake = loader->GetModel();
	Cake->setPos(Vector3D(20.0f, 15.0f, 7.0f));
	Cake->setAngulo(Vector3D(180.0f, 0.0f, 0.0f));
	Cake->setOrientationSpeed(Vector3D(0.0f, 0.5f, 0.0f));
	Cake->setSpeed(Vector3D(0.0f, 0.0f, 0.0f));
	Cake->PaintColor(Color(1.0f, 1.0f, 1.0f));
	Cake->setId(4);
	escenaUsando->AddGameObject(Cake);
	loader->Clear();

	loader->setScala(2);
	loader->LoadModel("objects\\CupcakeCherry.obj");
	*CupcakeCherry = loader->GetModel();
	CupcakeCherry->setPos(Vector3D(10.0f, 10.0f, 7.0f));
	CupcakeCherry->setAngulo(Vector3D(180.0f, 0.0f, 0.0f));
	CupcakeCherry->setOrientationSpeed(Vector3D(0.0f, 0.5f, 0.0f));
	CupcakeCherry->setSpeed(Vector3D(0.0f, 0.0f, 0.0f));
	CupcakeCherry->PaintColor(Color(1.0f, 1.0f, 1.0f));
	CupcakeCherry->setId(5);
	escenaUsando->AddGameObject(CupcakeCherry);
	loader->Clear();


	loader->setScala(4);
	loader->LoadModel("objects\\Hotdog.obj");
	*SodaLataTria = loader->GetModel();
	SodaLataTria->setPos(Vector3D(34.0f, 10.0f, 7.0f));
	SodaLataTria->setAngulo(Vector3D(180.0f, 0.0f, 0.0f));
	SodaLataTria->setOrientationSpeed(Vector3D(0.0f, 0.5f, 0.0f));
	SodaLataTria->setSpeed(Vector3D(0.0f, 0.0f, 0.0f));
	SodaLataTria->PaintColor(Color(1.0f, 1.0f, 1.0f));
	SodaLataTria->setId(6);
	escenaUsando->AddGameObject(SodaLataTria);
	loader->Clear();

}

void Scene::EscenaFinal(Scene* escenaUsando) {

	Text* finalbossTexto = new Text("FINNAL BOSS");
	finalbossTexto->setPos(Vector3D(22.0f, 25.0f, 0.0f));
	finalbossTexto->setAngulo(Vector3D(0.0f, 0.0f, 0.0f));
	finalbossTexto->setOrientationSpeed(Vector3D(0.0f, 0.0f, 0.0f));
	finalbossTexto->setRgb(Color(1.0f, 1.0f, 1.0f));
	escenaUsando->AddGameObject(finalbossTexto);



	boss->setSize(2);
	boss->setAngulo(Vector3D(0.0f, 0.0f, 0.0f));
	boss->setPos(Vector3D(24.0f, 10.0f, 5.0f));
	boss->setRgb(Color(0.0f, 0.0f, 1.0f));
	boss->setOrientationSpeed(Vector3D(0.0f, 0.01f, 0.0f));
	boss->setSpeed(Vector3D(0.1f, 0.0f, 0.0f));
	boss->setId(9);
	boss->setVida(100);
	escenaUsando->AddGameObject(boss);


	teapotA->setAngulo(Vector3D(30.0f, -60.0f, -10.0f));
	teapotA->setPos(Vector3D(20.0f, 10.0f, 5.0f));
	teapotA->setRgb(Color(1.0f, 1.0f, 1.0f));
	teapotA->setOrientationSpeed(Vector3D(0.0f, 0.5f, 0.0f));
	teapotA->setSpeed(Vector3D(0.01f, 0.01f, 0.0f));
	teapotA->setId(7);
	escenaUsando->AddGameObject(teapotA);

	teapotB->setAngulo(Vector3D(30.0f, -60.0f, -10.0f));
	teapotB->setPos(Vector3D(30.0f, 20.0f, 5.0f));
	teapotB->setRgb(Color(1.0f, 0.0f, 1.0f));
	teapotB->setOrientationSpeed(Vector3D(0.0f, 0.5f, 0.0f));
	teapotB->setSpeed(Vector3D(-0.01f, -0.01f, 0.0f));
	teapotB->setId(8);
	escenaUsando->AddGameObject(teapotB);

}

void Scene::Congratulations(Scene* escenaUsando) {

	std::cout << "final" << std::endl;
	Text* end = new Text("GANASTE ENHORABUENA");
	end->setPos(Vector3D(20.0f, 15.0f, 10.0f));
	end->setAngulo(Vector3D(0.0f, 0.0f, 0.0f));
	end->setOrientationSpeed(Vector3D(0.0f, 0.0f, 0.0f));
	end->setRgb(Color(1.0f, 1.0f, 1.0f));
	escenaUsando->AddGameObject(end);

	ModelLoader* loader = new ModelLoader();
	Model* tarta = new Model();
	loader->setScala(3);
	loader->LoadModel("objects\\Cake.obj");

	*tarta = loader->GetModel();
	tarta->setPos(Vector3D(20.0f, 10.0f, 10.0f));
	tarta->setAngulo(Vector3D(0.0f, 0.0f, 180.0f));
	tarta->setOrientationSpeed(Vector3D(0.0f, 0.5f, 0.0f));
	tarta->setSpeed(Vector3D(0.0f, 0.0f, 0.0f));
	tarta->PaintColor(Color(1.0f, 1.0f, 1.0f));
	escenaUsando->AddGameObject(tarta);
}
void Scene::GameOver(Scene* escenaUsando) {

	std::cout << "final" << std::endl;
	Text* endText = new Text("PEREDISTE");
	endText->setPos(Vector3D(20.0f, 15.0f, 10.0f));
	endText->setAngulo(Vector3D(0.0f, 0.0f, 0.0f));
	endText->setOrientationSpeed(Vector3D(0.0f, 0.0f, 0.0f));
	endText->setRgb(Color(1.0f, 1.0f, 1.0f));
	escenaUsando->AddGameObject(endText);


	srand(time(NULL));
	for (int i = 0; i < 20; i++)
	{
		ModelLoader* loaderPEr = new ModelLoader();
		Model* objetoPer = new Model();
		loaderPEr->setScala(rand() % 3 + 1);
		loaderPEr->LoadModel("objects\\" + objetos[rand() % 7] + ".obj");

		*objetoPer = loaderPEr->GetModel();
		objetoPer->setPos(Vector3D(static_cast <float>(rand() % 10), static_cast <float>(rand() % 10) / 10, static_cast <float>(rand() % 9) / 10));//2,2,2
		objetoPer->setAngulo(Vector3D(0.0f, 0.0f, 180.0f));
		objetoPer->setOrientationSpeed(Vector3D(0.2f, 0.2f, 0.2f)); // 0, 0.5, 0
		objetoPer->setSpeed(Vector3D(static_cast <float>(rand() % 4) / 10, static_cast <float>(rand() % 4) / 10, 0.0f));
		objetoPer->PaintColor(Color(1.0f, 1.0f, 1.0f));
		escenaUsando->AddGameObject(objetoPer);
		loader->Clear();

	}
}

void Scene::Mercadero(Scene* escenaUsando) {


	Text* dialogo = new Text("¡Hola! ¿Quieres que repare tu nave?   Y: 1 N: 2");
	dialogo->setPos(Vector3D(5.0f, 2.0f, 0.0f));
	dialogo->setAngulo(Vector3D(0.0f, 0.0f, 0.0f));
	dialogo->setOrientationSpeed(Vector3D(0.0f, 0.0f, 0.0f));
	dialogo->setRgb(Color(1.0f, 1.0f, 1.0f));
	escenaUsando->AddGameObject(dialogo);
	escenaUsando->AddGameObject(comerciante);

	ModelLoader* loader = new ModelLoader();

	loader->setScala(1.0f);
	loader->LoadModel("objects\\Mechanic.obj");
	*Mecanico = loader->GetModel();
	Mecanico->setPos(Vector3D(20.0f, 5.0f, -10.0f));
	Mecanico->setAngulo(Vector3D(10.0f, 90.0f, 90.0f));
	Mecanico->setOrientationSpeed(Vector3D(0.0f, 0.0f, 0.0f));
	Mecanico->setSpeed(Vector3D(0.1f, 0.0f, 0.0f));
	Mecanico->PaintColor(Color(1.0f, 1.0f, 1.0f));
	loader->Clear();


	escenaUsando->AddGameObject(Mecanico);

}