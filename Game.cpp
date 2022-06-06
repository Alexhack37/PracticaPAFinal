#include "Game.h"
#include "Scene.h"
#include <iostream>
#include "Model.h"
#include "ModelLoader.h"
#include "Text.h"
#include "Jugador.h"


// Escenas del juego
Scene* altScene = new(nothrow) Scene();//escena junkblaster
Scene* mainScene = new(nothrow) Scene();//escena primer nivel
Scene* finalBossScene = new(nothrow) Scene();//escena final boss
Scene* endScene = new(nothrow) Scene();//si ganas
Scene* gameOver = new(nothrow) Scene();//si pierdes
Mercader* comerciante = new Mercader();



//Objetos en el juego
Model* Mecanico = new Model();
ModelLoader* loader = new ModelLoader();
Teapot* teapot = new Teapot();
Teapot* teapotB = new Teapot();
Teapot* teapotA = new Teapot();
Model* Refresco = new Model();
Model* Burger = new Model();
Model* Cake = new Model();
Model* CupcakeCherry = new Model();
Model* SodaLataTria = new Model();
FinalBoss* boss = new FinalBoss();

//Relacionados con el arma y los disparos

int modoDisparo = mainScene->tuArma->getShootMode();
int modoDisparo1 = altScene->tuArma->getShootMode();
int modoDisparo2 = finalBossScene->tuArma->getShootMode();

Proyectil* bala = new Proyectil();

//Metodo que procesa los disparos
void Game::Disparo(Scene* scene) {

	//int modoDisparo = scene->tuArma->getShootMode();
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
	player.cambiarMunicion(-1.0f);
	cout << this->player.getMunicion() << endl;

}


int i = 0;
void Game::ProcessKeyPressed(unsigned char key, int px, int py) {
	//std::cout << "texto " << key << std::endl;
	this->escenaActual->ProcessKeyPressed(key, px, py);

	//if (key == 'm' && escenas.size() == 2) {
	//
	//	if (i == 1) {
	//		Text* aviso = new Text("Ya esta el mecanico aqui");
	//		aviso->setPos(Vector3D(5.0f, 10.0f, 0.0f));
	//		aviso->setAngulo(Vector3D(0.0f, 0.0f, 0.0f));
	//		aviso->setOrientationSpeed(Vector3D(0.0f, 0.0f, 0.0f));
	//		aviso->setRgb(Color(1.0f, 1.0f, 1.0f));
	//		mainScene->AddGameObject(aviso);
	//	}
	//	else {
	//		Mercadero();
	//		i = 1;
	//	}
	//
	//}
	if (key == 't' && escenas.size() == 2) {
		//std::cout << mainScene->Size() << std::endl;
		//std::cout << "ultimo borrado" << i << std::endl;
		mainScene->DeleteLastGameObject();
		//std::cout << mainScene->Size() << std::endl;
	}
	if (key == 'e' && escenaActual == altScene) {
		Escena1();
	}
	
	if (key == 'y' && escenas.size() == 3) {
		//std::cout << mainScene->Size() << std::endl;
		//std::cout << "ultimo borrado" << i << std::endl;
		finalBossScene->DeleteLastGameObject();
		std::cout << mainScene->Size() << escenas.size() << std::endl;
		if (finalBossScene->Size()) {
			Congratulations();
		}
	}

	//if (key == '1' && escenas.size() == 2) {
	//	//reparar vida
	//	if (player->getVida() == 100.0f) {
	//		Text* aviso = new Text("Vida al maximo");
	//		aviso->setPos(Vector3D(25.0f, 10.0f, 0.0f));
	//		aviso->setAngulo(Vector3D(0.0f, 0.0f, 0.0f));
	//		aviso->setOrientationSpeed(Vector3D(0.0f, 0.0f, 0.0f));
	//		aviso->setRgb(Color(1.0f, 1.0f, 1.0f));
	//		mainScene->AddGameObject(aviso);
	//
	//
	//	}
	//	else {
	//		player->setVida(100.0f);
	//	}
	//
	//
	//}
	//if (key == '2' && escenas.size() == 2) {
	//	//Mercadero();
	//	if (i == 1) {
	//		Text* dialogo = new Text("El mecanico se ha ido");
	//		dialogo->setPos(Vector3D(30.0f, 2.0f, 0.0f));
	//		dialogo->setAngulo(Vector3D(0.0f, 0.0f, 0.0f));
	//		dialogo->setOrientationSpeed(Vector3D(0.0f, 0.0f, 0.0f));
	//		dialogo->setRgb(Color(1.0f, 1.0f, 1.0f));
	//		mainScene->AddGameObject(dialogo);
	//
	//	}
	//	else {
	//		i = 1;
	//		std::cout << "texto" << i << std::endl;
	//		mainScene->DeleteLastGameObject();
	//		mainScene->DeleteLastGameObject();
	//		mainScene->DeleteLastGameObject();
	//
	//	}
	//}
	
	////Botones de disparo
	if (key == 'f' && escenas.size() == 1) {
		altScene->tuArma->Dispara();
		if (modoDisparo1 == 0) {

			Disparo(altScene);
		}
	}

	if (key == 'f' && escenas.size() == 2) {
		mainScene->tuArma->Dispara();
		if (modoDisparo == 0) {
		

			Disparo(mainScene);

		}
	}
	else if (key == 'p' || key == 'P') {
		
		//cout << mainScene->checkObjetIndex(2) << endl;
		mainScene->checkObjetIndex(2);
		//cout << altScene->checkObjetIndex() << endl;
		//altScene->DeleteGameObject(5);
		

	}

	if (key == 'f' && escenas.size() == 3) {
		finalBossScene->tuArma->Dispara();
		if (modoDisparo == 0) {
			Disparo(finalBossScene);
		}
	}
	 if (key == 'd' || key == 'D') {

		finalBossScene->tuMirila->CambiarScope();
		//this->tuMirila->setAngulo(vectorDisparoAdapt);


	}
	if (key == 's' || key == 'S') {
		mainScene->tuArma->setAngulo(Vector3D(0.0, 0.0, 90.0));
		mainScene->tuMirila->setAngulo(Vector3D(0.0, 0.0, 90.0));
		altScene->tuArma->setAngulo(Vector3D(0.0, 0.0, 90.0));
		altScene->tuMirila->setAngulo(Vector3D(0.0, 0.0, 90.0));
		finalBossScene->tuArma->setAngulo(Vector3D(0.0, 0.0, 90.0));
		finalBossScene->tuMirila->setAngulo(Vector3D(0.0, 0.0, 90.0));
	}
}

