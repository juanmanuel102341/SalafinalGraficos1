#ifndef BALL_H
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>
#include"Scene.h"
#include"Player.h"
using namespace std;

class Ball
{
public:
	Ball(sf::RenderWindow* window, DimensionsScene _dimensionsScene,Player* player);
	~Ball();
	void draw();
	void update(sf::Time deltaTime);
	void move(sf::Time deltaTime);
private:
	void init();
	DimensionsScene dimensionsScene;
	sf::RenderWindow* window;
	sf::Texture texture;
	sf::Sprite sprite;
	Player* player;
	bool active;
	float velocity;
};

#endif // !BALL_H
