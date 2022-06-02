#include "Scene.h"
#include "Solid.h"

#include "Camera.h"
#include "Proyectil.h"
#include "ProyectilArea.h"
#include "camera_fps.h"
#include <iostream>



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

float Scene::GetBala() {
		
	return this->gameObjects[5]->getPos().getCoordinateX();
	
}
void Scene::GetBalaDato() {
	//cout << this->gameObjects[5]->getPos().getCoordinateX() << endl;

}
float Scene::GetBalaY() {
	return this->gameObjects[5]->getPos().getCoordinateY();

}

void Scene::Update(const float& time) {

	this->camera->Update(0);
	this->tuArma->Update(time);
	this->tuMirila->Update(time);
	for (size_t i = 0; i < gameObjects.size(); i++) {
		gameObjects[i]->Update(time);

	}
	checkBoundary();


}

void Scene::ProcessMouseMovement(int x, int y) {

	this->tuArma->ProcessMouseMovement(x, y);
	this->tuMirila->ProcessMouseMovement(x, y);
}
/**/
void Scene::ProcessKeyPressed(unsigned char key, int px, int py) {
	
	int modoDisparo = this->tuArma->getShootMode();
	float estabilizadoX = 0.01;
	float estabilizadoY = 0.01;

	Vector3D vectorDisparo = Vector3D(this->tuArma->getAngulo().getCoordinateY() * -1, this->tuArma->getAngulo().getCoordinateX(), -1.0f);

	int saltosEstablX = this->tuArma->getAngulo().getCoordinateX() / 5;
	int saltosEstablY = this->tuArma->getAngulo().getCoordinateY() / 5;

	estabilizadoX += 0.001 * saltosEstablX;
	estabilizadoY += 0.001 * saltosEstablY;

	//Velocidad y trayectorias segun la mira
	Vector3D vectorDisparoAdapt = vectorDisparo.MultValues(Vector3D(estabilizadoX, estabilizadoY, 0.5f));

	


	/*
	if (key == 'f' || key == 'F') {
		this->tuArma->Dispara();
		if (modoDisparo == 0) {
			//std::cout << "Disparo Normal" << std::endl;
			Proyectil* bala = new Proyectil(this->tuArma->getPos(), Vector3D(0.0, 0.0, 0.0),
				Color(1.0, 0.0, 0.0), Vector3D(0.0, 0.0, 0.0),
				vectorDisparoAdapt);
			this->AddGameObject(bala);
		
			
			//mainScene->GetBalaDato();
			int x = this->gameObjects[6]->getPos().getCoordinateX();
			int y = this->gameObjects[6]->getPos().getCoordinateY();
			//int x = this->gameObjects[gameObjects.size()-1]->getPos().getCoordinateX();
			//int y = this->gameObjects[gameObjects.size()-1]->getPos().getCoordinateY();
			std::cout << "ESTE " << x << std::endl;
			if (x == this->gameObjects[this->gameObjects.size() -2]->getPos().getCoordinateX() && y == this->gameObjects[gameObjects.size() -2]->getPos().getCoordinateY()) {
				std::cout << "HIT " << std::endl;
			}
			if (this->Size() > 7) {
				
				
				this->DeleteGameObject();
			}
			
		}



		else if (modoDisparo == 1) {
			std::cout << "Disparo Veloz" << std::endl;
			Proyectil* bala = new Proyectil(this->tuArma->getPos(), Vector3D(0.0, 0.0, 0.0),
				Color(1.0, 0.0, 0.0), Vector3D(0.0, 0.0, 0.0),
				vectorDisparoAdapt.MultValues(Vector3D(10.0, 10.0, 10.0)));
			this->AddGameObject(bala);
		}
		else if (modoDisparo == 2) {
			std::cout << "Disparo en área" << std::endl;
			ProyectilArea* bala = new ProyectilArea(this->tuArma->getPos(), this->tuArma->getAngulo(),
				Color(0.0, 1.0, 0.7), Vector3D(0.0, 0.0, 0.0),
				vectorDisparoAdapt);
			this->AddGameObject(bala);
		}
		else if (modoDisparo == 3) {

		}
	}
	else if (key == 'd' || key == 'D') {

		this->tuMirila->CambiarScope();
		//this->tuMirila->setAngulo(vectorDisparoAdapt);


	}
	else if (key == 'h' || key == 'H') {
		this->tuArma->setShootMode(0);
	}
	else if (key == 'j' || key == 'J') {
		this->tuArma->setShootMode(1);
	}
	else if (key == 'k' || key == 'K') {
		this->tuArma->setShootMode(2);
	}
	else if (key == 'l' || key == 'L') {
		this->tuArma->setShootMode(3);
	}
	else if (key == 'q' || key == 'Q') {
		std::cout << "El vector disparo  es " << vectorDisparo.getCoordinateX() << " " << vectorDisparo.getCoordinateY() << " " << vectorDisparo.getCoordinateZ() << std::endl;
		std::cout << "El vector disparoAdaptado  es " << vectorDisparoAdapt.getCoordinateX() << " " << vectorDisparoAdapt.getCoordinateY() << " " << vectorDisparoAdapt.getCoordinateZ() << std::endl;
		std::cout << "El vector es Arma " << this->tuArma->getAngulo().getCoordinateX() << " " << this->tuArma->getAngulo().getCoordinateY() << " " << this->tuArma->getAngulo().getCoordinateZ() << std::endl;
		std::cout << "El vector es Mira " << this->tuMirila->getAngulo().getCoordinateX() << " " << this->tuMirila->getAngulo().getCoordinateY() << " " << this->tuMirila->getAngulo().getCoordinateZ() << std::endl;
	}
	else if (key == 's' || key == 'S') {
		this->tuArma->setAngulo(Vector3D(0.0, 0.0, 90.0));
		this->tuMirila->setAngulo(Vector3D(0.0, 0.0, 90.0));
	}*/
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

			//cout << gameObjects[i]->getId() << endl;
			return true;
			//int n = gameObjects[i]->getId();
		}
		return false;

	}
	
}

