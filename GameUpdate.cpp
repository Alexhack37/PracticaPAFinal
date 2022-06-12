#include "GameUpdate.h"
#include "SceneUpdate.h"

SceneUpdate* altScene = new(nothrow) SceneUpdate();//escena junkblaster
SceneUpdate* mainScene = new(nothrow) SceneUpdate();//escena primer nivel
SceneUpdate* finalBossScene = new(nothrow) SceneUpdate();//escena final boss
SceneUpdate* endScene = new(nothrow) SceneUpdate();//si ganas
SceneUpdate* gameOver = new(nothrow) SceneUpdate();//si pierdes

void GameUpdate::ProcessMouseMovement(int x, int y) {
	//Se dividen entre 20 para reducir la sensibilidad
	x = x / 10;
	y = y / 10;
	this->escenaActual->ProcessMouseMovement(x, y);
}

void GameUpdate::ProcessKeyPressed(unsigned char key, int px, int py) {
	this->escenaActual->ProcessKeyPressed(key, px, py);
	int i;
	if (key == 't' && escenaActual == mainScene) {
		mainScene->DeleteLastGameObject();
	}
	if (key == 'e' && escenaActual == altScene) {
		escenaActual->EscenaRandom(mainScene);
	}
	if (key == 'm' && escenaActual == mainScene && mecanicoUp) {
		escenaActual = mainScene;
		i = 1;
		escenaActual->Mercadero(mainScene, i);
		mecanicoUp = false;
	}
	if (key == 'n' && escenaActual == mainScene && !mecanicoUp) {
		escenaActual = mainScene;
		i = 2;
		cout << "hola" << endl;
		escenaActual->Mercadero(mainScene, i);
		mecanicoUp = true;
	}
	if (key == 'y' && escenaActual == mainScene && !mecanicoUp) {
		escenaActual = mainScene;
		i = 3;
		escenaActual->Mercadero(mainScene, i);
		this->getPlayer()->setVida(100.0f);
		mecanicoUp = true;
	}
	if (key == 's' || key == 'S') { //reset camera

		escenaActual->getCamera()->setAngulo(Vector3D(0.0, 0.0, 0.0));
		//escenaActual->tuMirila->setAngulo(Vector3D(0.0, 0.0, 0.0));
	}
}
void GameUpdate::ProcessMouseClick(int button, int state, int x, int y) {
	if (x > 350 && y > 400 && escenaActual == altScene) {
		escenaActual = mainScene;
		escenaActual->EscenaRandom(mainScene);
		NewScene(mainScene);
	}
}
void GameUpdate::resuelveColisiones()
{
	this->escenaActual->resuelveColisiones();
}
void GameUpdate::Init() {
	
	string nombreJugador;
	cin >> nombreJugador;
	player->setNombre(nombreJugador);
	NewScene(altScene);
	escenaActual = altScene;
	//Normal
	escenaActual->Init(altScene, player->getNombre());
	//VersionDeluxe
	//escenaActual->EscenaTesteo(altScene);
	//VersionRandom
	//escenaActual->EscenaRandom(altScene);
	//escenaActual->EscenaFinal(altScene);
	//escenaActual->Congratulations(altScene, player->getNombre(), amo);
	//escenaActual->GameOver(altScene);
}
void GameUpdate::NewScene(SceneUpdate* object) {
	escenas.push_back(object);
};
void GameUpdate::Render() {
	this->escenaActual->Render();
}
void GameUpdate::Update() {

	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

	if (currentTime.count() - this->initialMilliseconds.count() - this->lasUpdatedTime > UPDATE_PERIOD) {
		this->escenaActual->Update(TIME_INCREMENT);
		this->lasUpdatedTime = currentTime.count() - this->initialMilliseconds.count();
	}

	//Regula que tipo de escena tiene al terminar el juego
	cout << escenaActual->Size() << endl;
	if (escenas.size() == 2 && mainScene->Size() == 0) {
		NewScene(finalBossScene);
		escenaActual = finalBossScene;
		escenaActual->EscenaFinal(finalBossScene);
	}
	if (escenas.size() == 3 && finalBossScene->SizeCol() == 0) {
		NewScene(endScene);
		escenaActual = endScene;
		escenaActual->Congratulations(endScene, player->getNombre(), amo);
	}
	if (escenas.size() == 3 && finalBossScene->SizeCol() == 0) {
		NewScene(gameOver);
		escenaActual = gameOver;
		escenaActual->GameOver(gameOver);
	}
}