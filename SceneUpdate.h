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
public:
	SceneUpdate() {
		this->camera = new CameraFPS(Vector3D(25.0, 14.0, 35.0));
		this->tuProyectil = new Proyectil();
		this->tuProyectil->setPos(camera->getPos());
		this->tuArma = new Arma(Vector3D(25.0f, 6.0f, 22.0f));
		this->nombre = "Escena por defecto";
		this->boundary = Vector3D(50.0f, 30.0f, 50.0f);

		//A�adir los planos que haran de boundri por defecto
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
	//	moviles.push_back(s);
	//	colisionables.push_back(s);
	//}
	// only render
	void addSolido(Solid* s) {
		solidos.push_back(s);
	}
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
		for (Solid* c : colisionables) {
			if (tuProyectil->colision(c)) {
				tuProyectil->resuelveColision(c);
				c->resuelveColision(tuProyectil);
				tuProyectil->setPos(camera->getPos().Sub(Vector3D(0.0f, 0.0f, 100.0f)));
				tuProyectil->setSpeed(Vector3D(0.0f, 0.0f, 0.0f));
				puntosRegistrados += c->getPuntos(); 
				danoRegistrado -= c->getDano();
				std::cout << "Tienes estos puntos " << danoRegistrado<< endl;
			}
		}
		vector<float> datos = { puntosRegistrados, danoRegistrado };
		return datos;
	}

	inline string getNombre()	const { return nombre; }
	inline void setPos(string nuevoNombre) { nombre = nuevoNombre; }
	void ProcessMouseMovement(int x, int y);
	void ProcessKeyPressed(unsigned char key, int px, int py);

	void checkBoundary();

	void Init(SceneUpdate* object, string nombre);
	void Escena1(SceneUpdate* escenaUsando);
	void EscenaFinal(SceneUpdate* object);
	void Congratulations(SceneUpdate* object);
	void GameOver(SceneUpdate* object);
	void Mercadero(SceneUpdate* object);
	//Version que se llama desde game
	//void Disparo(SceneUpdate* object);
	void Disparo();

	void EscenaTesteo(SceneUpdate* escenaCambia);
	void EscenaRandom(SceneUpdate* escenaCambia);
};

