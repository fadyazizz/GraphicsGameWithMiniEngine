#pragma once

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "Vector3f.h"
#include "Camera.h"
#include <vector>
#include "GameObject.h"
#include "Ground.h"
#include "Player.h"
#include "SnowMan.h"
#include <time.h>
#include <windows.h>
#include "Mill.h"
#include "Shovel.h"
#include "Sleigh.h"
#include "Tree.h"
#include "Elf.h"
#include "Bulb.h"
#include "UI.h"
#include "Child.h"
#include <string>

#define GLUT_KEY_ESCAPE 27
using std::vector;

vector<GameObject*> objectsInScene;


double ratio = 680 / 680;
Camera camera;
float angle = 0;
bool inc = false;
float color = 1;
int level = 0;
bool moveIt = false;
double dx = 0;
double dy = 0;
Player* player;



void collisionEngine() {
	glm::mat4 trans = glm::mat4(1.0f);
	trans = glm::rotate(trans, glm::radians((float)rotate), glm::vec3(0.0f, 0.0f, 1.0f));

	glm::vec4 result = trans * glm::vec4(dx, dy, 0.0f, 1.0f);


	double maxXMover = player->maxX + result.x;
	double minXMover = player->minX + result.x;
	double maxYMover = player->maxY + result.y;
	double minYMover = player->minY + result.y;
	bool collid = false;

	for (int j = 0; j < objectsInScene.size(); j++) {
		if (objectsInScene.at(j)->tag == player->tag) {
			continue;
		}
		// check whether this gameObject can collide with its surroundings or not
		if (!objectsInScene.at(j)->canCollide) {
			// this object is an isTrigger one, so it cant collide
			continue;
		}
		GameObject* temp = objectsInScene.at(j);
		double maxXScene = temp->maxX;
		double minXScene = temp->minX;
		double maxYScene = temp->maxY;
		double minYScene = temp->minY;
		if (((maxXMover >= minXScene && maxXMover <= maxXScene) || (maxXScene >= minXMover && maxXScene <= maxXMover))) {

			if ((maxYMover >= maxYScene && maxYScene >= minYMover) || (maxYMover <= maxYScene && minYMover >= minYScene) || (maxYMover >= minYScene && minYScene >= minYMover)) {
				std::cout << "Collision! with: " << temp->tag << std::endl;
				std::cout << temp->tag << "'s minX: " << temp->minX << " maxX: " << temp->maxX << " minY: " << temp->minY << " maxY: " << temp->maxY << std::endl;
				std::cout << "player" << "'s minX: " << player->minX << " maxX: " << player->maxX << " minY: " << player->minY << " maxY: " << player->maxY << std::endl;
				//LPCWSTR sound = L"EnemyExplosion.wav";
				//PlaySound(sound, NULL, SND_ASYNC | SND_FILENAME);
				if (objectsInScene.at(j)->hasSound) {

					//objectsInScene.at(j)->playSound();

				}
				if (objectsInScene.at(j)->isTrigger) {

					player->handleTriggerEvent(objectsInScene.at(j), j);

				}
				if (objectsInScene.at(j)->canCollide) {
					collid = true;
					break;
				}

			}
		}

	}
	if (!collid) {
		player->move(dx, dy);
	}
	else {
		player->move(0, 0);
	}
}

void setupLights() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	angle = angle + 0.1;
	glm::mat4 trans = glm::mat4(1.0f);
	trans = glm::rotate(trans, glm::radians((float)angle), glm::vec3(1.0f, 0.0f, 0.0f));

	glm::vec4 result = trans * glm::vec4(0, 0.2, 2.0f, 1.0f);
	glPushMatrix();
	glTranslated(result.x, result.y, result.z);
	glScaled(0.1, 0.1, 0.1);
	glutWireCube(1);
	glPopMatrix();
		GLfloat ambient[] = { color,color, color, 0.0f };

		GLfloat specular[] = { .5f, .5f, 1.0, 1.0f };




		GLfloat lightPosition[] = { result.x, result.y, result.z, 0.0f };

		GLfloat lightIntensity[] = { 0.0, 0.0, 0.0, 1 };

		glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
		glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);





}
void setupCamera() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90,  ratio, 0.001, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if (gameOver) {
		camera.lookAtUI();
	}
	else {
		camera.look();
	}


}
void createGround() {
	Ground* g = new Ground();
	objectsInScene.push_back(g);
}


