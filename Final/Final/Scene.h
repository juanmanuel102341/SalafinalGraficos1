#ifndef SCENE_H
#define SCENE_H
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>
#include"Reg.h"
using namespace std;
struct DimensionsScene {
	float width, height,half;
	sf::Vector2f origin;
};

class Scene
{
public:
	Scene(sf::RenderWindow* window);
	~Scene();
	void draw();
	void init();
	sf::Sprite sprite;
	sf::Texture texture;
	sf::RenderWindow* window;
	sf::RectangleShape colliderUp;
	sf::RectangleShape colliderleft;
	sf::RectangleShape colliderRight;
	DimensionsScene dimensions;
private:

};
#endif // !SCENE_H

