#ifndef FINAL_GUI_STATES_H
#define FINAL_GUI_STATES_H
#include<iostream>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include"Buttons.h"
using namespace std;

class FinalGuiStates
{
public:
	FinalGuiStates(sf::RenderWindow* window);
	~FinalGuiStates();
	void draw();
	void update(sf::Time delta);
	void setDimensions(sf::Vector2f _dimensions, float width, float height);
	bool win;

private:
	void init();
	sf::Texture textureWin;
	sf::Sprite spriteWin;
	sf::Texture textureLoose;
	sf::Sprite spriteLoose;
	sf::RenderWindow* window;
	sf::Vector2f dimensions;
	float widhtScene;
	float heightScene;
	Buttons* buttons;
	bool applyFinal;
};

#endif // !FINAL_GUI_STATES_H
