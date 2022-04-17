#pragma once
template <class S> class Vector3Dx;
typedef Vector3Dx<double> Vector3D;

typedef Vector3Dx<float> Vector3Df;
typedef Vector3Dx<double> Vector3Dd;
typedef Vector3Dx<int> Vector3Di;

class Vector3Dd {

private:
	double coordinateX;
	double coordinateY;
	double coordinateZ;

public:

	Vector3Dd(double x, double y, double z)
	{
		coordinateX = x;
		coordinateY = y;
		coordinateZ = z;
	}
};