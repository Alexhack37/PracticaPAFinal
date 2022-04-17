#pragma once
template <class S> class Vector3Dx;
typedef Vector3Dx<int> Vector3D;

typedef Vector3Dx<float> Vector3Df;
typedef Vector3Dx<double> Vector3Dd;
typedef Vector3Dx<int> Vector3Di;
class Vector3Di {

private:
	int coordinateX;
	int coordinateY;
	int coordinateZ;

public:

	Vector3Di(int x, int y, int z)
	{
		coordinateX = x;
		coordinateY = y;
		coordinateZ = z;
	}
};