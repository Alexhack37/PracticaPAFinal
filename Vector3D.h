#pragma once
#include <vector>

template <class S> class Vector3Dx;
typedef Vector3Dx<float> Vector3D;

typedef Vector3Dx<float> Vector3Df;
typedef Vector3Dx<double> Vector3Dd;
typedef Vector3Dx<int> Vector3Di;

template<class S> class Vector3Dx {
private:

	
	S x, y, z;

public:


	Vector3Dx(S x = 0, S y = 0, S z = 0): x(x), y(y), z(z){}




	inline S getCoordinateX() const { return x; }
	inline S getCoordinateY() const { return y; }
	inline S getCoordinateZ() const { return z; }




	inline void setCoordnateX(S d) { x = d; }
	inline void setCoordnateY(S d) { y = d; }
	inline void setCoordnateZ(S d) { z = d; }


	Vector3Dx<S> Add(Vector3Dx<S> v);
	Vector3Dx<S> Sub(Vector3Dx<S> v);
	Vector3Dx<S> Product(const float& v);
	Vector3Dx<S> MultValues(const Vector3D& v);


};

template <class S> Vector3Dx<S> Vector3Dx<S>::Add(Vector3Dx<S> v) {
	
	Vector3Dx<S> vector;
	vector.setCoordnateX(v.getCoordinateX() + x);
	vector.setCoordnateY(v.getCoordinateY() + y);
	vector.setCoordnateZ(v.getCoordinateZ() + z);
	return vector;
}
template <class S> Vector3Dx<S> Vector3Dx<S>::Sub(Vector3Dx<S> v) {
	
	Vector3Dx<S> vector;
	vector.setCoordnateX(v.getCoordinateX() - x);
	vector.setCoordnateY(v.getCoordinateY() - y);
	vector.setCoordnateZ(v.getCoordinateZ() - z);
	return vector;
}
template <class S> Vector3Dx<S> Vector3Dx<S>::Product(const float& v) {
	
	Vector3Dx<S> vector;
	vector.setCoordnateX(v * x);
	vector.setCoordnateY(v * y);
	vector.setCoordnateZ(v * z);
	return vector;
}

template <class S> Vector3Dx<S> Vector3Dx<S>::MultValues(const Vector3D& v) {
	Vector3Dx<S> vector;
	vector.setCoordnateX(x * v.getCoordinateX());
	vector.setCoordnateY(y * v.getCoordinateY());
	vector.setCoordnateZ(z * v.getCoordinateZ());
	return vector;
}