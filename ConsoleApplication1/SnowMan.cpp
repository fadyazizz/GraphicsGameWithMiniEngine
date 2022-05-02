#include "SnowMan.h"
#include <windows.h>



SnowMan::SnowMan(double translateX, double translateY, double translateZ, double scaleX, double scaleY, double scaleZ) {
	setUp(translateX, translateY, translateZ, scaleX, scaleY, scaleZ);
	this->tag = "snowMan";
	char file[] = "Models/snowMan/snowman.3ds";
	snowMan.Load(file);
	snowMan.lit = false;
	std::cout << snowMan.scale <<"here"<< std::endl;
	snowMan.scale = 0.01;
	this->canCollide = true;
	this->isTrigger = true;
}


void SnowMan::draw() {
	glPushMatrix();
	glTranslatef(translateX, translateY, translateZ);
	glRotated(90, 1, 0, 0);

	glRotated(90, 0, 1, 0);


	//glScalef(scaleX, scaleY,scaleZ);
	snowMan.Draw();

	glPopMatrix();
	//this->debug();
}