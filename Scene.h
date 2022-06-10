#pragma once
#include "Solid.h"
#include "Camera.h"
#include "camera_fps.h"
#include "Arma.h"
#include "Mira.h"
#include <vector>


#include "Tarta.h"
#include "Boton.h"
#include "Mercader.h"
#include "FinalBoss.h"
#include "Text.h"
#include "Proyectil.h"
#include "Jugador.h"

#include "Teapot.h"
#include "CuboId.h"
#include "Sphere.h"


//SI DA UN ERROR RARPO POPSIBLE SEA ESTO
//#include "Game.h"

using namespace std;
class Scene 
{
	private:
	
		Vector3D boundary;
		Jugador* player;
		
		//CameraFPS* camera;
		
		void checkBoundary();

	public:

		vector<Solid*> gameObjects;
		vector<Solid*> colisionables;
		vector<Solid*> limites;
		string objetos[8] = { "Burger", "SodaLataTria", "Cake", "CupcakeCherry", "Hotdog", "Pizza", "Soda", "BurgerTest" };

		//Camera* camera;
		CameraFPS* camera;
		Arma* tuArma;
		Mira* tuMirila;
		Proyectil* tuProyectil;

		Scene(): boundary(50.0f, 30.0f, 50.0f){
		
			this->camera = new CameraFPS(Vector3D(25.0, 14.0, 35.0));
			//this->camera = new Camera(Vector3D(), Vector3D(25.0, 14.0, 35.0)); //25.0, 15.0, 30.0
			this->tuArma = new Arma(Vector3D(25.0f, 6.0f, 22.0f));
			this->tuMirila = new Mira(this->tuArma->getPos());
			this->player = new Jugador(100.0f, 30.0f, 0.0f, "JunjkRAt");
			
		}; //8,6,4 o 20,20,20
		/*	~Scene() {
			delete[] gameObjects[i];
		}*/

	
	inline Vector3D getBounds() const { return boundary; }
	inline void setBounds(Vector3D b) { boundary = b; }


	void AddGameObject(Solid* object);
	void ProcessMouseMovement(int x, int y);
	void ProcessKeyPressed(unsigned char key, int px, int py);
	void DeleteLastGameObject();
	float GetBala();
	float GetBalaY();
	void GetBalaDato();
	void DeleteGameObject(int i);
	int Size();
	void Render();
	void Update(const float& time);
	bool checkObjetIndex(int a);
	void DeleteObjectByMyId(int i);


	//void NewScene(Scene* object);
	void Init(Scene* object);
	void Escena1(Scene* escenaUsando);
	void EscenaFinal(Scene* object);
	void Congratulations(Scene* object);
	void GameOver(Scene* object);
	void Mercadero(Scene* object);
	void Disparo(Scene* object);

};

