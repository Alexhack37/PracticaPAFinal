#pragma once
#include "Vector3D.h"
#include "Color.h"
#include <GL/glut.h>

class Solid
{
private:


	Vector3D orientationSpeed{ 0.0, 0.0, 0.0 };
	Vector3D speed{ 0.0, 0.0, 0.0 };

	Vector3D posicion{ 0.0, 0.0, 0.0 };
	Vector3D orientacion{ 0.0, 0.0, 0.0 };
	Color rgb{ 0.0, 0.0, 0.0 };
	
	int incremento_de_tiempo = 1;
	 
public:
	Solid() = default;
	
	Solid(Vector3D position,Vector3D orientation, Color colour, Vector3D vectorRotacion, Vector3D vectorDesplazamiento)
	{
		posicion = position;
		orientacion = orientation;
		rgb = colour;
		orientationSpeed = vectorRotacion;
		speed = vectorDesplazamiento;
	}

	//getters
	inline Vector3D getPos()	const { return posicion; }
	inline Color getRgb()		const { return rgb; }
	inline Vector3D getAngulo() const { return orientacion; }

	inline Vector3D getOrientationSpeed() const { return orientationSpeed; }
	inline Vector3D getSpeed()			  const { return speed; }

	// setters
	
	inline void setPos(Vector3D position){ posicion = position; }
	inline void setCoordenadaX(float x) { posicion.setCoordnateX(x);}
	inline void setCoordenadaY(float y) { posicion.setCoordnateY(y);}
	inline void setCoordenadaZ(float z) { posicion.setCoordnateZ(z);}

	inline void setAngulo(Vector3D orientation) { orientacion = orientation; }
	inline void setAnguloX(float x) { orientacion.setCoordnateX(x);}
	inline void setAnguloY(float y) { orientacion.setCoordnateY(y);}
	inline void setAnguloZ(float z) { orientacion.setCoordnateZ(z);}

	inline void setRgb(Color colour) { rgb = colour; }
	inline void setRed(float r) { rgb.setRedComponent(r); }
	inline void setGreen(float g) { rgb.setGreenComponent(g); }
	inline void setBlue(float b) { rgb.setBluecomponent(b); }

	inline void setOrientationSpeed(Vector3D velocidadRotacion) { orientationSpeed = velocidadRotacion; }
	inline void setOrientationSpeedComponentX(float x) { orientationSpeed.setCoordnateX(x); }
	inline void setOrientationSpeedComponentY(float y) { orientationSpeed.setCoordnateY(y); }
	inline void setOrientationSpeedComponentZ(float z) { orientationSpeed.setCoordnateZ(z); }

	inline void setSpeed(Vector3D vectorDesplazamiento) { speed = vectorDesplazamiento; }
	inline void setSpeedX(float x) { speed.setCoordnateX(x); }
	inline void setSpeedY(float y) { speed.setCoordnateY(y); }
	inline void setSpeedZ(float z) { speed.setCoordnateZ(z); }

	virtual void Render() = 0;

	virtual void Update(const float& time);
};

