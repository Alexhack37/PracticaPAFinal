#pragma once
#include <GL/glut.h>
#include "Vector3D.h"
#include "Solid.h"

class Sphere: public Solid{
private:

	double m_radio{};
	int m_slices{};
	int m_stacks{};

public:

	Sphere(Vector3D position = Vector3D(0.0, 0.0, 0.0),
		Vector3D orientation = Vector3D(0.0, 0.0, 0.0),
		Color rgb = Color(0.0, 0.0, 0.0),
		Vector3D vectorRotacion = Vector3D(0.0, 0.0, 0.0),
		Vector3D vectorDesplazamiento = Vector3D(0.0, 0.0, 0.0),
		float radio = 4.0,
		int slices = 15,
		int slacks = 15,
		int identificacion = 0)
		:Solid{ position, orientation, rgb, vectorRotacion, vectorDesplazamiento, identificacion },
		m_radio{ radio },
		m_slices{slices},
		m_stacks{slacks} {}


	inline float getRadio()  const { return this->m_radio; }
	inline int	 getSlices() const { return this->m_slices;}
	inline int	 getStacks() const { return this->m_stacks; }

	inline void setRadio (const float&  nuevoRadio)  {this -> m_radio = nuevoRadio; }
	inline void setSlices(const float&  nuevoSlices) {this -> m_slices = nuevoSlices; }
	inline void setSlacks(const float&  nuevoSlacks) {this -> m_stacks = nuevoSlacks; }

	void Render();
};

