#pragma once
#include <GL/glut.h>
#include "Vector3D.h"
#include "Color.h"
#include "Model.h"
class Mercader : public Model
{

private:

	//float m_longit{};
	//float m_height{};
	//float m_width{};

	int vida;
public:


	Mercader() {
		vida = 50;

	}

	//Mercader(Vector3D position = Vector3D(0.0, 0.0, 0.0),
	//	Vector3D orientation = Vector3D(0.0, 0.0, 0.0),
	//	Color rgb = Color(0.0, 0.0, 0.0),
	//	Vector3D vectorRotacion = Vector3D(0.0, 0.0, 0.0),
	//	Vector3D vectorDesplazamiento = Vector3D(0.0, 0.0, 0.0),
	//	float longit = 4.0,
	//	float height = 2.0,
	//	float width = 2.0, int identificacion = 0)
	//	:Solid{ position, orientation, rgb, vectorRotacion, vectorDesplazamiento, identificacion },
	//	m_longit{ longit },
	//	m_height{ height },
	//	m_width{ width }{}


		inline float getVida() const { return this->vida; }
		inline void  setVida(const  float& vidaToSet) { this->vida = vidaToSet; }

		//inline float getHeight() const { return this->m_height; }
		//inline void  setHeight(const  float& heightToSet) { this->m_height = heightToSet; }

		//inline float getWidth() const { return this->m_width; }
		//inline void  setWidth(const  float& widthToSet) { this->m_height = widthToSet; }
		void resuelveColision(Solid* s);
		//void Render();

};