//Movimiento del raton
void Game::ProcessMouseMovement(int x, int y) {
	//Se dividen entre 20 para reducir la sensibilidad
	x = x / 10;
	y = y / 10;
	this->escenaActual->ProcessMouseMovement(x, y);

}


//Botones del raton
void Game::ProcessMouseClick(int button, int state, int x, int y) {
	/*std::cout << "click" << button<< std::endl;
	std::cout << "click" << x << " + "<< y << std::endl;*/
	if (x >350 && y>400 && escenaActual == altScene) {
		Escena1();
	}

}


//Inicia el juego
void Game::Init() {

	//texto

	Text* intro = new Text("Jugar");

	intro->setPos(Vector3D(25.0f, 10.0f, 10.0f));
	intro->setAngulo(Vector3D(0.0f, 0.0f, 0.0f));
	intro->setOrientationSpeed(Vector3D(0.0f, 0.0f, 0.0f));
	intro->setRgb(Color(1.0f, 1.0f, 1.0f));
	altScene->AddGameObject(intro);

	Text* nombres = new Text("Alejandro Cavero y Luis Mateos Sanchez");

	nombres->setPos(Vector3D(25.0f, 5.0f, 10.0f));
	nombres->setAngulo(Vector3D(0.0f, 0.0f, 0.0f));
	nombres->setOrientationSpeed(Vector3D(0.0f, 0.0f, 0.0f));
	nombres->setRgb(Color(1.0f, 1.0f, 0.0f));
	altScene->AddGameObject(nombres);


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
	
	altScene->AddGameObject(Masterblaster);
	loader->Clear();

	Teapot* teapot = new Teapot();
	teapot->setAngulo(Vector3D(30.0f, -60.0f, -10.0f));
	teapot->setPos(Vector3D(2.0f, 2.0f, 2.0f));
	teapot->setRgb(Color(1.0f, 1.0f, 1.0f));
	teapot->setOrientationSpeed(Vector3D(0.0f, 5.0f, 0.0f));
	teapot->setSpeed(Vector3D(0.2f,0.1f,0.0f));
	//this->gameObjects.push_back(teapot);
	altScene->AddGameObject(teapot);

	NewScene(altScene);
	this->escenaActual = altScene;

	
}
void Game::Render() {

	this->escenaActual->Render();

}

