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
	private:
	
		//vector<Proyectil*> balas;
		Vector3D boundary;

		//CameraFPS* camera;
		
		void checkBoundary();

	public:

		vector<Solid*> gameObjects;
		//Camera* camera;
		CameraFPS* camera;
		Arma* tuArma;
		Mira* tuMirila;
		Scene(): boundary(50.0f, 30.0f, 30.0f){
		
			this->camera = new CameraFPS(Vector3D(25.0, 14.0, 35.0));
			//this->camera = new Camera(Vector3D(), Vector3D(25.0, 14.0, 35.0)); //25.0, 15.0, 30.0
			this->tuArma = new Arma(Vector3D(25.0f, 6.0f, 22.0f));
			this->tuMirila = new Mira(this->tuArma->getPos());
		
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

	

};

