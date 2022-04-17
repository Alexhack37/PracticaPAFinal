#pragma once
#include <GL/glut.h>
#include "Vector3D.h"
#include "Color.h"
#include "Solid.h"

class ProyectilArea: public Solid
{
private:

	double m_rInterno{};
	double m_rExterno{};

	int m_faces{};
	int m_rings{};

public:


	ProyectilArea(Vector3D v = Vector3D(0.0, 0.0, 0.0),
		Vector3D a = Vector3D(0.0, 0.0, 0.0),
		Color c = Color(0.0, 1.0, 0.5),
		Vector3D o = Vector3D(0.0, 0.0, 0.0),
		Vector3D s = Vector3D(0.0, 0.0, 0.0),
		double rInterno = 1,
		double rExterno = 2.5,
		int faces = 15,
		int rings = 15)
		:Solid{ v, a, c, o, s },
		m_rInterno{ rInterno },
		m_rExterno{ rExterno },
		m_faces{ faces },
		m_rings{ rings } {}


	inline float getRinterno() const { return this->m_rInterno; }
	inline void  setRinterno(const  float& nuevorInterno) { this->m_rInterno = nuevorInterno; }

	inline float getRexterno() const { return this->m_rExterno; }
	inline void  setRexterno(const  float& nuevorExterno) { this->m_rExterno = nuevorExterno; }

	inline float getFaces() const { return this->m_faces; }
	inline void  setFaces(const  float& nuevoFaces) { this->m_faces = nuevoFaces; }

	inline float getRings() const { return this->m_rings; }
	inline void  setRings(const  float& nuevoRings) { this->m_rings = nuevoRings; }


	void Render();
};

