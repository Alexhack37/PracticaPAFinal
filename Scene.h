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
		vector<ModelLoader*> gameLoaders;
		vector<Solid*> colisionables;
		vector<Solid*> limites;
		string objetos[7] = { "Burger", "SodaLataTria", "Cake", "CupcakeCherry", "Hotdog", "Soda", "BurgerTest" };

		//Camera* camera;
		CameraFPS* camera;
		Arma* tuArma = new Arma(Vector3D(25.0f, 6.0f, 22.0f));
		Mira* tuMirila;
		Proyectil* bala;
		Mercader* mecanico;
		Text* textoMeca;

		Scene(): boundary(50.0f, 30.0f, 50.0f){
		
			this->camera = new CameraFPS(Vector3D(25.0, 14.0, 35.0));
			//this->camera = new Camera(Vector3D(), Vector3D(25.0, 14.0, 35.0)); //25.0, 15.0, 30.0
			//this->tuArma = new Arma(Vector3D(25.0f, 6.0f, 22.0f));
			this->tuMirila = new Mira(this->tuArma->getPos());
			//this->player = new Jugador(100.0f, 0.0f, "");
			this->bala = new Proyectil(Vector3D(0.0f,0.0f,100.0f), Vector3D(0.0f, 0.0f, 0.0f), Color(0.0f, 0.0f, 0.0f),Vector3D(0.0f, 0.0f, 0.0f), Vector3D(0.0f, 0.0f, 0.0f),0.25f,15,15,0,0 );
			this->mecanico = new Mercader();
			this->textoMeca = new Text("¡Hola! ¿Quieres que repare tu nave?   Y: 1 N: 2");
			mecanico->setPos(Vector3D(0.0f, 0.0f, 100.0f));
			textoMeca->setPos(Vector3D(0.0f, 0.0f, 100.0f));

			
		}; //8,6,4 o 20,20,20
		/*	~Scene() {
			delete[] gameObjects[i];
		}*/

		int escena;
		int tamanoEscena2, tamanoEscena3;
	inline Vector3D getBounds() const { return boundary; }
	inline void setBounds(Vector3D b) { boundary = b; }


	void AddGameObject(Solid* object);
	void AddLoaderObject(ModelLoader* object);	
	void ProcessMouseMovement(int x, int y);
	void ProcessKeyPressed(unsigned char key, int px, int py);
	void DeleteLastGameObject();
	void DeleteGameObject(int i);
	int Size();
	void Render();
	void Update(const float& time);
	bool checkObjetIndex(int a);
	void checkBala();
	void checkColision();
	void DeleteObjectByMyId(int i);


	//void NewScene(Scene* object);
	void Init(Scene* object, string nombre);
	void Escena1(Scene* escenaUsando);
	void EscenaFinal(Scene* object);
	void Congratulations(Scene* object, string nombre, int amo);
	void GameOver(Scene* object);
	void Mercadero(Scene* object, int i);
	void Disparo(Scene* object);

};

