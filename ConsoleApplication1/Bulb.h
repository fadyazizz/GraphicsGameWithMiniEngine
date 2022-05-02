#pragma once
#include "GameObject.h"
#include "Model_3DS.h"
class Bulb :public GameObject {
public:
	Model_3DS bulb;
	void draw();
	Bulb(double translateX, double translateY, double translateZ, double scaleX, double scaleY, double scaleZ);

};