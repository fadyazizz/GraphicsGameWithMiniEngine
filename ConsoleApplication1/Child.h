#pragma once

#include "GameObject.h"

#include "Model_3DS.h"
#include "Gift.h"
class Child :public GameObject {
public:
	bool hasGift = false;

	Model_3DS child;
	Gift* gift;
	void draw();
	Child(double translateX, double translateY, double translateZ, double scaleX, double scaleY, double scaleZ);

};