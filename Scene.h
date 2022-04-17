#pragma once
#include "Solid.h"
#include "Camera.h"
#include "camera_fps.h"
#include "Arma.h"
#include "Mira.h"
#include <vector>

using namespace std;
class Scene 
{
	//hola
	private:
	
		//vector<Proyectil*> balas;
		Vector3D boundary;

		//CameraFPS* camera;
		

		void checkBoundary();
	public:

		vector<Solid*> gameObjects;
		Camera* camera;
		Arma* tuArma;
		Mira* tuMirila;
		Scene(): boundary(50.0f, 30.0f, 30.0f){
		
			//this->camera = new CameraFPS(Vector3D(5.0, 5.0, 20.0));
			this->camera = new Camera(Vector3D(25.0, 15.0, 30.0));
			this->tuArma = new Arma();
			this->tuMirila = new Mira(this->tuArma->getPos());
		
		}; //8,6,4 o 20,20,20
	

	
	inline Vector3D getBounds() const { return boundary; }
	inline void setBounds(Vector3D b) { boundary = b; }


	void AddGameObject(Solid* object);
	void ProcessMouseMovement(int x, int y);
	void ProcessKeyPressed(unsigned char key, int px, int py);
	void DeleteLastGameObject();
	float GetBala();
	float GetBalaY();
	void GetBalaDato();
	void DeleteGameObject();
	int Size();
	void Render();
	void Update(const float& time);


	

};

