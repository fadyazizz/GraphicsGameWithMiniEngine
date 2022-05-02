#include "GameObject.h"

#include <GL/glut.h>

void GameObject::setUpCollider(double minX, double maxX, double minY, double maxY,double minZ,double maxZ) {
	vector<int> v1;
	this->maxX = maxX;
	this->minX = minX;
	this->maxY = maxY;
	this->minY = minY;
	this->minZ = minZ;
	this->maxZ = maxZ;

}

void GameObject::setUpScale(double scaleX, double scaleY, double scaleZ) {
	this->scaleX = scaleX;
	this->scaleY = scaleY;
	this->scaleZ = scaleZ;
}
 void GameObject::setUp(double translateX, double translateY, double translateZ, double scaleX, double scaleY, double scaleZ) {
	 double scaleXhalf = scaleX / 2;
	 double scaleYhalf = scaleY / 2;
	 double scaleZhalf = scaleZ / 2;
	 this->translateX = translateX;
	 this->translateY = translateY;
	 this->translateZ = translateZ;

	 //std::cout << translateZ-scaleYhalf;
	 this->setUpCollider(translateX - abs(scaleXhalf), translateX + abs(scaleXhalf), translateY - abs(scaleYhalf), translateY + abs(scaleYhalf), translateZ - abs(scaleZhalf), translateZ + abs(scaleZhalf));
	 this->setUpScale(scaleX, scaleY, scaleZ);
}
 void GameObject:: debug() {
	 glPushMatrix();
	 glTranslated(translateX, translateY, translateZ);
	 glScaled(scaleX, scaleY, scaleZ);
	 glutWireCube(1);
	 glPopMatrix();




	 glBegin(GL_POLYGON);
	 glVertex2f(this->minX, this->minY);
	 glVertex2f(this->maxX, this->minY);
	 glVertex2f(this->maxX, this->maxY);
	 glVertex2f(this->minX, this->maxY);
	 glEnd();
 }
