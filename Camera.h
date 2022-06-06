#pragma once
#include "Solid.h"
class Camera: public Solid
{

public:
	
	Camera(Vector3D lookAt = Vector3D(), Vector3D posicion = Vector3D()) :Solid()
	{
		setAngulo(lookAt);
		setPos(posicion);
		
	}
	Camera() {

	}
	void Render();
};

