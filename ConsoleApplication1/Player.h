#pragma once
#include "GameObject.h"
#include <GL/glut.h>
#include "Model_3DS.h"
class Player :public GameObject {
public:
	Model_3DS santa;
	void move(double dx, double dy);
	void draw();
	Player(double translateX, double translateY, double translateZ, double scaleX, double scaleY, double scaleZ);
	void handleTriggerEvent(GameObject* g, int index);
};
