#ifndef MANAGER_H
#define MANAGER_H
#include"Player.h"
#include"Bricks.h"
#include"Scene.h"
#include"Menu.h"
#include"Ball.h"
class Manager
{
public:
	Manager(Player* player, Bricks* bricks, Scene* scene, sf::RenderWindow* _window,Menu* menu,Ball* _ball);
	~Manager();
	void update(sf::Time deltaTime);
	void draw();
private:
	void resetlevel();
	void init();
	Player* player;
	Bricks* bricks;
	Scene* scene;
	

	sf::Texture textureWin;
	sf::Texture textureLoose;
	sf::Sprite spriteLoose;
	sf::Sprite spriteWin;
	sf::RenderWindow* window;
	Menu* menu;
	Ball* ball;
	bool clean;
};

#endif // !MANAGER_H