void createPlayer() {
	Player* p = new Player(1, 0.5, 0.09, 0.1, 0.1, 0.2);
	player = p;
	objectsInScene.push_back(p);
}
void createSnowMan() {
	SnowMan* s = new SnowMan(-.50, -1, 0.01, 0.1, 0.1, 0.2);
	objectsInScene.push_back(s);
}
void createMill() {
	Mill* m = new Mill(-0.3, 0.3, 0.002, 0.6, 0.6, 0.6);
	objectsInScene.push_back(m);
}
void createShovel() {
	Shovel* s = new Shovel(-1, 0.5, 0.03, 0.05, 0.12, 0.1);
	objectsInScene.push_back(s);
}
void createSleigh() {
	Sleigh* s = new Sleigh(1, -0.5, 0.11, 0.25, 0.22, 0.2);
	objectsInScene.push_back(s);
}
void createTree() {
	Tree* t = new Tree(.5, -0.0, 0.0, 0.25, 0.22, 0.2);

	//Tree* t2 = new Tree(0.5, -1.0, 0.0, 0.25, 0.22, 0.2);
	objectsInScene.push_back(t);

	//objectsInScene.push_back(t2);
}
void createElf() {
	Elf* e = new Elf(0.5, 1, 0.05, .04, 0.05, 0.1);
	Elf* e1 = new Elf(1, 1, 0.05, .04, 0.05, 0.1);
	Elf* e2 = new Elf(-0.9, 0.9, 0.05, .04, 0.05, 0.1);
	Elf* e3 = new Elf(-0.5, -.5, 0.05, .04, 0.05, 0.1);
	Elf* e4 = new Elf(-1, -1, 0.05, .04, 0.05, 0.1);
	objectsInScene.push_back(e);
	objectsInScene.push_back(e1);
	objectsInScene.push_back(e2);
	objectsInScene.push_back(e3);
	objectsInScene.push_back(e4);
}
void createBulb() {
	Bulb* b = new Bulb(1, -1.0, 0.0, 0.01, 0.01, 0.01);
	objectsInScene.push_back(b);
}

void createPlayer2() {
	Player* p = new Player(0, -1.1, 0.09, 0.1, 0.1, 0.2);
	player = p;
	objectsInScene.push_back(p);
}
void createSnowMan2() {
	SnowMan* s = new SnowMan(-1.0, -1, 0.01, 0.1, 0.1, 0.2);
	SnowMan* s2 = new SnowMan(-1.0, -0.5, 0.01, 0.1, 0.1, 0.2);
	objectsInScene.push_back(s);
	objectsInScene.push_back(s2);
}
void createMill2() {
	Mill* m = new Mill(-1, 1, 0.002, 0.6, 0.6, 0.6);
	Mill* m2 = new Mill(-1, -0.2, 0.002, 0.6, 0.6, 0.6);
	objectsInScene.push_back(m);
	objectsInScene.push_back(m2);
}
void createShovel2() {
	Shovel* s = new Shovel(1, 0.5, 0.03, 0.05, 0.12, 0.1);
	objectsInScene.push_back(s);
}
void createSleigh2() {
	Sleigh* s = new Sleigh(1, -1., 0.11, 0.25, 0.22, 0.2);
	objectsInScene.push_back(s);
}
void createTree2() {
	Tree* t = new Tree(-0.5, 1, 0.0, 0.25, 0.22, 0.2);
	Tree* t2 = new Tree(-1.5, 0, 0.0, 0.25, 0.22, 0.2);
	//Tree* t2 = new Tree(0.5, -1.0, 0.0, 0.25, 0.22, 0.2);
	objectsInScene.push_back(t);
	objectsInScene.push_back(t2);
}
void createChildren() {
	Child* e = new Child(0.5, 1, 0.0, .04, 0.05, 0.1);
	Child* e1 = new Child(1, 1, 0.0, .04, 0.05, 0.1);
	Child* e2 = new Child(-1.4, 0.9, 0.0, .04, 0.05, 0.1);
	Child* e3 = new Child(-0.5, .1, 0.0, .04, 0.05, 0.1);
	Child* e4 = new Child(-1, -0.7, 0.0, .04, 0.05, 0.1);
	objectsInScene.push_back(e);
	objectsInScene.push_back(e1);
	objectsInScene.push_back(e2);
	objectsInScene.push_back(e3);
	objectsInScene.push_back(e4);
}
void createLevel2() {

	createGround();
	createPlayer2();
	createSnowMan2();
	createMill2();
	createShovel2();
	createSleigh2();
	createTree2();
	//createElf2();
	createChildren();
	createBulb();

	//createUI();
}

