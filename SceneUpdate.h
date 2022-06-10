#pragma once
#include "Solid.h"
#include "Camera.h"
#include "camera_fps.h"
#include <vector>
#include "Proyectil.h"

//using namespace std;

class SceneUpdate : public Solid
{
	vector<Solid*> solidos;
	vector<Solid*> moviles;
	vector<Solid*> colisionables;
	vector<Solid*> limites;
	string objetos[8] = { "Burger", "SodaLataTria", "Cake", "CupcakeCherry", "Hotdog", "Pizza", "Soda", "BurgerTest" };
	//Camera* camera;
	CameraFPS* camera;
	Proyectil* tuProyectil;
public:
	SceneUpdate();
	virtual ~SceneUpdate();
	void add(Solid* s) {
		solidos.push_back(s);
		moviles.push_back(s);
		colisionables.push_back(s);
	}
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
	inline void render() {
		for (Solid* r : solidos)
			r->Render();
	}
	inline void update(float dt) {
		for (Solid* s : moviles)
			s->Update(dt);
	}
	inline void resuelveColisiones() {
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
	}
};

