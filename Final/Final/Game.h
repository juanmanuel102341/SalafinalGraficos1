#ifndef GAME_H
#define GAME_H
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include"Player.h"
#include"Reg.h"
#include"Scene.h"
#include"Ball.h"
#include"Collision.h"
#include"Bricks.h"
#include"Manager.h"
#include"Buttons.h"
#include"Menu.h"

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	void update(sf::Time deltaTime);
	void processEvents();
	void render();
	
	sf::RenderWindow window;
	Player* player;
	Scene* scene;
	Ball* ball;
	Collision* collision;
	Bricks* bricks;
	Manager* manager;
	Menu* menu;
	Buttons* buttons;
	sf::Music musicLevel;

};

#endif // !GAME_H

