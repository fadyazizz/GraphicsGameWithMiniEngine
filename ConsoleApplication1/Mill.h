#pragma once
#include "GameObject.h"
#include <GL/glut.h>
#include "Model_3DS.h"
class Mill :public GameObject {
public:



	Model_3DS mill;
	void draw();
	Mill(double translateX, double translateY, double translateZ, double scaleX, double scaleY, double scaleZ);
	
};