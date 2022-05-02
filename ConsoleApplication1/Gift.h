#pragma once
#include "GameObject.h"
#include "Model_3DS.h"
class Gift :public GameObject {
public:
	Model_3DS gift;
	void draw();
	Gift(double translateX, double translateY, double translateZ, double scaleX, double scaleY, double scaleZ);

};