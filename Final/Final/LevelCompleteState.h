#ifndef LEVEL_COMPLETE_STATE_H
#define LEVEL_COMPLETE_STATE_H
#include<iostream>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
using namespace std;


class LevelCompleteState
{
public:
	LevelCompleteState(sf::RenderWindow* _window);
	~LevelCompleteState();
	void draw();
	void update(sf::Time delta);
	void setDimensions(sf::Vector2f _dimensions, float width, float height);
private:
	void init();
	sf::Texture texture;
	sf::Sprite sprite;
	sf::RenderWindow* window;
	sf::Vector2f dimensions;
	float widhtScene;
	float heightScene;
};
#endif // !LEVEL_COMPLETE_STATE_H

