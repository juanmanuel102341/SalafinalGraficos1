#ifndef BRICKS_H
#define BRICKS_H
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<vector>
#include"Scene.h"

class Bricks
{
	struct Brick
	{
		sf::Sprite sprite;
		sf::Texture texture;
		sf::Vector2f position;
	};
public:
	const int numberOfBricks=6;
	const int numberOfLines = 6;
	Bricks(sf::RenderWindow* window, DimensionsScene _dimensionsScene);
	~Bricks();
	void draw();
	std::vector<Brick*>Vecbricks;
	
private:
	void init();
	sf::RenderWindow* window;
	DimensionsScene dimensions;
	sf::Texture textureBlue;
	sf::Texture textureRed;
	sf::Texture textureBrown;
	sf::Texture textureGreen;
	sf::Texture returnTexture(int id);
	sf::Texture currentTexture;
};

#endif // !BRICKS_H
