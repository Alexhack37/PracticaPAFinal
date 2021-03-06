#pragma once
#include <GL/glut.h>
#include "Vector3D.h"
#include "CuboId.h"
class Arma : public CuboId
{
private:

	int mouseX;
	int mouseY;
	float municion;
	int modoDisparo = 0;    //Valor del disparo por defecto

	float m_longit{};
	float m_height{};
	float m_width{};

public:

	Arma(Vector3D position = Vector3D(0.0f, 0.0f, 0.0f), //25.0f, 6.0f, 14.0f
		Vector3D orientation = Vector3D(0.0, 0.0, 90.0),
		Color rgb = Color(0.7, 0.7, 0.7),
		Vector3D vectorRotacion = Vector3D(0.0, 0.0, 0.0),
		Vector3D vectorDesplazamiento = Vector3D(0.0, 0.0, 0.0),
		int shootMode = 0,
		float amo = 0.0f,
		float longit = 0.75,
		float height = 0.75,
		float width = 3.0)
		:CuboId{ position, orientation, rgb, vectorRotacion, vectorDesplazamiento },
		municion{amo},
		modoDisparo{ shootMode },
		m_longit{ longit },
		m_height{ height },
		m_width{ width }{}

	inline float getLongit() const { return this->m_longit; }
	inline void  setLongit(const  float& longitToSet) { this->m_longit = longitToSet; }

	inline float getHeight() const { return this->m_height; }
	inline void  setHeight(const  float& heightToSet) { this->m_height = heightToSet; }

	inline float getWidth() const { return this->m_width; }
	inline void  setWidth(const  float& widthToSet) { this->m_height = widthToSet; }

	inline int getShootMode() const { return this->modoDisparo; }
	inline void setShootMode(const  int& nuevoShootMode) { this->modoDisparo = nuevoShootMode; }

	inline void  setMunicion(const  float& MunicionToSet) { this->municion = MunicionToSet; }
	inline float getMunicion() const { return this->municion; }


	void ProcessMouseMovement(int x, int y);
	//void ProcessKeyPressed(unsigned char key, int px, int py);

	inline float GetMouseX() const { return this->mouseX; }
	inline void SetMouseX(const float& mousexToSet) { this->mouseX = mousexToSet; }

	inline float GetMouseY() const { return this->mouseY; }
	inline void SetMouseY(const float& mouseyToSet) { this->mouseY = mouseyToSet; }



	//void cambiarMunicion(float municionCambia);
	void Dispara();

	void Render();

};

