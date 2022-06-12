#include "Jugador.h"

//alex
#include "Vector3D.h"

void Jugador::cambiarPuntuacion(float puntuacionCambia) {
	float nuevaPuntuacion = puntuacionCambia + this->getPuntuacion();
	this->setPuntuacion(nuevaPuntuacion);
}

void Jugador::cambiarVida(float vidaCambia) {
	float nuevaVida = vidaCambia + this->getVida();
	this->setVida(nuevaVida);
}

void Jugador::cambiarMunicion(float municionCambia) {
	float nuevaMunicion = municionCambia + (this->getMunicion());
	this->setMunicion(nuevaMunicion);
}

