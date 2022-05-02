#include "Sleigh.h"
#include <windows.h>


Sleigh::Sleigh(double translateX, double translateY, double translateZ, double scaleX, double scaleY, double scaleZ) {
	setUp(translateX, translateY, translateZ, scaleX, scaleY, scaleZ);
	this->tag = "shovel";
	char file[] = "Models/sleigh/sleigh.3ds";
	sleigh.Load(file);
	sleigh.lit = false;
	//std::cout << shovel.scale << "here" << std::endl;
	sleigh.scale = 0.02;
	this->canCollide = true;
	this->isTrigger = true;
}


void Sleigh::draw() {
	glPushMatrix();
	glTranslatef(translateX, translateY, translateZ);
	glRotated(90, 1, 0, 0);

	glRotated(0, 0, 1, 0);
	glRotated(0, 0, 0, 1);

	//glScalef(scaleX, scaleY,scaleZ);
	sleigh.Draw();

	glPopMatrix();
	if (this->isDebug) {
		this->debug();
	}
}