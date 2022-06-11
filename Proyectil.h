#pragma once
#include "Vector3D.h"
#include "Solid.h"

//#include "Scene.h"

class Proyectil : public Solid
{
private:
	//Proyectil* bala;
	float m_radio;
	int m_slices;
	int m_stacks;

public:

	Proyectil(Vector3D position = Vector3D(0.0, 0.0, 0.0),
		Vector3D orientation = Vector3D(0.0, 0.0, 0.0),
		Color rgb = Color(1.0, 0.0, 0.0),
		Vector3D vectorRotacion = Vector3D(0.0, 0.0, 7.0),
		Vector3D vectorDesplazamiento = Vector3D(0.0, 0.0, 0.0),
		float radio = 0.25,
		int slices = 15,
		int slacks = 15,
		int ideBala = 0,
		int identificacion = 0)
		:Solid{ position, orientation, rgb, vectorRotacion, vectorDesplazamiento, identificacion },
		m_radio{ radio },
		m_slices{ slices },
		m_stacks{ slacks }/*, identidadBala{ ideBala } */{}

	inline ~Proyectil() {}

	inline float getRadio()  const { return this->m_radio; }
	inline int	 getSlices() const { return this->m_slices; }
	inline int	 getStacks() const { return this->m_stacks; }
	//inline int	 getId() const { return this->identidadBala; }

	inline void setRadio(const float& nuevoRadio) { this->m_radio = nuevoRadio; }
	inline void setSlices(const float& nuevoSlices) { this->m_slices = nuevoSlices; }
	inline void setSlacks(const float& nuevoSlacks) { this->m_stacks = nuevoSlacks; }
	//inline void setId(const float& nuevoId) { this->identidadBala = nuevoId; }

	void Render();

	Contorno* getContorno();
	bool colision(Solid* s);
	void resuelveColision(Solid* s);
};

