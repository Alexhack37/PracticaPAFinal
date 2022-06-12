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


	if (key == 'i' || key == 'I') { //reset camera
		std::cout << "Tienes estos puntos " << this->player->getPuntuacion()<< endl;
		std::cout << "Tienes estos vida " << this->player->getVida() << endl;
	}
}
void GameUpdate::ProcessMouseClick(int button, int state, int x, int y) {
	//if (x > 350 && y > 400 && escenaActual == altScene) {
	//	escenaActual = mainScene;
	//	escenaActual->Escena1(mainScene);
	//	NewScene(mainScene);
	//}
}
void GameUpdate::resuelveColisiones()
{
	vector<float> datos = this->escenaActual->resuelveColisiones();
	//this->player->setPuntuacion(this->player->getMunicion() + puntosAnanaidos);
	player->addPuntuacion(datos[0]);
	player->addVida(datos[1]);
}
void GameUpdate::Init() {
	string nombreJugador;
	cin >> nombreJugador;
	this->player->setNombre(nombreJugador);
	this->getPlayer()->setNombre(nombreJugador);
	NewScene(altScene);
	escenaActual = altScene;
	//Normal
	//escenaActual->Init(altScene, player->getNombre());
	//VersionDeluxe
	escenaActual->EscenaTesteo(altScene);
	//VersionRandom
	//escenaActual->EscenaRandom(altScene);
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
	////cout << mainScene->Size() << endl;
	//if (escenas.size() == 2 && mainScene->Size() == 0) {
	//	NewScene(finalBossScene);
	//	escenaActual = finalBossScene;
	//	escenaActual->EscenaFinal(finalBossScene);
	//}
	//if (escenas.size() == 3 && !finalBossScene->checkObjetIndex(9)) {
	//	NewScene(endScene);
	//	escenaActual = endScene;
	//	escenaActual->Congratulations(endScene);
	//}
	//if (escenas.size() == 3 && !finalBossScene->checkObjetIndex(7) && !finalBossScene->checkObjetIndex(8)) {
	//	NewScene(gameOver);
	//	escenaActual = gameOver;
	//	escenaActual->GameOver(gameOver);
	//}
}