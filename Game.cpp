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

void Game::ProcessKeyPressed(unsigned char key, int px, int py) {
	if (key == 't' && escenaActual == mainScene) {
		mainScene->DeleteLastGameObject();
	}
	if (key == 'e' && escenaActual == altScene) {
		escenaActual->Escena1(mainScene);
	}

	if (key == 'y' && escenas.size() == 3) {
		finalBossScene->DeleteLastGameObject();
		if (finalBossScene->Size()) {
			escenaActual->Congratulations(mainScene);
		}
	}
	////Botones de disparo
	if (key == 'f') {
		escenaActual->Disparo(escenaActual);
	}
	if (key == 'p' || key == 'P') {

		escenaActual->checkObjetIndex(2);
	}
	if (key == 'd' || key == 'D') { //mirilla
		escenaActual->tuMirila->CambiarScope();
	}
	if (key == 's' || key == 'S') { //reset camera
		escenaActual->tuArma->setAngulo(Vector3D(0.0, 0.0, 90.0));
		escenaActual->tuMirila->setAngulo(Vector3D(0.0, 0.0, 90.0));
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
	if (x >350 && y>400 && escenaActual == altScene) {
		escenaActual = mainScene;
		escenaActual->Escena1(mainScene);
		NewScene(mainScene);
	}
}

void Game::Init() {
	NewScene(altScene);
	escenaActual = altScene;
	escenaActual->Init(altScene);
}
void Game::NewScene(Scene* object) {
	escenas.push_back(object);
};
void Game::Render() {
	this->escenaActual->Render();
}



void Game::Update() {
	
	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	if (currentTime.count() - this->initialMilliseconds.count() - this->lasUpdatedTime > UPDATE_PERIOD) {
		this->escenaActual->Update(TIME_INCREMENT);
		this->lasUpdatedTime = currentTime.count() - this->initialMilliseconds.count();
	}
	if (escenas.size() == 2 && mainScene->Size() == 0) {
		NewScene(finalBossScene);
		escenaActual = finalBossScene;
		escenaActual->EscenaFinal(finalBossScene);
	}
	if(escenas.size() == 3 && !finalBossScene->checkObjetIndex(9)){
			NewScene(endScene);
			escenaActual = endScene;
			escenaActual->Congratulations(endScene);
	}
	if (escenas.size() == 3 && !finalBossScene->checkObjetIndex(7) && !finalBossScene->checkObjetIndex(8)) {
		NewScene(gameOver);
		escenaActual = gameOver;
		escenaActual->GameOver(gameOver);
	}
}
