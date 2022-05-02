#pragma once
#include "GameObject.h"

#include "Model_3DS.h"

class Sleigh :public GameObject {
public:
	Model_3DS sleigh;
	void draw();
	Sleigh(double translateX, double translateY, double translateZ, double scaleX, double scaleY, double scaleZ);

};