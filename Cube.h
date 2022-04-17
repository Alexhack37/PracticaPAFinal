#pragma once
#include <GL/glut.h>
#include "Vector3D.h"
#include "Color.h"
#include "Solid.h"


class Cube:public Solid
{

private:
	float m_size{};

public:


	Cube(Vector3D position = Vector3D(0.0, 0.0, 0.0),
		 Vector3D orientation = Vector3D(0.0, 0.0, 0.0),
		 Color    rgb = Color(0.0, 0.0, 0.0),
		 Vector3D vectorRotacion = Vector3D(0.0, 0.0, 0.0),
		 Vector3D vectorDesplazamiento = Vector3D(0.0, 0.0, 0.0),
		 float size = 4.0)
		:Solid{ position, orientation, rgb, vectorRotacion, vectorDesplazamiento},
		 m_size{size}	{}
	

	inline float getSize() const { return this->m_size; }
	inline void setSize(const  float& sizeToSet) { this->m_size = sizeToSet; }


	void Render();
};

