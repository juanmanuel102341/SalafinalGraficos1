#ifndef COLLISION_H
#define COLLISION_H
#include"Ball.h"
#include"Scene.h"
#include"Player.h"

#include<iostream>
using namespace std;
class Collision
{
public:
	Collision(Ball* ball,Scene* scene,Player* player);
	void collideBallBoundarys();
	void collideBallPlayer();
	~Collision();

private:
	Ball* ball;
	Scene* scene;
	Player* player;
};

#endif // !COLLISION_H
