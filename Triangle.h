#pragma once
#include "Solid.h"
#include "Texture.h"
class Triangle: Solid
{
private:
	Vector3D vertice1;
	Vector3D vertice2;
	Vector3D vertice3;

	Vector3D normal1;
	Vector3D normal2;
	Vector3D normal3;

	//Color vcolor1{ 0.0f, 0.0f, 0.0f };
	//Color vcolor2{ 0.0f, 0.0f, 0.0f };
	//Color vcolor3{ 0.0f, 0.0f, 0.0f };

	Color vcolor1;
	Color vcolor2;
	Color vcolor3;

	//Vector3D t0, t1, t2;
	//Texture* texture;

public:

	Triangle(Vector3D vX, Vector3D vY, Vector3D vZ, Vector3D nX, Vector3D nY, Vector3D nZ,
		Color c0 = Color(0, 0, 0), Color c1 = Color(0, 0, 0), Color c2 = Color(0, 0, 0))
	{
		vertice1 = vX;
		vertice2 = vY;
		vertice3 = vZ;

		normal1 = nX;
		normal2 = nY;
		normal3 = nZ;

		vcolor1 = c0;
		vcolor2 = c1;
		vcolor3 = c2;


	};


	//vertex
	inline Vector3D GetVertice1() const { return this->vertice1; }
	inline Vector3D GetVertice2() const { return this->vertice2; }
	inline Vector3D GetVertice3() const { return this->vertice3; }

	inline void SetVertice1(Vector3D vx) { vertice1 = vx; }
	inline void SetVertice2(Vector3D vy) { vertice2 = vy; }
	inline void SetVertice3(Vector3D vz) { vertice3 = vz; }

	//normal
	inline Vector3D GetNormal1() const { return this->normal1; }
	inline Vector3D GetNormal2() const { return this->normal2; }
	inline Vector3D GetNormal3() const { return this->normal3; }

	inline void SetNormal1(Vector3D nx) { normal1 = nx; }
	inline void SetNormal2(Vector3D ny) { normal2 = ny; }
	inline void SetNormal3(Vector3D nz) { normal3 = nz; }

	//color
	inline Color GetVcolor1() const { return this->vcolor1; }
	inline Color GetVcolor2() const { return this->vcolor2; }
	inline Color GetVcolor3() const { return this->vcolor3; }

	inline void SetVcolor1(Color cx) { vcolor1 = cx; }
	inline void SetVcolor2(Color cy) { vcolor2 = cy; }
	inline void SetVcolor3(Color cz) { vcolor3 = cz; }


	/*Vector3D getC0() { return c0; }
	void setC0(Vector3D v) { c0 = v; }
	Vector3D getC1() { return c1; }
	void setC1(Vector3D v) { c1 = v; }
	Vector3D getC2() { return c2; }
	void setC2(Vector3D v) { c2 = v; }*/
	
	//texture

	/*Texture* getTexture() { return texture; }
	void setTexture(Texture* t) { texture = t; }

	Vector3D getT0() { return t0; }
	void setT0(Vector3D v) { t0 = v; }
	Vector3D getT1() { return t1; }
	void setT1(Vector3D v) { t1 = v; }
	Vector3D getT2() { return t2; }
	void setT2(Vector3D v) { t2 = v; }
	void setTextures(Vector3D v0, Vector3D v1, Vector3D v2) { t0 = v0; t1 = v1; t2 = v2; }*/


	void Render();
};

