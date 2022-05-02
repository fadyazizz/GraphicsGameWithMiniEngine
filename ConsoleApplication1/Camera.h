#pragma once
#include "Vector3f.h"
#include "Engine.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#define DEG2RAD(a) (a * 0.0174532925)
class Camera {
public:
	Vector3f eye, center, up;
	int pres = 1;
	Camera(float eyeX = 0.0f, float eyeY = 0.0f, float eyeZ = 1.0f, float centerX = 0.0f, float centerY = 0.0f, float centerZ = 0.0f, float upX = 0.0f, float upY = 1.0f, float upZ = 0.0f) {
		eye = Vector3f(eyeX, eyeY, eyeZ);
		center = Vector3f(centerX, centerY, centerZ);
		up = Vector3f(upX, upY, upZ);
	}
	//e
	void moveX(float d) {

		eye = Vector3f(0.0, -0.5, 0.5);
		up = Vector3f(0, 1, 0);
		center = Vector3f(0.0, -0.5, 0);

	}
	//w
	void moveY(float d) {
		eye = Vector3f(2, 0, 0.5);
		up = Vector3f(0, 0, 1);
		//center = Vector3f(0.0, -0.6, 0);
		//	center = Vector3f(0.0, -0.0, 0.0);
			//center = center + up.unit() * d;
	}
	//q
	void moveZ(float d) {

	}
	void lookAtTree() {
		eye = Vector3f(0.3, -0.1, 0.1);
		up = Vector3f(0, 0, 1);
		center = Vector3f(0.3, 0.0, 0.1);

	}
	void lookAtTree2() {
		eye = Vector3f(-0.2, -0.1, 0.1);
		up = Vector3f(0, 0, 1);
		center = Vector3f(-0.2, 0.0, 0.1);

	}
	void lookAtUmbrella() {
		eye = Vector3f(0.1, -0.1, 0.1);
		up = Vector3f(0, 0, 1);
		center = Vector3f(0.1, 0.0, 0.1);
	}
	void lookAtPool() {
		eye = Vector3f(0.2, -0.3, 0.5);
		up = Vector3f(0, 1, 0);
		center = Vector3f(0.2, -0.3, 0);
	}
	void lookAtFence() {
		eye = Vector3f(0.0, 0, 1);
		up = Vector3f(0, 1, 0);
		center = Vector3f(0, 0, 0);
	}
	void lookAtBench() {
		eye = Vector3f(0.1, -0.1, 0.1);
		up = Vector3f(0, 0, 1);
		center = Vector3f(0.1, 0.0, 0.1);
	}
	void lookAtGrass() {
		eye = Vector3f(0.0, 0, 0.65);
		up = Vector3f(0, 1, 0);
		center = Vector3f(0, 0, 0);
	}
	void lookAtUI() {
		eye = Vector3f(0.0, 0.5, 0);
		up = Vector3f(0, 1, 0);
		center = Vector3f(0.0, 0.0, 0);
		gluLookAt(
			eye.x, eye.y, eye.z,
			center.x, center.y, center.z,
			up.x, up.y, up.z
		);
	}


	void rotateX(float a) {
		Vector3f view = (center - eye).unit();
		Vector3f right = up.cross(view).unit();
		view = view * cos(DEG2RAD(a));
		up = up * sin(DEG2RAD(a));
		view = view + up;
		up = view.cross(right);
		center = eye + view;
	}

	void rotateY(float a) {
		Vector3f view = (center - eye).unit();
		Vector3f right = up.cross(view).unit();
		view = view * cos(DEG2RAD(a));
		right = right * sin(DEG2RAD(a));
		view =  view+right;
		right = view.cross(up);
		center = eye + view;
	}

	void look() {
		if (pres == 0) {
			glm::mat4 trans = glm::mat4(1.0f);
			trans = glm::rotate(trans, glm::radians((float)rotate), glm::vec3(0.0f, 0.0f, 1.0f));
			glm::vec4 result = trans * glm::vec4(player->translateX, player->translateY, 0.0f, 1.0f);
			eye = Vector3f(player->translateX, player->translateY, 0.19);
			up = Vector3f(0, 0, 1);
			center = Vector3f(player->translateX, player->translateY + 1, 0.15);
			//glPushMatrix();
			//glRotated(rotate, 0, 0, 1);
			rotateY(rotate);
			gluLookAt(
				eye.x, eye.y, eye.z,
				center.x, center.y, center.z,
				up.x, up.y, up.z
			);
		}
		else {

			eye = Vector3f(player->translateX, player->translateY - 1, 1.5);
			up = Vector3f(0, 0, 1);
			center = Vector3f(0, 0, -0.2);
			//glPushMatrix();
			//glRotated(rotate, 0, 0, 1);
			//rotateY(rotate);
			gluLookAt(
				eye.x, eye.y, eye.z,
				center.x, center.y, center.z,
				up.x, up.y, up.z
			);
		}
		//	glPopMatrix();
	}
};