void Game::Update() {
	/*cout << mainScene->getBounds().getCoordinateY() << endl;
	cout << bala->getPos().getCoordinateX() << endl;*/
	
	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	if (currentTime.count() - this->initialMilliseconds.count() - this->lasUpdatedTime > UPDATE_PERIOD) {
		this->escenaActual->Update(TIME_INCREMENT);
		this->lasUpdatedTime = currentTime.count() - this->initialMilliseconds.count();
	}
	//this->escenaActual->Update();
	//Elimina la bala cuando llega al limite de la escena
	//f (bala->getPos().getCoordinateZ() == 1.0f ) {
	//	//cout << escenas.size() << endl;
	//	if (escenas.size() == 1) {
	//		//cout << "bala borrada" << endl;
	//		altScene->DeleteObjectByMyId(10);
	//	}
	//	if (escenas.size() == 2 ) {
	//		//cout << "bala borrada" << endl;
	//		mainScene->DeleteObjectByMyId(10);
	//	}
	//	if (escenas.size() == 3) {
	//		//cout << "bala borrada" << endl;
	//		finalBossScene->DeleteObjectByMyId(10);
	//	}
	//
	//
	//cout << escenas.size() << endl;
	
	if (escenas.size() == 2) {
		
		if (bala->getPos().getCoordinateX() > Refresco->getPos().getCoordinateX() && bala->getPos().getCoordinateX() < loader->getHeight() + Refresco->getPos().getCoordinateX()
			&& bala->getPos().getCoordinateY() > Refresco->getPos().getCoordinateY() && bala->getPos().getCoordinateY() < loader->getLength() + Refresco->getPos().getCoordinateY()) {
			mainScene->DeleteObjectByMyId(1);
		}
		if (bala->getPos().getCoordinateX() > teapot->getPos().getCoordinateX() && bala->getPos().getCoordinateX() < loader->getHeight() + teapot->getPos().getCoordinateX()
			&& bala->getPos().getCoordinateY() > teapot->getPos().getCoordinateY() && bala->getPos().getCoordinateY() < loader->getLength() + teapot->getPos().getCoordinateY()
			&& bala->getPos().getCoordinateZ() > teapot->getPos().getCoordinateZ() && bala->getPos().getCoordinateZ() < loader->getWidth() + teapot->getPos().getCoordinateZ()) {
			mainScene->DeleteObjectByMyId(2);
			player.setVida(50.0f);
			cout << player.getVida() << endl;

		}
		
		if (bala->getPos().getCoordinateX() > Burger->getPos().getCoordinateX() && bala->getPos().getCoordinateX() < loader->getHeight() + Burger->getPos().getCoordinateX()
			&& bala->getPos().getCoordinateY() > Burger->getPos().getCoordinateY() && bala->getPos().getCoordinateY() < loader->getLength() + Burger->getPos().getCoordinateY()) {
			mainScene->DeleteObjectByMyId(3);
		}
		if (bala->getPos().getCoordinateX() > Cake->getPos().getCoordinateX() && bala->getPos().getCoordinateX() < loader->getHeight() + Cake->getPos().getCoordinateX()
			&& bala->getPos().getCoordinateY() > Cake->getPos().getCoordinateY() && bala->getPos().getCoordinateY() < loader->getLength() + Cake->getPos().getCoordinateY()) {
			mainScene->DeleteObjectByMyId(4);
		}
		if (bala->getPos().getCoordinateX() > CupcakeCherry->getPos().getCoordinateX() && bala->getPos().getCoordinateX() < loader->getHeight() + CupcakeCherry->getPos().getCoordinateX()
			&& bala->getPos().getCoordinateY() > CupcakeCherry->getPos().getCoordinateY() && bala->getPos().getCoordinateY() < loader->getLength() + CupcakeCherry->getPos().getCoordinateY()) {
			mainScene->DeleteObjectByMyId(5);
		}
		if (bala->getPos().getCoordinateX() > SodaLataTria->getPos().getCoordinateX() && bala->getPos().getCoordinateX() < loader->getHeight() + SodaLataTria->getPos().getCoordinateX()
			&& bala->getPos().getCoordinateY() > SodaLataTria->getPos().getCoordinateY() && bala->getPos().getCoordinateY() < loader->getLength() + SodaLataTria->getPos().getCoordinateY()) {
			mainScene->DeleteObjectByMyId(6);
		}
		////funciona pero mal MIRAR TODO no es un for porq quiero que sea todo el tiempo la comprobacion pero no un while porq seria sin fin y crashea el programa
		//for (size_t i = 0; i < mainScene->gameObjects.size(); i++)
		//{
		//	if (bala->getPos().getCoordinateX() > mainScene->gameObjects[i]->getPos().getCoordinateX() && bala->getPos().getCoordinateX() < loader->getHeight() + mainScene->gameObjects[i]->getPos().getCoordinateX()
		//		&& bala->getPos().getCoordinateY() > mainScene->gameObjects[i]->getPos().getCoordinateY() && bala->getPos().getCoordinateY() < loader->getLength() + mainScene->gameObjects[i]->getPos().getCoordinateY()
		//		&& mainScene->gameObjects[i]->getId() ) {
		//		mainScene->DeleteObjectByMyId(i);
		//	}
		//}
		if (mainScene->Size() == 0) {
			EscenaFinal();
		}
	}
	if (escenas.size() == 3) {
		if (bala->getPos().getCoordinateX() > boss->getPos().getCoordinateX() && bala->getPos().getCoordinateX() < loader->getHeight() + boss->getPos().getCoordinateX()
			&& bala->getPos().getCoordinateY() > boss->getPos().getCoordinateY() && bala->getPos().getCoordinateY() < loader->getLength() + boss->getPos().getCoordinateY()) {
			boss->setVida(boss->getVida() - 10.0f);
			cout << boss->getVida() << endl;
			if (boss->getVida() < 0.0f) {
				finalBossScene->DeleteObjectByMyId(9);
				Congratulations();
			}
		}
		if (bala->getPos().getCoordinateX() > teapotA->getPos().getCoordinateX() && bala->getPos().getCoordinateX() < loader->getHeight() + teapotA->getPos().getCoordinateX()
			&& bala->getPos().getCoordinateY() > teapotA->getPos().getCoordinateY() && bala->getPos().getCoordinateY() < loader->getLength() + teapotA->getPos().getCoordinateY()) {
			finalBossScene->DeleteObjectByMyId(7);
			if (player.getVida() == 25.f) {
				//lol
			}
			else {
				player.setVida(25.0f);
			}
		}
		if (bala->getPos().getCoordinateX() > teapotB->getPos().getCoordinateX() && bala->getPos().getCoordinateX() < loader->getHeight() + teapotB->getPos().getCoordinateX()
			&& bala->getPos().getCoordinateY() > teapotB->getPos().getCoordinateY() && bala->getPos().getCoordinateY() < loader->getLength() + teapotB->getPos().getCoordinateY()) {
			finalBossScene->DeleteObjectByMyId(8);
			if (player.getVida()==25.f) {
				//termianr partida
				GameOver();
			}else{
				player.setVida(25.0f);
			}
			
		}
		//if (player->getVida() < 0.0f) {
		//	cout << "lol" << endl;
		//	//terminar game aqui
		//}
	}
	
}


