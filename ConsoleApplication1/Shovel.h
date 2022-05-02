#pragma once
#include "GameObject.h"

#include "Model_3DS.h"

class Shovel :public GameObject {
public:
	Model_3DS shovel;
	void draw();
	Shovel(double translateX, double translateY, double translateZ, double scaleX, double scaleY, double scaleZ);

};