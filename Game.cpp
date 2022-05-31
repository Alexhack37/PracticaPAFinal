#include "Game.h"
#include "Scene.h"
#include <iostream>
#include "Model.h"
#include "ModelLoader.h"
#include "Text.h"



Scene* altScene = new(nothrow) Scene();
Scene* mainScene = new(nothrow) Scene();
Scene* finalBossScene = new(nothrow) Scene();
Scene* endScene = new(nothrow) Scene();
Mercader* comerciante = new Mercader();
Jugador* player = new Jugador(100.f);



Model* Mecanico = new Model();

//Boton* primerBoton = new Boton();



int i = 0;
void Game::ProcessKeyPressed(unsigned char key, int px, int py) {
	//std::cout << "texto " << key << std::endl;
	this->escenaActual->ProcessKeyPressed(key, px, py);

	if (key == 'm' && escenas.size() == 2) {

		if (i == 1) {
			Text* aviso = new Text("Ya esta el mecanico aqui");
			aviso->setPos(Vector3D(5.0f, 10.0f, 0.0f));
			aviso->setAngulo(Vector3D(0.0f, 0.0f, 0.0f));
			aviso->setOrientationSpeed(Vector3D(0.0f, 0.0f, 0.0f));
			aviso->setRgb(Color(1.0f, 1.0f, 1.0f));
			mainScene->AddGameObject(aviso);
		}
		else {
			Mercadero();
			i = 1;
		}

	}
	if (key == 't' && escenas.size() == 2) {
		//std::cout << mainScene->Size() << std::endl;
		//std::cout << "ultimo borrado" << i << std::endl;
		mainScene->DeleteLastGameObject();
		//std::cout << mainScene->Size() << std::endl;
	}
	if (key == 'e' && escenaActual == altScene) {
		Escena1();
	}
	if (mainScene->Size() == 0 && escenas.size() == 2) {


		EscenaFinal();
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

	if (key == '1' && escenas.size() == 2) {
		//reparar vida
		if (player->getVida() == 100.0f) {
			Text* aviso = new Text("Vida al maximo");
			aviso->setPos(Vector3D(25.0f, 10.0f, 0.0f));
			aviso->setAngulo(Vector3D(0.0f, 0.0f, 0.0f));
			aviso->setOrientationSpeed(Vector3D(0.0f, 0.0f, 0.0f));
			aviso->setRgb(Color(1.0f, 1.0f, 1.0f));
			mainScene->AddGameObject(aviso);


		}
		else {
			player->setVida(100.0f);
		}


	}
	if (key == '2' && escenas.size() == 2) {
		//Mercadero();
		if (i == 1) {
			Text* dialogo = new Text("El mecanico se ha ido");
			dialogo->setPos(Vector3D(30.0f, 2.0f, 0.0f));
			dialogo->setAngulo(Vector3D(0.0f, 0.0f, 0.0f));
			dialogo->setOrientationSpeed(Vector3D(0.0f, 0.0f, 0.0f));
			dialogo->setRgb(Color(1.0f, 1.0f, 1.0f));
			mainScene->AddGameObject(dialogo);

		}
		else {
			i = 1;
			std::cout << "texto" << i << std::endl;
			mainScene->DeleteLastGameObject();
			mainScene->DeleteLastGameObject();
			mainScene->DeleteLastGameObject();

		}
	}

	//arma related things

	int modoDisparo = mainScene->tuArma->getShootMode();
	int modoDisparo1 = altScene->tuArma->getShootMode();
	int modoDisparo2 = finalBossScene->tuArma->getShootMode();
	float estabilizadoX = 0.01;
	float estabilizadoY = 0.01;

	float estabilizadoX1 = 0.01;
	float estabilizadoY1= 0.01;

	float estabilizadoX2= 0.01;
	float estabilizadoY2= 0.01;

	Vector3D vectorDisparo = Vector3D(mainScene->tuArma->getAngulo().getCoordinateY() * -1, mainScene->tuArma->getAngulo().getCoordinateX(), -1.0f);
	Vector3D vectorDisparo1 = Vector3D(altScene->tuArma->getAngulo().getCoordinateY() * -1, altScene->tuArma->getAngulo().getCoordinateX(), -1.0f);
	Vector3D vectorDisparo2 = Vector3D(finalBossScene->tuArma->getAngulo().getCoordinateY() * -1, finalBossScene->tuArma->getAngulo().getCoordinateX(), -1.0f);

	int saltosEstablX = mainScene->tuArma->getAngulo().getCoordinateX() / 5;
	int saltosEstablY = mainScene->tuArma->getAngulo().getCoordinateY() / 5;


	int saltosEstablX1 = altScene->tuArma->getAngulo().getCoordinateX() / 5;
	int saltosEstablY1 = altScene->tuArma->getAngulo().getCoordinateY() / 5;

	
	int saltosEstablX2 = finalBossScene->tuArma->getAngulo().getCoordinateX() / 5;
	int saltosEstablY2 = finalBossScene->tuArma->getAngulo().getCoordinateY() / 5;

	estabilizadoX += 0.001 * saltosEstablX;
	estabilizadoY += 0.001 * saltosEstablY;
	estabilizadoX1 += 0.001 * saltosEstablX1;
	estabilizadoY1 += 0.001 * saltosEstablY1;

	estabilizadoX2 += 0.001 * saltosEstablX2;
	estabilizadoY2 += 0.001 * saltosEstablY2;


	//Velocidad y trayectorias segun la mira
	Vector3D vectorDisparoAdapt = vectorDisparo.MultValues(Vector3D(estabilizadoX, estabilizadoY, 0.5f));
	Vector3D vectorDisparoAdapt1 = vectorDisparo1.MultValues(Vector3D(estabilizadoX1, estabilizadoY1, 0.5f));
	Vector3D vectorDisparoAdapt2 = vectorDisparo2.MultValues(Vector3D(estabilizadoX1, estabilizadoY1, 0.5f));
	if (key == 'f' && escenas.size() == 1) {
		altScene->tuArma->Dispara();
		if (modoDisparo1 == 0) {
			//std::cout << "Disparo Normal" << std::endl;
			Proyectil* bala = new Proyectil(altScene->tuArma->getPos(), Vector3D(0.0, 0.0, 0.0),
				Color(1.0, 0.0, 0.0), Vector3D(0.0, 0.0, 0.0),
				vectorDisparoAdapt1);
			altScene->AddGameObject(bala);

			if (mainScene->Size() > 7) {


				altScene->DeleteGameObject();
			}

		}
	}
	else if (key == 's' || key == 'S') {
		altScene->tuArma->setAngulo(Vector3D(0.0, 0.0, 90.0));
		altScene->tuMirila->setAngulo(Vector3D(0.0, 0.0, 90.0));
	}

	if (key == 'f' && escenas.size() == 2) {
		mainScene->tuArma->Dispara();
		if (modoDisparo == 0) {
			//std::cout << "Disparo Normal" << std::endl;
			Proyectil* bala = new Proyectil(mainScene->tuArma->getPos(), Vector3D(0.0, 0.0, 0.0),
				Color(1.0, 0.0, 0.0), Vector3D(0.0, 0.0, 0.0),
				vectorDisparoAdapt);
			mainScene->AddGameObject(bala);


			//mainScene->GetBalaDato();
			int x = mainScene->gameObjects[6]->getPos().getCoordinateX();
			int y = mainScene->gameObjects[6]->getPos().getCoordinateY();
			std::cout << "BULLET " << x << std::endl;
			std::cout << "BULLET " << y << std::endl;
			std::cout << "OBJECT " << mainScene->gameObjects[5]->getPos().getCoordinateX() << std::endl;
			std::cout << "OBJECT " << mainScene->gameObjects[5]->getPos().getCoordinateY() << std::endl;
			if (x == mainScene->gameObjects[5]->getPos().getCoordinateX()) {
				std::cout << "HIT " << std::endl;
				mainScene->gameObjects.erase(mainScene->gameObjects.begin() + 5);
			}
			if (x == mainScene->gameObjects[4]->getPos().getCoordinateX()) {
				std::cout << "HIT " << std::endl;
				mainScene->gameObjects.erase(mainScene->gameObjects.begin() + 4);
			}
			if (x == mainScene->gameObjects[3]->getPos().getCoordinateX()) {
				std::cout << "HIT " << std::endl;
				mainScene->gameObjects.erase(mainScene->gameObjects.begin() + 2);
			}
			if (x == mainScene->gameObjects[2]->getPos().getCoordinateX()) {
				std::cout << "HIT " << std::endl;
				mainScene->gameObjects.erase(mainScene->gameObjects.begin() + 5);
			}
			if (x == mainScene->gameObjects[1]->getPos().getCoordinateX()) {
				std::cout << "HIT " << std::endl;
				mainScene->gameObjects.erase(mainScene->gameObjects.begin() + 5);
			}
			if (mainScene->Size() > 7) {


				mainScene->DeleteGameObject();
			}
		}
	}
	else if (key == 'd' || key == 'D') {

		mainScene->tuMirila->CambiarScope();
		//this->tuMirila->setAngulo(vectorDisparoAdapt);


	}
	else if (key == 's' || key == 'S') {
		mainScene->tuArma->setAngulo(Vector3D(0.0, 0.0, 90.0));
		mainScene->tuMirila->setAngulo(Vector3D(0.0, 0.0, 90.0));
	}

	if (key == 'f' && escenas.size() == 3) {
		finalBossScene->tuArma->Dispara();
		if (modoDisparo == 0) {
			//std::cout << "Disparo Normal" << std::endl;
			Proyectil* bala = new Proyectil(finalBossScene->tuArma->getPos(), Vector3D(0.0, 0.0, 0.0),
				Color(1.0, 0.0, 0.0), Vector3D(0.0, 0.0, 0.0),
				vectorDisparoAdapt2);
			finalBossScene->AddGameObject(bala);


			//mainScene->GetBalaDato();
			int x = finalBossScene->gameObjects[2]->getPos().getCoordinateX();
			if (x == finalBossScene->gameObjects[0]->getPos().getCoordinateX()) {
				std::cout << "HIT " << std::endl;
				finalBossScene->gameObjects.erase(finalBossScene->gameObjects.begin());
			}
			if (finalBossScene->Size() > 7) {


				finalBossScene->DeleteGameObject();
			}
		}
	}
	else if (key == 'd' || key == 'D') {

		finalBossScene->tuMirila->CambiarScope();
		//this->tuMirila->setAngulo(vectorDisparoAdapt);


	}
	else if (key == 's' || key == 'S') {
		finalBossScene->tuArma->setAngulo(Vector3D(0.0, 0.0, 90.0));
		finalBossScene->tuMirila->setAngulo(Vector3D(0.0, 0.0, 90.0));
	}
}

void Game::ProcessMouseMovement(int x, int y) {
	//Se dividen entre 20 para reducir la sensibilidad
	x = x / 10;
	y = y / 10;
	this->escenaActual->ProcessMouseMovement(x, y);

}



void Game::ProcessMouseClick(int button, int state, int x, int y) {
	/*std::cout << "click" << button<< std::endl;
	std::cout << "click" << x << " + "<< y << std::endl;*/
	if (x >350 && y>400 && escenaActual == altScene) {
		Escena1();
	}

}

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
	nombres->setRgb(Color(1.0f, 1.0f, 1.0f));
	altScene->AddGameObject(nombres);


	//modelo personalizado


	ModelLoader* loader = new ModelLoader();
	Model* Masterblaster = new Model();
	loader->setScala(4.0f);
	//loader->LoadModel("objects\\TheSpaceJunker.obj");
	loader->LoadModel("objects\\JUNKBLASTER.obj");


	*Masterblaster = loader->GetModel();
	Masterblaster->setPos(Vector3D(25.0f, 15.0f, 10.0f));
	Masterblaster->setAngulo(Vector3D(0.0f, 0.0f, 180.0f));
	Masterblaster->setOrientationSpeed(Vector3D(0.0f, 0.0f, 0.0f));
	Masterblaster->setSpeed(Vector3D(0.0f, 0.0f, 0.0f));
	Masterblaster->PaintColor(Color(1.0f, 1.0f, 1.0f));
	//Masterblaster->setRgb(Color(1.0f, 1.0f, 1.0f));
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
	
	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	if (currentTime.count() - this->initialMilliseconds.count() - this->lasUpdatedTime > UPDATE_PERIOD) {
		this->escenaActual->Update(TIME_INCREMENT);
		this->lasUpdatedTime = currentTime.count() - this->initialMilliseconds.count();
	}
	//this->escenaActual->Update();

}