void Game::NewScene(Scene* object) {

	escenas.push_back(object);

};

//escena principal
void Game::Escena1() {
	//desafortunadamente no pudo llamar a objetos dentro de funciones sin hacerlos globales, y si lo fueran se acoplan todos juntos al no crear 
	//una instanciacion nueva en cada bucle :(
	/*
	srand(time(NULL));
	for (int i = 0; i < 2; i++)			
	{
		ModelLoader* loaderPEr = new ModelLoader();
		Model* objetoPer = new Model();
		loaderPEr->setScala(rand() % 3 + 1);
		loaderPEr->LoadModel("objects\\" + objetos[rand()%7] + ".obj");

		*objetoPer = loaderPEr->GetModel();
		objetoPer->setPos(Vector3D(static_cast <float>(rand() % 100), static_cast <float>(rand() % 10) / 10, static_cast <float>(rand() % 9) / 10));//2,2,2
		objetoPer->setAngulo(Vector3D(0.0f, 0.0f, 180.0f));
		objetoPer->setOrientationSpeed(Vector3D(0.2f,0.2f,0.2f)); // 0, 0.5, 0
		objetoPer->setSpeed(Vector3D(static_cast <float>(rand() % 4) / 10, static_cast <float>(rand() % 4) / 10, 0.0f));
		objetoPer->setSpeed(Vector3D(0.0f, 0.0f, 0.0f));
		objetoPer->PaintColor(Color(1.0f, 1.0f,1.0f));
		mainScene->AddGameObject(objetoPer);
		loader->Clear();
		
	}*/

	
	//player->setVida(45.0f);
	
	cout << player.getVida() << endl;
	loader->setScala(1);
	loader->LoadModel("objects\\Soda.obj");
	*Refresco = loader->GetModel();
	Refresco->setPos(Vector3D(24.0f, 10.0f, 5.0f));
	Refresco->setAngulo(Vector3D(180.0f, 0.0f, 0.0f));
	Refresco->setOrientationSpeed(Vector3D(0.0f, 0.5f, 0.0f));
	Refresco->setSpeed(Vector3D(0.0f, 0.0f, 0.0f));
	Refresco->PaintColor(Color(1.0f, 1.0f, 1.0f));
	Refresco->setId(1);
	mainScene->AddGameObject(Refresco);
	loader->Clear();

	teapot->setAngulo(Vector3D(30.0f, -60.0f, -10.0f));
	teapot->setPos(Vector3D(20.0f, 10.0f, 5.0f));
	teapot->setRgb(Color(1.0f, 1.0f, 1.0f));
	teapot->setOrientationSpeed(Vector3D(0.0f, 0.5f, 0.0f));
	teapot->setSpeed(Vector3D(0.0f, 0.0f, 0.0f));
	teapot->setId(2);
	mainScene->AddGameObject(teapot);

	loader->setScala(5);
	loader->LoadModel("objects\\Burger.obj");
	*Burger = loader->GetModel();
	Burger->setPos(Vector3D(30.0f, 10.0f, 5.0f));
	Burger->setAngulo(Vector3D(180.0f, 0.0f, 0.0f));
	Burger->setOrientationSpeed(Vector3D(0.0f, 0.5f, 0.0f));
	Burger->setSpeed(Vector3D(0.01f, 0.0f, 0.0f));
	Burger->PaintColor(Color(1.0f, 1.0f, 1.0f));
	Burger->setId(3);
	mainScene->AddGameObject(Burger);
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
	mainScene->AddGameObject(Cake);
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
	mainScene->AddGameObject(CupcakeCherry);
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
	mainScene->AddGameObject(SodaLataTria);
	loader->Clear();


	this->escenas.push_back(mainScene);
	this->escenaActual = mainScene;

}

