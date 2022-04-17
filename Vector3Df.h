#pragma once

template <class S> class Vector3Dx;
typedef Vector3Dx<float> Vector3D;

typedef Vector3Dx<float> Vector3Df;
typedef Vector3Dx<double> Vector3Dd;
typedef Vector3Dx<int> Vector3Di;
class Vector3Df{

private:
	float coordinateX;
	float coordinateY;
	float coordinateZ;

public:

	Vector3Df(float x, float y, float z)
	{
	coordinateX = x;
	coordinateY = y;
	coordinateZ = z;
	}
};