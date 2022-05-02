#include "Bulb.h"
#include <windows.h>

#include <GL/glut.h>


Bulb::Bulb(double translateX, double translateY, double translateZ, double scaleX, double scaleY, double scaleZ) {
	setUp(translateX, translateY, translateZ, scaleX, scaleY, scaleZ);
	this->tag = "shovel";
	char file[] = "Models/bulb/bulb.3ds";
	bulb.Load(file);
	bulb.lit = false;
	//std::cout << shovel.scale << "here" << std::endl;
	bulb.scale = 0.0005;
	this->debug();
	//this->canCollide = true;
}

float color1 = 0;
float color2 = 0.5;
void Bulb::draw() {
	if (color1 >= 1) {
		color1 = 0;
		std::cout <<  "herecc" << std::endl;
	}
	if (color2 >= 1) {
		color2 = 0;
		std::cout << "herecc" << std::endl;
	}
	color2 = color2+0.01;
	color1 = color1 + 0.01;
	glPushMatrix();
	glTranslatef(translateX, translateY, translateZ);
	glRotated(90, 1, 0, 0);


	//bulb.Draw();

	glPopMatrix();
	



	GLfloat lightPosition[] = { 0, -0.5, 0.5, 0.0f };

	GLfloat lightIntensity[] = { 0.0, 0.0, color1, 0 };

	glLightfv(GL_LIGHT1, GL_POSITION, lightPosition);
	
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightIntensity);
	glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 1.0f);





	GLfloat lightPosition1[] = { -1, -1.5, 0.2, 0.0f };

	GLfloat lightIntensity1[] = { color2, 0.0, 0, 0 };

	glLightfv(GL_LIGHT2, GL_POSITION, lightPosition1);

	glLightfv(GL_LIGHT2, GL_DIFFUSE, lightIntensity1);
	glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, 1.0f);




	// uncomment this line if you want to see the collider
	//this->debug();
}