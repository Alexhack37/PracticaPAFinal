#include "contorno.h"
Contorno::~Contorno() {
	// TODO Auto-generated destructor stub
}

bool Contorno::colision(Plano* pl) {
	Vector3D vn(pl->getA(), pl->getB(), pl->getC());
	return fabs(vn.DotProduct(p) - pl->getD()) < r;
}
bool Contorno::colision(EsferaColision* e) {
	Vector3D pe = e->getPos();
	float re = e->getR();
	Vector3D vd = pe.Sub(p);
	float l = vd.Modulo();
	return l < r + re;
}
bool Contorno::colision(CuboColision* c) {
	Vector3D pc = c->getPos();
	float rc = c->getS();
	Vector3D vd = pc.Sub(p);
	float l = vd.Modulo();
	return l < r + rc;
}

bool Contorno::colision(Proyectil* bala)
{
	Vector3D pb = bala->getPos();
	float rb = bala->getRadio();
	Vector3D vd = pb.Sub(p);
	float l = vd.Modulo();
	return l < r + rb;
}
bool Contorno::colision(Model* modelo)
{
	Vector3D pm = modelo->getPos();
	float rm = modelo->GetScala();
	Vector3D vd = pm.Sub(p);
	float l = vd.Modulo();
	return l < r + rm;
}
//bool Contorno::colision(ModelLoader* modelo)
//{
//	Vector3D pm = modelo->GetModel().getPos();
//	float rm = modelo->GetScala();
//	Vector3D vd = pm.Sub(p);
//	float l = vd.Modulo();
//	return l < r + rm;
//}
