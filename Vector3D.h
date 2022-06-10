#pragma once
#include <vector>
#include <math.h> 
template <class S> class Vector3Dx;
typedef Vector3Dx<double> Vector3D;

typedef Vector3Dx<float> Vector3Df;
typedef Vector3Dx<double> Vector3Dd;
typedef Vector3Dx<int> Vector3Di;

template<class S> class Vector3Dx {
private:

	
	S x, y, z;

public:

	//Vector3Dx() :x(0), y(0), z(0) {}
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
	Vector3Dx<S> Normalizar();
	Vector3Dx<S> crossProduct(const Vector3D& v);
	float DotProduct(Vector3Dx<S> v);
	float Modulo();

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

template <class S> Vector3Dx<S> Vector3Dx<S>::Normalizar() {
	Vector3Dx<S> vector;
	float modulo = vector.Modulo();
	vector.setCoordnateX(x / modulo);
	vector.setCoordnateY(y / modulo);
	vector.setCoordnateZ(z / modulo);
	return vector;
}


template<class S>float Vector3Dx<S>::DotProduct(Vector3Dx<S> v)
{
	float dotProd;
	Vector3Dx<S> vector;
	dotProd = (vector.getCoordinateX() * v.getCoordinateX()) + (vector.getCoordinateY() * v.getCoordinateY()) + (vector.getCoordinateZ() * v.getCoordinateZ());
	return dotProd;
}

//Vector3D crossProduct(const Vector3D v1, const Vector3D v2) {
//	return Vector3D(
//		v1.getCoordinateY() * v2.getCoordinateZ() - v1.getCoordinateZ() * v2.getCoordinateY(),
//		v1.getCoordinateZ() * v2.getCoordinateX() - v1.getCoordinateX() * v2.getCoordinateZ(),
//		v1.getCoordinateX() * v2.getCoordinateY() - v1.getCoordinateY() * v2.getCoordinateX());
//}
template <class S> Vector3Dx<S> Vector3Dx<S>::crossProduct(const Vector3D& v) {
	Vector3Dx<S> vector;
	vector.setCoordnateX((y * v.getCoordinateZ()) - (z * v.getCoordinateY()));
	vector.setCoordnateY((z * v.getCoordinateX()) - (x * v.getCoordinateZ()));
	vector.setCoordnateZ((x * v.getCoordinateY()) - (y * v.getCoordinateX()));
	return vector;
}
template<class S>float Vector3Dx<S>::Modulo()
{
	float Mod;
	Mod = sqrt((x * x) + (y * y) + (z * z));
	return Mod;
}
