#include "Color.h"
/*
void Scene::Render() {
	for (size_t i = 0; i < gameObjects.size(); i++){
		gameObjects[i]->Render();
	}
}
*/
void Color::setRedComponent(float valor) {
	if (valor > 1.0) {
		valor = 1.0;
	}
	else if (valor < 0) {
		valor = 0.0;
	}
	redComponent = valor;
}
void Color::setBluecomponent(float valor) {
	if (valor > 1.0) {
		valor = 1.0;
	}
	else if (valor < 0) {
		valor = 0.0;
	}
	blueComponent = valor;
}
void Color::setGreenComponent(float valor) {
	if (valor > 1.0) {
		valor = 1.0;
	}
	else if (valor < 0) {
		valor = 0.0;
	}
	greenComponent = valor;
}