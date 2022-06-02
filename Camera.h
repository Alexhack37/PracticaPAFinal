#pragma once
#include "Solid.h"
class Camera: public Solid
{

public:
	Camera(Vector3D a = Vector3D(), Vector3D p = Vector3D()) :Solid()
	{
		setAngulo(a);
		setPos(p);
		
	}
	void Render();
};

