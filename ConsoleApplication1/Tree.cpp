#include "Tree.h"
#include <windows.h>




int no = 0;
Tree::Tree(double translateX, double translateY, double translateZ, double scaleX, double scaleY, double scaleZ) {
	setUp(translateX, translateY, translateZ, scaleX, scaleY, scaleZ);
	this->tag = "tree";
	if (no == 1) {
		char file[] = "Models/tree2/tree1/tree.3ds";
		tree.Load(file);
		tree.scale = 0.001;
	}
	else {
		char file[] = "Models/tree/tree1.3ds";
		tree.Load(file);
		tree.scale = 0.1;
	}
	
	tree.lit = false;
	//std::cout << shovel.scale << "here" << std::endl;
	
	this->canCollide = true;
	this->isTrigger = true;
	
}


void Tree::draw() {
	glPushMatrix();
	glTranslatef(translateX, translateY, translateZ);
	glRotated(90, 1, 0, 0);

	glRotated(0, 0, 1, 0);
	glRotated(0, 0, 0, 1);

	//glScalef(scaleX, scaleY,scaleZ);
	tree.Draw();

	glPopMatrix();
	if (this->isDebug) {
		this->debug();
	}
}