#pragma once
#include "Solid.h"
#include "Camera.h"
#include "camera_fps.h"
#include "planoY.h"
#include "planoX.h"
#include "planoZ.h"
#include <vector>
#include "Proyectil.h"
#include "Arma.h"
#include "Mercader.h"
#include "Text.h"

using namespace std;

class SceneUpdate : public Solid
{
	vector<Solid*> solidos;
	vector<Solid*> moviles;
	vector<Solid*> colisionables;
	vector<Solid*> limites;
	string objetos[8] = { "Burger", "SodaLataTria", "Cake", "CupcakeCherry", "Hotdog", "Pizza", "Soda", "BurgerTest" };
	//Camera* camera;
	CameraFPS* camera;
	std::string nombre;
	Arma* tuArma;
	Proyectil* tuProyectil;

	Vector3D boundary;

	/*Mercader* mecanico;
	Text* textoMeca;*/
public:
	int i;
	SceneUpdate() {
		this->camera = new CameraFPS(Vector3D(25.0, 14.0, 35.0));
		this->tuProyectil = new Proyectil();
		this->tuProyectil->setPos(camera->getPos());
		this->tuArma = new Arma(Vector3D(25.0f, 6.0f, 22.0f));
		this->nombre = "Escena por defecto";
		this->boundary = Vector3D(50.0f, 30.0f, 50.0f);


		//this->textoMeca = new Text("?Hola! ?Quieres que repare tu nave?   Y: 1 N: 2");
		//mecanico->setPos(Vector3D(0.0f, 0.0f, 100.0f));
		//textoMeca->setPos(Vector3D(0.0f, 0.0f, 100.0f));

		//A?adir los planos que haran de boundri por defecto
		//this->addLimite(new PlanoZ(10));
		//this->addLimite(new PlanoZ(-30));
	};
	virtual ~SceneUpdate();
	void add(Solid* s) {
		solidos.push_back(s);
		moviles.push_back(s);
		colisionables.push_back(s);
	}
	//void remove(Solid* s) {
	//	solidos.erase(s);
	//	moviles.erase(s);
	//	colisionables.push_back(s);
	//}

	// render and collision not move
	void addFijo(Solid* s) {
		solidos.push_back(s);
		colisionables.push_back(s);
	}
	void addLimite(Solid* s) {
		solidos.push_back(s);
		limites.push_back(s);
	}
	inline void Render() {
		this->camera->Render();
		this->tuArma->Render();
		this->tuProyectil->Render();
		for (Solid* r : solidos)
			r->Render();
	}
	inline void Update(float dt) {
		this->camera->Update(0);
		this->tuArma->Update(dt);
		this->tuProyectil->Update(dt);
		this->checkBoundary();
		for (Solid* s : moviles)
			s->Update(dt);

	}
	inline vector<float> resuelveColisiones() {
		float puntosRegistrados = 0;
		float danoRegistrado = 0;
		
		for (Solid* l : limites) {
			for (Solid* s : moviles) {
				if (l->colision(s)) {
					l->resuelveColision(s);
				}
			}
		}
		for (Solid* m : moviles) {
			for (Solid* c : colisionables) {
				if (c != m) {
					if (m->colision(c)) {
						m->resuelveColision(c);
					}
				}
			}
		}
		//for (Solid* c : colisionables) {
		//	if (tuProyectil->colision(c)) {
		//		tuProyectil->resuelveColision(c);
		//		c->resuelveColision(tuProyectil);
		//		tuProyectil->setPos(camera->getPos().Sub(Vector3D(0.0f, 0.0f, 100.0f)));
		//		tuProyectil->setSpeed(Vector3D(0.0f, 0.0f, 0.0f));
		//		puntosRegistrados += c->getPuntos(); 
		//		danoRegistrado -= c->getDano();
		//		//std::cout << "Tienes estos puntos " << danoRegistrado<< endl;
		//		this->remove(c);
		//	}
		//}
		for (int i = 0; i <= colisionables.size(); i++) {
			if (tuProyectil->colision(colisionables[i])) {
				tuProyectil->resuelveColision(colisionables[i]);
				colisionables[i]->resuelveColision(tuProyectil);
				tuProyectil->setPos(camera->getPos().Sub(Vector3D(0.0f, 0.0f, 100.0f)));
				tuProyectil->setSpeed(Vector3D(0.0f, 0.0f, 0.0f));
				puntosRegistrados += colisionables[i]->getPuntos();
				danoRegistrado -= colisionables[i]->getDano();
				//std::cout << "Tienes estos puntos " << danoRegistrado<< endl;
				//this->remove(colisionables[i]);
			}
		}
		vector<float> datos = { puntosRegistrados, danoRegistrado };
		return datos;
	}

	inline string getNombre()	const { return nombre; }
	inline void setPos(string nuevoNombre) { nombre = nuevoNombre; }

	inline CameraFPS* getCamera() const { return camera; }
	void setCamera(CameraFPS* setcamera) { this->camera = setcamera; }


	void ProcessMouseMovement(int x, int y);
	void ProcessKeyPressed(unsigned char key, int px, int py);

	void checkBoundary();

	void Init(SceneUpdate* object, string nombre);
	void Escena1(SceneUpdate* escenaUsando);
	void EscenaFinal(SceneUpdate* object);
	void Congratulations(SceneUpdate* object, string nombre, int amo);
	void GameOver(SceneUpdate* object);
	void Mercadero(SceneUpdate* object, int i);
	//Version que se llama desde game
	//void Disparo(SceneUpdate* object);
	void Disparo();
	int Size();
	int SizeCol();
	void DeleteLastGameObject();
	void EscenaTesteo(SceneUpdate* escenaCambia);
	void EscenaRandom(SceneUpdate* escenaCambia);
};

