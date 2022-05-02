#pragma once

#include "GameObject.h"
class UI :public GameObject {

public:
	bool con = false;
	float x = 0;
	float y = 0;
	float z = 0;
	int sc;
	UI(float minX, float maxX, float minY,float maxY, std::string tag);
	void draw();
	void playSound();
};

extern int timeToEnd;
