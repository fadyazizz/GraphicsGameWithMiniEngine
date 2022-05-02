#pragma once
#include "GameObject.h"
#include "Model_3DS.h"


class Tree :public GameObject {
public:
	Model_3DS tree;
	void draw();
	Tree(double translateX, double translateY, double translateZ, double scaleX, double scaleY, double scaleZ);

}; 
