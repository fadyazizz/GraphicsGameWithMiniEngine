#pragma once
#include "GameObject.h"


#include <GL/glut.h>

class Ground:public GameObject{
public:

	Ground();
	void draw();
	void animate();

};
