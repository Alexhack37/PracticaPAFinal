#pragma once
#include "Camera.h"
#define _USE_MATH_DEFINES
#include<math.h>
#define degToRad(angleInDegrees) ((angleInDegrees) * M_PI / 180.0)
#define radToDeg(angleInRadians) ((angleInRadians) * 180.0 / M_PI)

class CameraFPS : public Camera
{
private:
	int mouseX;
	int mouseY;

	Vector3D speedVector;

	Vector3D calcSpeedVector();

	float cameraStep;

public:
	CameraFPS(Vector3D positionArgument) : Camera(Vector3D(),positionArgument),
		mouseX(-1), mouseY(-1), cameraStep(0.25) { };
	void Render();
	void Update(const float& time);

	void ProcessMouseMovement(int x, int y);
	void ProcessKeyPressed(unsigned char key, int px, int py);

	inline float GetMouseX() const { return this->mouseX; }
	inline void SetMouseX(const float& mousexToSet) { this->mouseX = mousexToSet; }

	inline float GetMouseY() const { return this->mouseY; }
	inline void SetMouseY(const float& mouseyToSet) { this->mouseY = mouseyToSet; }

	inline Vector3D GetSpeedVector() const { return this->speedVector; }
	inline void SetSpeedVector(const Vector3D& nuevoSpeedVector) { this->speedVector = nuevoSpeedVector; }

};