void init() {

	createGround();
	createPlayer();
	createSnowMan();
	createMill();
	createShovel();
	createSleigh();
	createTree();
	createElf();

	createBulb();
	//createUI();
}
void Display() {

		setupCamera();

	setupLights();

	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for (int i = 0; i < objectsInScene.size(); i++) {
		objectsInScene.at(i)->draw();
	}
	if (!gameOver) {
		UI* ui = new UI(camera.eye.x, 0, camera.eye.y, 0, "score");
		ui->x = 0;
		ui->y = -1.5;
		ui->z = 0.2;
		ui->draw();
		UI* ui1 = new UI(camera.eye.x, 0, camera.eye.y, 0, "score");
		ui1->x = 0;
		ui1->y = 1.5;

		ui1->z = 0.2;
		ui1->draw();
		UI* ui2 = new UI(camera.eye.x, 0, camera.eye.y, 0, "score");
		ui2->x = 1.5;
		ui2->y = 0;

		ui2->z = 0.2;
		ui2->draw();

		UI* ui3 = new UI(camera.eye.x, 0, camera.eye.y, 0, "score");
		ui3->x = -1.5;
		ui3->y = 0;

		ui3->z = 0.2;
		ui3->draw();
	}
	if (gameOver && level == 0) {
		UI* ui = new UI(camera.eye.x, 0, camera.eye.y, 0, "i");
		ui->x = 0;
		ui->y = -1.5;
		ui->z = 0.2;
		ui->draw();
		UI* ui1 = new UI(camera.eye.x, 0, camera.eye.y, 0, "i");
		ui1->x = 0;
		ui1->y = 1.5;

		ui1->z = 0.2;
		ui1->draw();
		UI* ui2 = new UI(camera.eye.x, 0, camera.eye.y, 0, "i");
		ui2->x = 1.5;
		ui2->y = 0;

		ui2->z = 0.2;
		ui2->draw();

		UI* ui3 = new UI(camera.eye.x, 0, camera.eye.y, 0, "i");
		ui3->x = -1.5;
		ui3->y = 0;

		ui3->z = 0.2;
		ui3->draw();
	}

	glFlush();
}
bool IsAnimating = false;
int n = 0;
GameObject* getObject(std::string tag) {

	for (int i = 0; i < objectsInScene.size(); i++) {

		if (objectsInScene.at(i)->tag == tag) {
			return objectsInScene.at(i);
		}
	}
	return NULL;
}



