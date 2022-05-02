#pragma once
#include <windows.h>
#include "Player.h"
#include "Engine.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Elf.h"
#include "Child.h"

double newTranslateX = 0;
double newTranslateY = 0;
double newTranslateZ = 0;

Player::Player(double translateX, double translateY, double translateZ, double scaleX, double scaleY, double scaleZ) {
	setUp(translateX, translateY, translateZ, scaleX, scaleY, scaleZ);
	this->tag = "player";
	char file[] = "Models/santa/santa.3ds";
	santa.Load(file);
	santa.lit = false;
	std::cout << santa.scale << std::endl;
	santa.scale = 0.001;
	this->canCollide = true;

}



void Player::draw() {

	glPushMatrix();


	glTranslatef(translateX, translateY, translateZ);

	glRotated(rotate, 0, 0, 1);



	glRotated(90, 1, 0, 0);
	glRotated(180 , 0, 1, 0);



	//glScalef(scaleX, scaleY,scaleZ);
	santa.Draw();

	glPopMatrix();

	//this->debug();


}
void Player::handleTriggerEvent(GameObject* g, int index) {
	if (g->tag == "elf") {
		Elf* e = (Elf*)g;
		if (e->hasGift) {
			e->hasGift = false;
			//LPCWSTR sound = L"EnemyExplosion.wav";
			score++;
			PlaySound("hohoho.wav", NULL, SND_ASYNC | SND_FILENAME);
		}

		}
	else {
		if (g->tag == "child") {
			Child* c = (Child*)g;
			if (!c->hasGift) {
				c->hasGift = true;
				//LPCWSTR sound = L"EnemyExplosion.wav";
				score++;
				PlaySound("hohoho.wav", NULL, SND_ASYNC | SND_FILENAME);
			}

		}

		else {
			std::cout << "soundplayer" << std::endl;
			LPCWSTR sound = L"EnemyExplosion.wav";
			PlaySound("EnemyExplosion.wav", NULL, SND_ASYNC | SND_FILENAME);
		}
	}
}
void Player::move(double dx,double dy) {
	glm::mat4 trans = glm::mat4(1.0f);
	trans = glm::rotate(trans, glm::radians((float)rotate), glm::vec3(0.0f, 0.0f, 1.0f));

	glm::vec4 result = trans * glm::vec4(dx, dy, 0.0f, 1.0f);
	glm::vec4 result2 = trans * glm::vec4(this->translateX+dx, this->translateY+dy, 0.0f, 1.0f);

	this->translateX =  this->translateX+result.x;
	this->translateY =  this->translateY+result.y;

	this->setUpCollider(this->minX + result.x, this->maxX + result.x, this->minY + result.y, this->maxY+result.y, this->minZ, this->maxZ);


}
