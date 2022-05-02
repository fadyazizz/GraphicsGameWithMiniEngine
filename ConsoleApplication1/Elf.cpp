#include "Elf.h"
#include <windows.h>


Elf ::Elf(double translateX, double translateY, double translateZ, double scaleX, double scaleY, double scaleZ) {
	setUp(translateX, translateY, translateZ, scaleX, scaleY, scaleZ);
	this->tag = "elf";
	std::cout  << this->tag << std::endl;
	char file[] = "Models/elf/elf.3ds";
	elf.Load(file);
	elf.lit = false;
	//std::cout << elf.scale << "elf" << std::endl;
	elf.scale = 0.005;
	this->gift = new Gift(translateX, translateY-0.03, translateZ, 0.02, 0.02, 0.02);
	//this->gift->gift.scale = 0.0001;
	//this->gift->canCollide = false;

	this->canCollide = true;
	this->isTrigger = true;
	this->isDebug = true;
}


void Elf::draw() {
	glPushMatrix();
	glTranslatef(translateX, translateY, translateZ);
	glRotated(90, 1, 0, 0);


	//glScalef(scaleX, scaleY,scaleZ);
	elf.Draw();

	glPopMatrix();
	if(hasGift){
		gift->draw();
	}
	
	if (this->isDebug) {
		this->debug();
	}
}