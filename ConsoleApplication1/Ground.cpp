
#include "Ground.h"
#include "Model_3DS.h"
#include "TextureBuilder.h"

void Ground::animate() {

}
int counter = 0;
GLTexture tex_ground;
GLTexture tex_ground1;
Ground::Ground() {
	this->setUpCollider(-5, 5, -5, 5, 0, 0);
	canCollide = false;

	char file[] = "Textures/snow2.bmp";
		tex_ground.Load(file);

	//counter++;
	//loadBMP(&tex, "Textures/ground.bmp", true);
}
void Ground::draw() {
	//glDisable(GL_LIGHTING);	// Disable lighting

	//glColor3f(0.6, 0.6, 0.6);	// Dim the ground texture a bit
	if (counter == 0) {
		glEnable(GL_TEXTURE_2D);	// Enable 2D texturing


		//The texture wraps over the edges (repeats) in the y direction
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
		glBindTexture(GL_TEXTURE_2D, tex_ground.texture[0]);	// Bind the ground texture
		/*glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);*/
		glPushMatrix();
		glBegin(GL_QUADS);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_CLAMP);
		glNormal3f(0, 1, 0);
		// Set quad normal direction.
		glTexCoord2f(0, 0);		// Set tex coordinates ( Using (0,0) -> (5,5) with texture wrapping set to GL_REPEAT to simulate the ground repeated grass texture).
		glVertex3f(-1.5, -1.5, 0);
		glTexCoord2f(1, 0);
		glVertex3f(1.5, -1.5, 0);
		glTexCoord2f(1, 1);
		glVertex3f(1.5, 1.5, 0);
		glTexCoord2f(0, 1);
		glVertex3f(-1.5, 1.5, 0);
		glEnd();
		glPopMatrix();
	}
	if (counter == 1) {
		glEnable(GL_TEXTURE_2D);	// Enable 2D texturing


		//The texture wraps over the edges (repeats) in the y direction
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
		glBindTexture(GL_TEXTURE_2D, tex_ground1.texture[0]);	// Bind the ground texture
		/*glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);*/
		glPushMatrix();
		glBegin(GL_QUADS);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_CLAMP);
		glNormal3f(0, 1, 0);
		// Set quad normal direction.
		glTexCoord2f(0, 0);		// Set tex coordinates ( Using (0,0) -> (5,5) with texture wrapping set to GL_REPEAT to simulate the ground repeated grass texture).
		glVertex3f(-1.5, -1.5, 0);
		glTexCoord2f(1, 0);
		glVertex3f(1.5, -1.5, 0);
		glTexCoord2f(1, 1);
		glVertex3f(1.5, 1.5, 0);
		glTexCoord2f(0, 1);
		glVertex3f(-1.5, 1.5, 0);
		glEnd();
		glPopMatrix();
	}
	//glEnable(GL_LIGHTING);	// Enable lighting again for other entites coming throung the pipeline.

	//glColor3f(1, 1, 1); //Set material back to white instead of grey used for the ground texture.

}
