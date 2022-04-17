#pragma once
#include <GL/glut.h>
#include "Vector3D.h"
#include "Color.h"
#include "Solid.h"


class Teapot: public Solid{
private:
	
	float m_size{};
public:


	Teapot(Vector3D position = Vector3D(0.0, 0.0, 0.0),
		Vector3D orientation = Vector3D(0.0, 0.0, 0.0),
		Color rgb = Color(0.0, 0.0, 0.0),
		Vector3D vectorRotacion = Vector3D(0.0, 0.0, 0.0),
		Vector3D vectorDesplazamiento = Vector3D(0.0, 0.0, 0.0),
		float size = 1.0)
		:Solid{ position, orientation, rgb, vectorRotacion, vectorDesplazamiento },
		m_size{ size }	{}
	
	inline float GetSize() const { return this->m_size; }
	inline void SetSize(const  float& sizeToSet) { this->m_size = sizeToSet; }

	
	void Render();
	
};