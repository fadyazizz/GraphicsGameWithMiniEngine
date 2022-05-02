
#include "Mill.h"

Mill::Mill(double translateX, double translateY, double translateZ, double scaleX, double scaleY, double scaleZ) {
	setUp(translateX, translateY, translateZ, scaleX, scaleY, scaleZ);
	this->tag = "mill";
	char file[] = "Models/house/house.3ds";
	mill.Load(file);
	mill.lit = false;
	std::cout << mill.scale << std::endl;
	mill.scale = 0.06;
	this->canCollide = true;
	this->isTrigger = true;
}



void Mill::draw() {


	glPushMatrix();
	glTranslatef(translateX, translateY, translateZ);
	glRotated(90, 1, 0, 0);

	glRotated(90, 0, 1, 0);


	//glScalef(scaleX, scaleY,scaleZ);
	mill.Draw();

	glPopMatrix();
	if (this->isDebug) {
		this->debug();
	}

}