void Game::NewScene(Scene* object) {

	escenas.push_back(object);

};

//escena principal
void Game::Escena1() {
	
	srand(time(NULL));
	for (int i = 0; i < 5; i++)			
	{
		ModelLoader* loader = new ModelLoader();
		Model* lata = new Model();
		loader->setScala(rand() % 3 + 1);
		loader->LoadModel("objects\\" + objetos[rand()%7] + ".obj");

		*lata = loader->GetModel();
		lata->setPos(Vector3D(static_cast <float>(rand() % 10), static_cast <float>(rand() % 10) / 10, static_cast <float>(rand() % 9) / 10));//2,2,2
		lata->setAngulo(Vector3D(0.0f, 0.0f, 180.0f));
		lata->setOrientationSpeed(Vector3D(0.2f,0.2f,0.2f)); // 0, 0.5, 0
		lata->setSpeed(Vector3D(static_cast <float>(rand() % 4) / 10, static_cast <float>(rand() % 4) / 10, 0.0f));
		//lata->setRgb(Color(1.0f, 1.0f, 1.0f));
		lata->PaintColor(Color(1.0f, 1.0f,1.0f));
		mainScene->AddGameObject(lata);
		
	}


	Teapot* teapot = new Teapot();
	teapot->setAngulo(Vector3D(30.0f, -60.0f, -10.0f));
	teapot->setPos(Vector3D(20.0f, 10.0f, 2.0f));
	teapot->setRgb(Color(1.0f, 1.0f, 1.0f));
	teapot->setOrientationSpeed(Vector3D(0.0f, 0.5f, 0.0f));
	teapot->setSpeed(Vector3D(0.0f, 0.0f, 0.0f));
	mainScene->AddGameObject(teapot);

	mainScene->GetBalaDato();

	


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



	FinalBoss* boss = new FinalBoss();
	boss->setAngulo(Vector3D(0.0f, 0.0f, 0.0f));
	boss->setPos(Vector3D(25.0f, 15.0f, 10.0f));
	boss->setRgb(Color(0.0f, 0.0f, 1.0f));
	boss->setOrientationSpeed(Vector3D(0.0f, 0.01f, 0.0f));
	boss->setSpeed(Vector3D(0.1f, 0.0f, 0.0f));
	finalBossScene->AddGameObject(boss);

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