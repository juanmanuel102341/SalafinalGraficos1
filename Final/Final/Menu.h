#ifndef MENU_H
#define MENU_H
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>
#include<vector>
#include<SFML/Window/Mouse.hpp>
#include"Buttons.h"
using namespace std;

class Menu
{
public:
	
	Menu(sf::RenderWindow* _window, Buttons* _buttons);
	~Menu();
	void draw();
	void update(sf::Time deltaTime);
	bool mousseDown;
	bool startGame ;

private:
	void init();

	
	
	sf::RenderWindow* window;
	sf::Texture textureBackMenu;
	Buttons* buttons;
	sf::Texture textureCredits;
	sf::Sprite backMenu;
	sf::Sprite spriteCredits;
	
	
	

	
};

#endif // !MENU_H

