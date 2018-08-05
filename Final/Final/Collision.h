#ifndef COLLISION_H
#define COLLISION_H
#include"Ball.h"
#include"Scene.h"
#include"Player.h"
#include"Bricks.h"
#include<iostream>
using namespace std;
class Collision
{
public:
	Collision(Ball* ball, Scene* scene, Player* player, Bricks* bricks);
	void collideBallBoundarys();
	void collideBallPlayer();
	void collideBallBricks();
	~Collision();

private:
	Ball* ball;
	Scene* scene;
	Player* player;
	Bricks*bricks;
};

#endif // !COLLISION_H
