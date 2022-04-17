#pragma once
#include <GL/glut.h>
#include "Vector3D.h"
#include "Color.h"
#include "Solid.h"

class Cylider: public Solid
{
private:

	double m_baseRadius{};
	double m_topRadius{};
	double m_height{};
	int m_slices{};
	int m_stacks{};


public:

	Cylider(Vector3D v = Vector3D(0.0, 0.0, 0.0),
		Vector3D a = Vector3D(0.0, 0.0, 0.0),
		Color c = Color(0.0, 0.0, 0.0),
		Vector3D o = Vector3D(0.0, 0.0, 0.0),
		Vector3D s = Vector3D(0.0, 0.0, 0.0),
		double baseRadius = 1.0,
		double topRadious = 1.0,
		double height = 3.0,
		int slices = 20,
		int stacks = 20)
		:Solid{ v, a, c, o, s },
		m_baseRadius{ baseRadius },
		m_topRadius{ topRadious },
		m_height{ height },
		m_slices{ slices },
		m_stacks{ stacks }	{}
	
	inline float getBaseradius() const { return this->m_baseRadius; }
	inline void  setBaseradius(const  float& baseRadiusToSet) { this->m_baseRadius = baseRadiusToSet; }

	inline float getTopRadius() const { return this->m_topRadius; }
	inline void  setTopRadius(const  float& topRadiusToSet) { this->m_topRadius = topRadiusToSet; }


	inline float getHeight() const { return this->m_height; }
	inline void  setHeight(const  float& heightToSet) { this->m_height = heightToSet; }

	inline float getSlices() const { return this->m_slices; }
	inline void  setslices(const  float& slicesToSet) { this->m_slices = slicesToSet; }

	inline float getStacks() const { return this->m_stacks; }
	inline void  setStackas(const  float& stacksToSet) { this->m_stacks = stacksToSet; }


	void Render();
};

