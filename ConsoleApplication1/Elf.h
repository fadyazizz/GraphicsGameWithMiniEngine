#pragma once

#include "GameObject.h"

#include "Model_3DS.h"
#include "Gift.h"
class Elf :public GameObject {
public:
	bool hasGift = true;
	
	Model_3DS elf;
	Gift* gift;
	void draw();
	Elf(double translateX, double translateY, double translateZ, double scaleX, double scaleY, double scaleZ);

};