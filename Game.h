#pragma once


#include <vector>

#include "Scene.h"

#include <string>

#include <chrono>
#include <thread>



using namespace std;
using namespace std::chrono;


class Game
{
private:

	const double TIME_INCREMENT = 0.4;
	const long UPDATE_PERIOD = 10;

	milliseconds initialMilliseconds;
	long lasUpdatedTime;

	//Scene scene;
	
	//en escenas
	Scene* escenaActual;
	vector<Scene*> escenas;

	

	//en escena
	
	

public:
	Jugador player;

	//Constructor por defecto
	Game() : escenaActual(nullptr), initialMilliseconds(duration_cast<milliseconds>(system_clock::now().time_since_epoch())),
		lasUpdatedTime(0), player(0.0f,0.0f, 0.0f,"") {} //?

	void Init();
	void Render();
	void Update();
	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClick(int button, int state, int x, int y);

	
	void NewScene(Scene* object);
	/*void Escena1(Scene* object);
	void EscenaFinal();
	void Congratulations();
	void GameOver();
	void Mercadero();
	void Disparo(Scene* object);*/
};