void Game::EscenaFinal() {

	Text* finalbossTexto = new Text("FINNAL BOSS");
	finalbossTexto->setPos(Vector3D(22.0f, 25.0f, 0.0f));
	finalbossTexto->setAngulo(Vector3D(0.0f, 0.0f, 0.0f));
	finalbossTexto->setOrientationSpeed(Vector3D(0.0f, 0.0f, 0.0f));
	finalbossTexto->setRgb(Color(1.0f, 1.0f, 1.0f));
	finalBossScene->AddGameObject(finalbossTexto);



	boss->setSize(2);
	boss->setAngulo(Vector3D(0.0f, 0.0f, 0.0f));
	boss->setPos(Vector3D(24.0f, 10.0f, 5.0f));
	boss->setRgb(Color(0.0f, 0.0f, 1.0f));
	boss->setOrientationSpeed(Vector3D(0.0f, 0.01f, 0.0f));
	boss->setSpeed(Vector3D(0.1f, 0.0f, 0.0f));
	boss->setId(9);
	boss->setVida(100);
	finalBossScene->AddGameObject(boss);


	teapotA->setAngulo(Vector3D(30.0f, -60.0f, -10.0f));
	teapotA->setPos(Vector3D(20.0f, 10.0f, 5.0f));
	teapotA->setRgb(Color(1.0f, 1.0f, 1.0f));
	teapotA->setOrientationSpeed(Vector3D(0.0f, 0.5f, 0.0f));
	teapotA->setSpeed(Vector3D(0.01f, 0.01f, 0.0f));
	teapotA->setId(7);
	finalBossScene->AddGameObject(teapotA);

	teapotB->setAngulo(Vector3D(30.0f, -60.0f, -10.0f));
	teapotB->setPos(Vector3D(30.0f, 20.0f, 5.0f));
	teapotB->setRgb(Color(1.0f, 0.0f, 1.0f));
	teapotB->setOrientationSpeed(Vector3D(0.0f, 0.5f, 0.0f));
	teapotB->setSpeed(Vector3D(-0.01f, -0.01f, 0.0f));
	teapot->setId(8);
	finalBossScene->AddGameObject(teapotB);

	this->escenas.push_back(finalBossScene);
	this->escenaActual = finalBossScene;
}

