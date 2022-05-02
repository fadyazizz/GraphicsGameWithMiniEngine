#include "Child.h"
#include <windows.h>


Child::Child(double translateX, double translateY, double translateZ, double scaleX, double scaleY, double scaleZ) {
	setUp(translateX, translateY, translateZ, scaleX, scaleY, scaleZ);
	this->tag = "child";
	std::cout << this->tag << std::endl;
	char file[] = "Models/child/child.3ds";
	child.Load(file);
	child.lit = false;
	//std::cout << elf.scale << "elf" << std::endl;
	child.scale = 0.1;
	this->gift = new Gift(translateX, translateY+0.04 , translateZ+0.08, 0.02, 0.02, 0.02);
	//this->gift->gift.scale = 0.0001;
	//this->gift->canCollide = false;

	this->canCollide = true;
	this->isTrigger = true;
}


void Child::draw() {
	glPushMatrix();
	glTranslatef(translateX, translateY, translateZ);
	glRotated(90, 1, 0, 0);
	//glRotated(90, 0, 0, 1);

	//glScalef(scaleX, scaleY,scaleZ);
	child.Draw();

	glPopMatrix();
	if (hasGift) {
		gift->draw();
	}
	if (this->isDebug) {
		this->debug();
	}
}