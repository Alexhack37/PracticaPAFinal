#pragma once
#include <GL/glut.h>
#include "Vector3D.h"
#include "Solid.h"
class Mira : public Solid
{
private:

	int mouseX;
	int mouseY;

	bool modoMira = false;

	float m_longit{};
	float m_height{};
	float m_width{};

public:

	Mira(Vector3D position = Vector3D(5.0f, 1.0f, 14.0f),
		Vector3D orientation = Vector3D(0.0, 0.0, 90.0),
		Color rgb = Color(0.0, 1.0, 0.0),
		Vector3D vectorRotacion = Vector3D(0.0, 0.0, 0.0),
		Vector3D vectorDesplazamiento = Vector3D(0.0, 0.0, 0.0),
		bool scopeMode = false,
		float longit = 0.05,
		float height = 0.05,
		float width = 40.0,
		int identificacion = 0)
		:Solid{ position, orientation, rgb, vectorRotacion, vectorDesplazamiento, identificacion },
		modoMira{ scopeMode },
		m_longit{ longit },
		m_height{ height },
		m_width{ width }{}

	inline float getLongit() const { return this->m_longit; }
	inline void  setLongit(const  float& longitToSet) { this->m_longit = longitToSet; }

	inline float getHeight() const { return this->m_height; }
	inline void  setHeight(const  float& heightToSet) { this->m_height = heightToSet; }

	inline float getWidth() const { return this->m_width; }
	inline void  setWidth(const  float& widthToSet) { this->m_height = widthToSet; }

	inline float getScopeMode() const { return this->modoMira; }
	inline void setScopeMode(const  bool& nuevoScopeMode) { this->modoMira = nuevoScopeMode; }



	void ProcessMouseMovement(int x, int y);
	void ProcessKeyPressed(unsigned char key, int px, int py);

	inline float GetMouseX() const { return this->mouseX; }
	inline void SetMouseX(const float& mousexToSet) { this->mouseX = mousexToSet; }

	inline float GetMouseY() const { return this->mouseY; }
	inline void SetMouseY(const float& mouseyToSet) { this->mouseY = mouseyToSet; }

	void CambiarScope();

	void Render();

};