double rotate = 0;
void myMouse( int x, int y)
{
	//std::cout << "rotate" << x <<" "<<y<< std::endl;
	rotate = -(double)x/1.5;
	//std::cout << "rotate" <<rotate<< std::endl;
}
void Keyboard(unsigned char key, int x, int y) {
	float d = 0.01;

	switch (key) {
	case 'w':
		camera.pres = 0;
		break;




		case 'q':
			camera.pres = 1;
		break;


	case GLUT_KEY_ESCAPE:
		exit(EXIT_SUCCESS);
	}

	glutPostRedisplay();
}

void Special(int key, int x, int y) {
	float a = 1.0;

	switch (key) {
	case GLUT_KEY_UP:
		dy = 0.01;
		moveIt = true;
		break;
	case GLUT_KEY_DOWN:
		dy = -0.01;
		moveIt = true;
		break;
	case GLUT_KEY_LEFT:
		dx = -0.01;
		moveIt = true;
		break;
	case GLUT_KEY_RIGHT:
		moveIt = true;
		dx = 0.01;
		break;
	}


}

int timeSinceStart = 0;
int timeToChangeColor = 0;
 bool gameOver = false;
 int winLose = 0;
 int score = 0;

void timedEvents() {
	timeSinceStart += 10;
	if (timeSinceStart - 30000 > 0) {
		gameOver = true;
	}

	if (score == 5) {
		gameOver = true;
		winLose = 1;
	}



	if (timeSinceStart - timeToChangeColor>150) {

		if (color >= 1) {
			inc = false;
		}
		if (color <= 0) {
			inc = true;
		}
		timeToChangeColor = timeSinceStart;


		if (inc) {
			color = color + 0.01;
			glClearColor(0, 0, 0, 0.0);
		}
		else {
			color = color - 0.01;
			glClearColor(1, 1, 1, 0.0);
		}
		//changeColor(red/10, green/10, blue/10);

	}

}
void physicsEngine(int x) {
	if (gameOver) {
		if (level==0&&winLose==1) {

			objectsInScene.clear();
			gameOver = false;
			timeSinceStart = 0;
			timeToChangeColor = 0;
			score = 0;
			level = 1;
			winLose = 0;
			//UI* lose = new UI(0, 240, 0, 250, "please wait for level 2 to load");
			//lose->playSound();
			//objectsInScene.push_back(lose);
			//camera.lookAtUI();


			//glutPostRedisplay();
			createLevel2();

		}
		else {
			if (level == 1 && winLose == 1) {

				objectsInScene.clear();
				std::string s = "you won, and your score is: " +std::to_string(score);
				UI* lose = new UI(0, 240, 0, 250, s);
				//lose->playSound();
				camera.lookAtUI();

				objectsInScene.push_back(lose);
				//glutPostRedisplay();
				//createLevel2();

			}
			else {

				std::string s = "you lost because time ran out, your score is: " +std::to_string(score);
				std::cout << s<< std::endl;
				objectsInScene.clear();
				UI* lose = new UI(0, 240, 0, 250,s );


				//lose->playSound();
				camera.lookAtUI();
				objectsInScene.push_back(lose);
			}
			//gameOver = false;
		}

		glutPostRedisplay();
		glutTimerFunc(10, physicsEngine, 0);

	}
	else {

		if (moveIt) {
			collisionEngine();
			moveIt = false;
			dx = 0;
			dy = 0;
		}
		timedEvents();
		glutPostRedisplay();

		glutTimerFunc(10, physicsEngine, 0);

	}

}
void main(int argc, char** argv) {
	glutInit(&argc, argv);

	glutInitWindowSize(1200, 780);
	glutInitWindowPosition(50, 50);

	glutCreateWindow("Best Game Ever");
	srand((unsigned)time(NULL));
	init();
	glutDisplayFunc(Display);
	//glutMouseFunc(myMouse);
	glutPassiveMotionFunc(myMouse);
	glutKeyboardFunc(Keyboard);
	glutSpecialFunc(Special);
	glutTimerFunc(1, physicsEngine, 0);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glClearColor(.0, .0, .0, 0.0);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHT3);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	glShadeModel(GL_SMOOTH);


	glutMainLoop();
}
