#ifndef PLAYER_H
#define PLAYER_H
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include"Reg.h"
#include<iostream>
using namespace std;
class Player
{
public:
	Player(sf::RenderWindow* window);

	~Player();
	void draw();
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
	void move(sf::Time deltaTime);
private:
	void initialize();
	float velocity;
	sf::Sprite sprite;
	sf::Texture texture;
	sf::RenderWindow* window;
	bool left;
	bool right;
};

#endif // !PLAYER_H
