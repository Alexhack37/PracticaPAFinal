#pragma once

class Color{
private:

	float redComponent{ 0.0 };
	float greenComponent{ 0.0 };
	float blueComponent{ 0.0 };

public:

	//Color() = default;

	Color(float r, float g, float b)
	{
		if (r > 1.0) {
			r = 1.0;
		}
		else if (r < 0) {
			r = 0.0;
		}

		if (g > 1.0) {
			g = 1.0;
		}
		else if (g < 0) {
			g = 0.0;
		}
		if (b > 1.0) {
			b = 1.0;
		}
		else if (b < 0) {
			b = 0.0;
		}
		redComponent = r;
		greenComponent = g;
		blueComponent = b;
	}

	//Getters

	inline float getRedComponent()   const { return this-> redComponent;}
	inline float getGreenComponent() const { return this-> greenComponent;}
	inline float getBlueComponent()  const { return this-> blueComponent;}

	//Setters
	inline void setRedComponent(float nuevoComponenteRed);
	inline void setGreenComponent(float nuevoComponenteGreen);
	inline void setBluecomponent(float nuevoComponenteBlue);
};