void Scene::checkBoundary() {
	for (size_t i = 0; i < gameObjects.size(); i++)
	{
		if (gameObjects[i]->getPos().getCoordinateX() > boundary.getCoordinateX() || gameObjects[i]->getPos().getCoordinateX() < 0.0f) {
			//gameObjects[i]->setSpeed(gameObjects[i]->getSpeed().Product(-1));

			gameObjects[i]->setSpeed(gameObjects[i]->getSpeed().MultValues(Vector3D(-1.0, 1.0, 1.0)));	
			//gameObjects[i]->setSpeed(gameObjects[i]->getSpeed() * Vector3D(-1.0, 1.0, 1.0));	
		}
		if (gameObjects[i]->getPos().getCoordinateY() > boundary.getCoordinateY() || gameObjects[i]->getPos().getCoordinateY() < 0.0f) {
			//gameObjects[i]->setSpeed(gameObjects[i]->getSpeed().Product(-1.0f));		
			gameObjects[i]->setSpeed(gameObjects[i]->getSpeed().MultValues(Vector3D(1.0, -1.0, 1.0)));
			//gameObjects[i]->setSpeed(gameObjects[i]->getSpeed() * Vector3D(1.0, -1.0, 1.0));
		}						

		if (gameObjects[i]->getPos().getCoordinateZ() > boundary.getCoordinateZ() || gameObjects[i]->getPos().getCoordinateZ() < 0.0f) {
			//gameObjects[i]->setSpeed(gameObjects[i]->getSpeed().Product(-1.0f));
			gameObjects[i]->setSpeed(gameObjects[i]->getSpeed().MultValues(Vector3D(1.0, 1.0, -1.0)));
			//gameObjects[i]->setSpeed(gameObjects[i]->getSpeed()*(Vector3D(1.0, 1.0, -1.0));
		}

		
	}
}