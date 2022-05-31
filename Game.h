#pragma once



#include "Solid.h"
#include "Teapot.h"
#include "Cube.h"
#include "CuboId.h"
#include "Sphere.h"
#include "Torus.h"
#include "Cylider.h"
#include "Camera.h"
#include <vector>

#include "camera_fps.h"
#include "Arma.h"

#include "Tarta.h"
#include "Boton.h"
#include "Mercader.h"
#include "FinalBoss.h"
#include "Text.h"
#include "Proyectil.h"
#include "Jugador.h"

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
	int sala1 = 0;
	Scene* escenaActual;
	vector<Scene*> escenas;

	string objetos[8] = {"Burger", "SodaLataTria", "Cake", "CupcakeCherry", "Hotdog", "Pizza", "Soda", "BurgerTest"};

	Solid* Jugador;
	

public:
	// erfhjbjkhbjklfhbjfafvhdjubdfbajhñuhubdjhbiqwefruhoñeubhjikñev

	Game() : escenaActual(nullptr), initialMilliseconds(duration_cast<milliseconds>(system_clock::now().time_since_epoch())), lasUpdatedTime(0), Jugador(nullptr) {} //?

	void Init();
	void Render();
	void Update();
	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClick(int button, int state, int x, int y);

	
	void NewScene(Scene* object);
	void Escena1();
	void EscenaFinal();
	void Congratulations();
	void Mercadero();
};

