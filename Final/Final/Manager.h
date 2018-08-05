#ifndef MANAGER_H
#define MANAGER_H
#include"Player.h"
#include"Bricks.h"
#include"Scene.h"
class Manager
{
public:
	Manager(Player* player, Bricks* bricks, Scene* scene);
	~Manager();
	void update(sf::Time deltaTime);
private:
	Player* player;
	Bricks* bricks;
	Scene* scene;

};

#endif // !MANAGER_H
