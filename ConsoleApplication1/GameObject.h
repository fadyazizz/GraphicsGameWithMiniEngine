#pragma once
#pragma once
#include <vector>
#include<iostream>

using std::vector;
class GameObject {
public:
	bool isTrigger = false;
	bool hasSound;
	bool canMove;
	bool canCollide=false;
	std::string tag;
	void setUpCollider(double minX, double maxX, double minY, double maxY, double minZ, double maxZ);
	void setUpScale(double scaleX, double scaleY, double scaleZ);
	virtual void draw() {}
	virtual void animate(){}
	virtual void move(double dx, double dy) {}
	virtual void handleTriggerEvent(GameObject* obj, int indexInScene) {}
	virtual void playSound() {}

	void setUp(double translateX, double translateY, double translateZ, double scaleX, double scaleY, double scaleZ);
	void debug();



	//collider array should be in the format @0 (min x, max x), @1(min y, max y)
	double minX;
	double maxX;
	double minY;
	double maxY;
	double minZ;
	double maxZ;
	double scaleX;
	double scaleY;
	double scaleZ;
	double translateX;
	double translateY;
	double translateZ;
	vector<int> collider[2];
	///*GameObject*/(int number);


};
