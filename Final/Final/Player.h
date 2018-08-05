#ifndef PLAYER_H
#define PLAYER_H
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include"Reg.h"
#include<iostream>
#include"Scene.h"
using namespace std;

class Player
{
public:
	Player(sf::RenderWindow* window,DimensionsScene _dimensionsScene);

	~Player();
	void draw();
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
	void move(sf::Time deltaTime);
	sf::Sprite sprite;
	bool activeShoot;
	sf::Sound soundColision;
private:
	void initialize();
	float velocity;
	sf::Texture texture;
	sf::RenderWindow* window;
	sf::SoundBuffer soundBuffer;
	
	bool left;
	bool right;
	DimensionsScene dimensionsScene;
	
};

#endif // !PLAYER_H
