#pragma once
#include <vector>

#include "SceneUpdate.h"
#include <string>

#include "Jugador.h"

#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;

class GameUpdate
{
private:

	const double TIME_INCREMENT = 0.4;
	const long UPDATE_PERIOD = 10;

	milliseconds initialMilliseconds;
	long lasUpdatedTime;

	Jugador* player;

	SceneUpdate* escenaActual;
	vector<SceneUpdate*> escenas;

public:
	GameUpdate() {

		escenaActual = new SceneUpdate();
		initialMilliseconds = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
		lasUpdatedTime = 0;
		player = new Jugador();
	};

	inline Jugador* getPlayer() const { return player; }
	void setJugador(Jugador* nuevoJugador) { this->player = nuevoJugador; }

	void Init();
	void Render();
	void Update();
	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClick(int button, int state, int x, int y);
	void resuelveColisiones();
	void NewScene(SceneUpdate* object);
};

