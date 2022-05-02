#include "Shovel.h"
#include <windows.h>


Shovel::Shovel(double translateX, double translateY, double translateZ, double scaleX, double scaleY, double scaleZ) {
	setUp(translateX, translateY, translateZ, scaleX, scaleY, scaleZ);
	this->tag = "shovel";
	char file[] = "Models/shovel/shovel.3ds";
	shovel.Load(file);
	shovel.lit = false;
	//std::cout << shovel.scale << "here" << std::endl;
	shovel.scale = 0.00001;
	this->canCollide = true;
	this->isTrigger = true;
	
}


void Shovel::draw() {
	glPushMatrix();
	glTranslatef(translateX, translateY, translateZ);
	glRotated(90, 1, 0, 0);

	glRotated(90, 0, 1, 0);
	glRotated(90, 0, 0, 1);

	//glScalef(scaleX, scaleY,scaleZ);
	shovel.Draw();

	glPopMatrix();
	if (this->isDebug) {
		this->debug();
	}
}