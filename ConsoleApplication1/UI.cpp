
#include "UI.h"
#include <string>
#include "Engine.h"
#include<GL/glut.h>

UI::UI(float minX, float maxX, float minY, float maxY, std::string tag) {
	//std::cout << tag << "ui" << std::endl;
	this->tag = tag;
}
void UI::draw() {
	//glColor3f(1, 1, 1);






	std::string s;





			s = this->tag;

			if (this->tag == "score") {
				std::cout << tag << "ui" << std::endl;

				s = "score: "+ std::to_string(score);
				glRasterPos3f(this->x, this->y,this->z);
			}
			else {

				if(this->tag=="i"){
					s = "please wait for level 2 to load";
				}
			else {
			glRasterPos2f(0, 0);
			}

			}

	for (int i = 0; i < s.length(); i++)
	{

		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, (int)s[i]);
	}


}
void UI::playSound() {

}
