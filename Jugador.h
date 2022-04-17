#pragma once
class Jugador
{

private:
	float vida;
public:
	Jugador(float v)
	{
		vida = v;
	}
	inline float getVida() const { return this->vida; }
	inline void  setVida(const  float& VidaToSet) { this->vida = VidaToSet; }

};

