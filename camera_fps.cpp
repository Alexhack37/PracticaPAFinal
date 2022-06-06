#include "camera_fps.h"
void CameraFPS :: Render()
{
	glRotatef(this->getAngulo().getCoordinateX(), 1, 0, 0);
	glRotatef(this->getAngulo().getCoordinateY(), 0, 1, 0);
	glRotatef(this->getAngulo().getCoordinateZ(), 0, 0, 1);
	glTranslatef(-1 * this->getPos().getCoordinateX(), -1 * this->getPos().getCoordinateY(), -1 * this->getPos().getCoordinateZ());
}

void CameraFPS::Update(const float& time)
{
	this->setSpeed(this->calcSpeedVector());
	//Camera::Update(time);
}

Vector3D CameraFPS::calcSpeedVector()
{
	float yOrientation = degToRad(this->getAngulo().getCoordinateY());
	float xOrientation = degToRad(this->getAngulo().getCoordinateX());

	//Flying camera
	float xComponent = sin(yOrientation) * cos(xOrientation);
	float yComponent = -sin(xOrientation);
	float zComponent = -cos(yOrientation) * cos(xOrientation);

	//Walking camera
	//float xComponent = sin(yOrientation);
	//float yComponent = 0;
	//float zComponent = -cos(yOrientation);

	Vector3D speedVector = { xComponent, yComponent, zComponent };
	//std::cout << "La posicion de la camara es esta, es un peligro " << this->getPos().getCoordinateX() << " " << this->getPos().getCoordinateY() << " " << this->getPos().getCoordinateZ() << std::endl;
	//Vector3D speedVector = { 0, 0, 0 };
	return speedVector;
}

void CameraFPS::ProcessKeyPressed(unsigned char key, int px, int py)
{
	switch (key)
	{
		case 'w':
		case 'W':
			this->Update(this->cameraStep);
			break;
		case 's':
		case 'S':
			this->Update(-1 * this->cameraStep);
			break;
	}
}
void CameraFPS::ProcessMouseMovement(int x, int y)
{
	if (this->GetMouseX() >= 0 && this->GetMouseY() >= 0)
	{
		Vector3D orientation = this->getAngulo().Add(Vector3D(y - this->GetMouseY(),
			x - this->GetMouseX(), 0));
		this->setAngulo(orientation);
	}
	this->SetMouseX(x);
	this->SetMouseY(y);
}