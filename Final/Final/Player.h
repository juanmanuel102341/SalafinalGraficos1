#ifndef PLAYER_H
#define PLAYER_H
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include"Reg.h"
#include<iostream>
#include"Scene.h"
#include<vector>

using namespace std;

class Player
{
	
public:
	Player(sf::RenderWindow* window,Scene* scene);

	~Player();
	void draw();
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
	void move(sf::Time deltaTime);
	void animationDead(sf::Time deltaTime);
	void update(sf::Time deltaTime);
	void resetState();
	sf::Sprite sprite;
	bool activeShoot;
	bool dead;
	bool activeAnimation;
	bool respawnBall;
	sf::Sound soundColision;
	sf::Sound soundLoose;
	sf::Sound soundRespawn;
	const int totalLifes;
	bool reset;
	int currentLifes;
private:
	void initialize();
	void initTextureAnimation();
	float velocity;
	
	
	sf::Texture texture;
	sf::RenderWindow* window;
	sf::SoundBuffer soundBuffer;
	sf::SoundBuffer soundBufferEfectLoose;
	sf::SoundBuffer soundBufferEfectRespawn;
	std::vector<sf::Texture>vecTextureAnimation;
	float timer;
	bool left;
	bool right;
	int contador;
	Scene* scene;
	
};

#endif // !PLAYER_H
