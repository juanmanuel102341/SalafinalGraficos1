#ifndef MENU_H
#define MENU_H
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>
#include<vector>
#include<SFML/Window/Mouse.hpp>
using namespace std;

class Menu
{
public:
	enum currentState {
		start,credits,exit,menu
	};
	Menu(sf::RenderWindow* _window);
	~Menu();
	void draw();
	void update(sf::Time deltaTime);
	bool mousseDown;
	bool startGame ;
private:
	void init();
	void setTexturesButtons();
	bool collideEnter(sf::Sprite sprite);
	void detectStates(sf::Sprite& sprite, sf::Texture& textOver, sf::Texture& textPress, sf::Texture& textOut, bool& apply, currentState& state, sf::Time delta,currentState objState);
	sf::RenderWindow* window;
	sf::Texture textureBackMenu;
	std::vector<sf::Texture>vecTexturePlay;
	std::vector<sf::Texture>vecTextureCredits;
	std::vector<sf::Texture>vecTextureExit;
	std::vector<sf::Texture>vecTextureMenu;
	sf::Texture currentTexturePlay;
	sf::Texture currentTextureCredits;
	sf::Texture currentTextureExit;
	sf::Texture currentTextureMenu;

	sf::Texture textureCredits;
	sf::Sprite backMenu;
	sf::Sprite buttonPlay;
	sf::Sprite buttonCredits;
	sf::Sprite buttonExit;
	sf::Sprite buttonMenu;
	
	bool applyTexture;
	bool apply2;
	bool apply3;
	bool apply4;
	bool press;
	currentState state;
	float timer;
	bool startState;
	bool goCredits;
};

#endif // !MENU_H

