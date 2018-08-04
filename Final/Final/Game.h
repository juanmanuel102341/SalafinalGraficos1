#ifndef GAME_H
#define GAME_H
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include"Player.h"
#include"Reg.h"
#include"Scene.h"
#include"Ball.h"
#include"Collision.h"
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
	
};

#endif // !GAME_H