void Game::Congratulations() {

	std::cout << "final"<< std::endl;
	Text* end = new Text("GANASTE ENHORABUENA");
	end->setPos(Vector3D(20.0f, 15.0f, 10.0f));
	end->setAngulo(Vector3D(0.0f, 0.0f, 0.0f));
	end->setOrientationSpeed(Vector3D(0.0f, 0.0f, 0.0f));
	end->setRgb(Color(1.0f, 1.0f, 1.0f));
	endScene->AddGameObject(end);

	ModelLoader* loader = new ModelLoader();
	Model* tarta = new Model();
	loader->setScala(3);
	loader->LoadModel("objects\\Cake.obj");

	*tarta = loader->GetModel();
	tarta->setPos(Vector3D(20.0f, 10.0f, 10.0f));//2,2,2
	tarta->setAngulo(Vector3D(0.0f, 0.0f, 180.0f));
	tarta->setOrientationSpeed(Vector3D(0.0f, 0.5f, 0.0f)); // 0, 0.5, 0
	tarta->setSpeed(Vector3D(0.0f,0.0f,0.0f));
	tarta->PaintColor(Color(1.0f, 1.0f, 1.0f));
	endScene->AddGameObject(tarta);


	this->escenas.push_back(endScene);
	this->escenaActual = endScene;
}
void Game::GameOver() {

	std::cout << "final" << std::endl;
	Text* endText = new Text("PEREDISTE");
	endText->setPos(Vector3D(20.0f, 15.0f, 10.0f));
	endText->setAngulo(Vector3D(0.0f, 0.0f, 0.0f));
	endText->setOrientationSpeed(Vector3D(0.0f, 0.0f, 0.0f));
	endText->setRgb(Color(1.0f, 1.0f, 1.0f));
	gameOver->AddGameObject(endText);


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
		gameOver->AddGameObject(objetoPer);
		loader->Clear();

	}



	this->escenas.push_back(gameOver);
	this->escenaActual = gameOver;
}

void Game::Mercadero() {

	
	Text* dialogo = new Text("¡Hola! ¿Quieres que repare tu nave?   Y: 1 N: 2");
	dialogo->setPos(Vector3D(5.0f, 2.0f, 0.0f));
	dialogo->setAngulo(Vector3D(0.0f, 0.0f, 0.0f));
	dialogo->setOrientationSpeed(Vector3D(0.0f, 0.0f, 0.0f));
	dialogo->setRgb(Color(1.0f, 1.0f, 1.0f));
	mainScene->AddGameObject(dialogo);

	//Movidaas de mercader
	//AQUI CURAR NAVE O JUGADOR

	//movidas de añadir objeto personlaizado
	mainScene->AddGameObject(comerciante);

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


	mainScene->AddGameObject(Mecanico);

}