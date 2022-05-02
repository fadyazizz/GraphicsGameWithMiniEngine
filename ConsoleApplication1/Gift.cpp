#include "Gift.h"
#include <windows.h>




Gift::Gift(double translateX, double translateY, double translateZ, double scaleX, double scaleY, double scaleZ) {
	setUp(translateX, translateY, translateZ, scaleX, scaleY, scaleZ);
	this->tag = "shovel";
	char file[] = "Models/gift/gift1.3ds";
	gift.Load(file);
	gift.lit = false;
	//std::cout << shovel.scale << "here" << std::endl;
	gift.scale = 0.0001;
	//this->canCollide = true;
}


void Gift::draw() {
	glPushMatrix();
	glTranslatef(translateX, translateY, translateZ);
	glRotated(90, 1, 0, 0);

	
	gift.Draw();

	glPopMatrix();
	
}