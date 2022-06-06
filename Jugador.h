#pragma once
#include <string>
class Jugador
{

private:
	float vida;
	float municion;
	float puntuacion;
	std::string nombre;

public:
	Jugador() {
		vida = 100;
		municion = 50;
		puntuacion = 0;
		nombre = "JUNKRAT";
	}
	Jugador(float v, float amo, float points, std::string nom)
	{
		vida = v;
		municion = amo;
		puntuacion = points;
		nombre = nom;
	}
	//Getters
	inline float getVida()  { return vida; }
	inline float getMunicion() const { return this->municion; }
	inline float getPuntuacion() const { return this->puntuacion; }
	inline std::string getNombre() const { return this->nombre; }
	//Setters
	inline void  setVida( const float& VidaToSet) { this->vida = VidaToSet; }
	inline void  setMunicion(const  float& MunicionToSet) { this->municion = MunicionToSet; }
	inline void  setPuntuacion(const  float& PuntuacionToSet) { this->puntuacion = PuntuacionToSet; }
	inline void  setNombre(const  std::string& NombreToSet) { this->nombre = NombreToSet; }
	//Otros Metodos
	void cambiarPuntuacion(float puntuacionCambia);
	void cambiarMunicion(float municionCambia);
	void cambiarVida(float vidaCambia);
};

