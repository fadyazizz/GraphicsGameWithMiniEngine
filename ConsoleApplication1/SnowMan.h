#pragma once
#include "GameObject.h"
#include "Model_3DS.h"

class SnowMan :public GameObject {
public:
	Model_3DS snowMan;
	void draw();
	SnowMan(double translateX, double translateY, double translateZ, double scaleX, double scaleY, double scaleZ);
	
};